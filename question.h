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
 
 
#ifndef _question_h_
#define _question_h_
 
#include <string>
 
/**
 * @struct Question
 * @brief An object of this struct represents one Question
 * @author Markus Koch
 * @version 1.5
 * @date 2008-11-17
 * @bug None
 * @warning None
 * @todo Nothing
 */
struct Question
{
  std::string text;
  std::string answer[4];
};
 
#endif
