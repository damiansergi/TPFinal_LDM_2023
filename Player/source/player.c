/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.c)+
   @brief    +Descripcion del archivo+
   @author   +Nombre del autor (ej: Salvador Allende)+
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "player.h"
#include "fsl_dac.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "sdmmc_config.h"
#include "fsl_sysmpu.h"
#include "MK64F12.h"
#include "MP3Dec.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef enum _SDStates
{
    SDCard_ready,
    no_SDCard
} SDStates_t;

typedef enum _PlayerStates
{
    STARTING,
    SD_DETECTED,
    READING_SD,
    DECODING,
    WAITING_TO_DECODE,
    FILTERING,
    WAITING_FOR_SONG,
    STOPPED,
    PAUSED,

} PlayerStates_t;
/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
/*
Function for reading all the mp3 files in the SD card in all folders and adding them to the song list
*/
static void readMP3Files();

void doNothing(void);
/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static dac_config_t dac_conf = {kDAC_ReferenceVoltageSourceVref2, false};

static FATFS g_fileSystem; /* File system object */

static PlayerStates_t state = STARTING;
static FRESULT error;

static song_node_t *currentSong = NULL;

static const TCHAR driverNumberBuffer[3U] = {SDDISK + '0', ':', '/'};
volatile bool failedFlag = false;
volatile bool playingMusic = false;

char ch = '0';
BYTE work[FF_MAX_SS];
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

bool playerInit()
{
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    SYSMPU_Enable(SYSMPU, false);
    initList();
    MP3DecInit();

    // DAC Configuration
    DAC_Init(DAC0, &dac_conf);
    DAC_Enable(DAC0, true);
    DAC_EnableBuffer(DAC0, false);

    return true;
}

bool play();
bool stop();
bool pause();
bool nextSong();
bool prevSong();
bool adjustVolume(float vol);

song_node_t *getSongList()
{
    return getListHead();
}

bool selectSong(song_node_t *song)
{
    if (!playingMusic)
    {
        currentSong = song;
        return false;
    }
    else
    {
        stop();
        currentSong = song;
        play();
    }

    return true;
}

void getSongInfo(song_node_t *node);

player_msg_t updatePlayer()
{
    switch (state)
    {
    case STARTING:
        BOARD_SD_Config(&g_sd, NULL, BOARD_SDMMC_SD_HOST_IRQ_PRIORITY, NULL);

        /* SD host init function */
        if (SD_HostInit(&g_sd) != kStatus_Success)
        {
            printf("\r\nSD host init fail\r\n");
            break;
        }

        /* wait card insert */
        if (SD_IsCardPresent(&g_sd) == true)
        {
            printf("\r\nCard inserted.\r\n");
            /* power off card */
            SD_SetCardPower(&g_sd, false);
            /* power on the card */
            SD_SetCardPower(&g_sd, true);

            state = SD_DETECTED;
        }
        else
        {
            printf("\r\nCard detect fail.\r\n");
            break;
        }
        break;

    case SD_DETECTED:
        if (f_mount(&g_fileSystem, driverNumberBuffer, 0U))
        {
            printf("Mount volume failed.\r\n");
            break;
        }

        error = f_chdrive((char const *)&driverNumberBuffer[0U]);
        if (error)
        {
            printf("Change drive failed.\r\n");
            break;
        }

        state = READING_SD;
        break;

    case READING_SD:
        // Read MP· files on SD
        readMP3Files("");
        selectSong(getListHead()->next);
        MP3SelectSong(currentSong);
        state = STOPPED;
        break;

    case DECODING:
        // Decode the first song using helix mp3 decoder and play it
        MP3DecDecode();
        break;

    case WAITING_TO_DECODE:
        break;

    case FILTERING:
        break;

    case STOPPED:
        doNothing();
        break;

    case PAUSED:
        doNothing();
        break;

    default:
        break;
    }
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void doNothing(void)
{
    return;
}

static void readMP3Files(const char *path)
{
    static volatile char currentPath[256];
    static DIR directory;
    static FILINFO fileInfo;

    FRESULT result = f_opendir(&directory, path); // Open the directory
    if (result != FR_OK)
    {
        printf("Error opening directory: %d\n", result);
        return;
    }

    while (1)
    {
        result = f_readdir(&directory, &fileInfo); // Read directory entries
        if (result != FR_OK || fileInfo.fname[0] == 0)
        {
            break; // Break on error or end of directory
        }

        if (fileInfo.fattrib & AM_DIR)
        {
            // If it's a directory, skip "." and ".."
            if (strcmp(fileInfo.fname, ".") == 0 || strcmp(fileInfo.fname, "..") == 0)
            {
                continue;
            }

            // Skip directories starting with a dot
            if (fileInfo.fname[0] == '.')
            {
                continue;
            }
            sprintf(currentPath, "%s/%s", path, fileInfo.fname);
            readMP3Files(currentPath);
        }
        else
        {
            // If it's a file, check for ".mp3" extension
            if (strstr(fileInfo.fname, ".mp3") != NULL)
            {
                printf("MP3 File: %s/%s\n", path, fileInfo.fname);
                // Add the file to the list
                pushtoBack(newSong(path, fileInfo.fname));
            }
        }
    }

    f_closedir(&directory); // Close the directory
}
