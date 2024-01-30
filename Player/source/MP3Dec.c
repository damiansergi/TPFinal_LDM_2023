/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.c)+
   @brief    +Descripcion del archivo+
   @author   +Nombre del autor (ej: Salvador Allende)+
  ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "MP3Dec.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "sdmmc_config.h"
#include "fsl_sysmpu.h"
#include "MK64F12.h"
#include "mp3dec.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define TAG_SIZE 128

typedef struct
{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    unsigned char genre;
} ID3Tag;
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
/*
Function for reading all the mp3 files in the SD card in all folders and adding them to the song list
*/
/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static HMP3Decoder mp3Dec;

static FIL mp3File;

static MP3FrameInfo mp3Info;

static bool fileOpen = false;

static FRESULT error;
static DIR directory; /* Directory object */
static FILINFO fileInformation;
static UINT bytesWritten;
static UINT bytesRead;
static const TCHAR driverNumberBuffer[3U] = {SDDISK + '0', ':', '/'};
static BYTE work[FF_MAX_SS];
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

bool MP3DecInit()
{
    mp3Dec = MP3InitDecoder();

    return mp3Dec == NULL;
}

int MP3SelectSong(song_t *song)
{
    static volatile char mp3path[256] = {0};
    static volatile BYTE readBuff[MAINBUF_SIZE]; // Buffer to store file content
    UINT br;
    int err = 1, offset;

    if (fileOpen)
    {
        f_close(&mp3File);
        fileOpen = false;
    }

    // merge path with filename to get full file directory
    strcpy(mp3path, song->path);
    strcat(mp3path, "/");
    strcat(mp3path, song->filename);

    error = f_open(&mp3File, mp3path, FA_READ);
    fileOpen = error == FR_OK;
    if (!fileOpen)
    {
        return 1;
    }

    while (!f_eof(&mp3File) && err)
    { // Read until Frame valid or EOF
        if (f_read(&mp3File, readBuff, MAINBUF_SIZE, &br) == FR_OK)
        { // Save file content in readBuff

            offset = MP3FindSyncWord(readBuff, br);
            if (offset < 0)
            {
                continue; // Skip block
            }

            err = MP3GetNextFrameInfo(mp3Dec, &mp3Info, readBuff + offset);
            if (err)
            {
                f_lseek(&mp3File, f_tell(&mp3File) - br + offset + 1); // Move file pointer next to last frame sync found
            }
        }
        else
        { // Error reading file
            break;
        }
    }

    if (!err)
    {
        if (f_lseek(&mp3File, f_tell(&mp3File) - br + offset) == FR_OK)
        { // File pointer to Start Of Frame

            return 0;
        }
    }

    f_close(&mp3File);
    fileOpen = false;
}

uint32_t MP3DecDecode(uint16_t *buffer)
{
    static volatile BYTE readBuff[MAINBUF_SIZE];                 // Buffer to store file content
    static volatile uint16_t stereoOutBuff[DEC_BUFFER_SIZE * 2]; // Buffer to store stereo samples
    UINT br;
    int offset;
    int err = 1;
    bool needSync = true;
    BYTE bytesLeft = 0;

    if (fileOpen)
    {
        while (!f_eof(&mp3File))
        {
            if (f_read(&mp3File, readBuff, MAINBUF_SIZE, &br) == FR_OK)
            { // Save file content in readBuff

                // Sync to Header

                bytesLeft = br;
                if (needSync)
                {
                    offset = MP3FindSyncWord(readBuff, br);
                    if (offset < 0)
                    {
                        continue; // Skip block
                    }
                    needSync = false;
                    bytesLeft -= offset;
                }
                else
                {
                    offset = 0;
                }

                // Decode
                err = MP3GetNextFrameInfo(mp3Dec, &mp3Info, readBuff + offset);

                if (!err)
                {
                    if (mp3Info.nChans == 1) // File is mono
                    {
                        err = MP3Decode(mp3Dec, readBuff + offset, &br, buffer, 0);
                        bytesLeft -= br;

                        if (!err)
                        {
                            f_lseek(&mp3File, f_tell(&mp3File) - bytesLeft);

                            return mp3Info.outputSamps;
                        }
                    }
                    else if (mp3Info.nChans == 2) // File is stereo
                    {
                        err = MP3Decode(mp3Dec, readBuff + offset, &br, stereoOutBuff, 0);
                        bytesLeft -= br;

                        if (!err)
                        {
                            for (int i = 0; i < DEC_BUFFER_SIZE; i++)
                            {
                                buffer[i] = ((uint32_t)stereoOutBuff[i * 2] + (uint32_t)stereoOutBuff[i * 2 + 1]) / 2;
                            }

                            f_lseek(&mp3File, f_tell(&mp3File) - bytesLeft);

                            return mp3Info.outputSamps / 2;
                        }
                    }
                }

                switch (err)
                {
                case ERR_MP3_INDATA_UNDERFLOW:
                    break;
                case ERR_MP3_MAINDATA_UNDERFLOW:

                    if (!f_eof(&mp3File))
                    { // Move file pointer to start of last frame
                        f_lseek(&mp3File, f_tell(&mp3File) - br + offset);
                    }
                    break;
                case ERR_MP3_FREE_BITRATE_SYNC:
                    break;
                case ERR_MP3_OUT_OF_MEMORY:
                    break;
                case ERR_MP3_NULL_POINTER:
                    break;
                case ERR_MP3_INVALID_FRAMEHEADER:
                    break;
                case ERR_MP3_INVALID_SIDEINFO:
                    break;
                case ERR_MP3_INVALID_SCALEFACT:
                    break;
                case ERR_MP3_INVALID_HUFFCODES:
                    // Move file pointer next to start of last frame and resync
                    needSync = true;
                    f_lseek(&mp3File, f_tell(&mp3File) - br + offset + 1);
                    break;
                case ERR_MP3_INVALID_DEQUANTIZE:
                    break;
                case ERR_MP3_INVALID_IMDCT:
                    break;
                case ERR_MP3_INVALID_SUBBAND:
                    break;
                default:
                    // Move file pointer next to start of last frame and resync
                    needSync = true;
                    f_lseek(&mp3File, f_tell(&mp3File) - br + offset + 1);
                    break;
                }
            }
        }
    }
    else
    {
        return 0;
    }

    return 0;
}
/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
