/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 3 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */
 
#include "sound.h"
#include <stdlib.h>
 
/// Plays the start sound of the game
void Sound::playStart()
{
  system("/usr/bin/aplay /opt/usr/share/sounds/drama.wav >/dev/null 2>&1 &");
}
 
/// Plays the end sound of the game
/**
 * @param sound Play a "game won" sound when true, otherwise a "game lost" sound
 */
void Sound::playEnd(bool sound)
{
  if(sound==true)
    {
      system("/usr/bin/aplay /opt/usr/share/sounds/kongas.wav >/dev/null 2>&1 &");
    }
    else
    {
      system("/usr/bin/aplay /opt/usr/share/sounds/beam.wav >/dev/null 2>&1 &");
    }
}
 
/// Plays an "answer given" soundfile
void Sound::playAnswer()
{
  system("/usr/bin/aplay /opt/usr/share/sounds/laser.wav >/dev/null 2>&1 &");
}
 
/// Plays a "question given" soundfile
void Sound::playQuestion()
{  
  system("/usr/bin/aplay /opt/usr/share/sounds/left.wav >/dev/null 2>&1 &");
}
