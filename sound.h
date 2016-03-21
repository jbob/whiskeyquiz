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
 
#ifndef _sound_h_
#define _sound_h_
 
#include <unistd.h>
#include <sys/types.h>
 
 
/**
 * @class Sound
 * @brief This class manages the sound effects of the game
 * @author Matthias Reitinger, Markus Koch
 * @version 0.5
 * @date 2008-12-02
 * @bug None
 * @warning None
 * @todo Implement the class with the system-calls fork() and execlp() instead of system()
 */
class Sound
{
  public:
    void playStart();
    void playEnd(bool);
    void playAnswer();
    void playQuestion();
};
 
#endif
