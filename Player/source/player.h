/***************************************************************************/ /**
   @file     +Nombre del archivo (ej: template.h)+
   @brief    +Descripcion del archivo+
   @author   +Nombre del autor (ej: Salvador Allende)+
  ******************************************************************************/

#ifndef _PLAYER_H_
#define _PLAYER_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "songList.h"
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define BUFFER_SIZE 2000
/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef enum _Player_MSG
{
  Playing,
  Paused,
  Stoped
} player_msg_t;

typedef struct _Player
{
  song_node_t *currSong;
  float volume;

} player_t;

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: extern unsigned int anio_actual;+

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

bool play();
bool stop();
bool pause();
bool nextSong();
bool prevSong();
bool adjustVolume(float vol);

song_node_t *getSongList();
bool selectSong(song_node_t *song);

void getSongInfo(song_node_t *node);

player_msg_t updatePlayer();

bool playerInit();

/*******************************************************************************
 ******************************************************************************/

#endif // _QUEUE_H_
