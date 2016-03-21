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
 
 
#include "questionhandler.h"
 
#include <xercesc/sax2/Attributes.hpp>
#include <iostream>
#include <string>
#include <sstream>                      // For a conversion string->int
 
 
using namespace std;
 
/// Callback, which is called at the beginning of the document
void QuestionHandler::startDocument()
{
 
}
 
 
/// Callback, which is called at the end of the document
void QuestionHandler::endDocument()
{
 
}
 
 
/// Callback, which is called at the start of an element
/**
 * @param qname The name of the tag, which started
 */
void QuestionHandler::startElement(
                  const XMLCh* const uri,
                  const XMLCh* const localname,
                  const XMLCh* const qname,
                  const Attributes& attr)
{
  _tag = XMLString::transcode(qname);   // transcode converts an XMLCh* to a string
}
 
 
/// Callback, which is called at the end of an element
/**
 * @param qname The name of the tag, which ended
 */
void QuestionHandler::endElement(
                  const XMLCh* const uri,
                  const XMLCh* const localname,
                  const XMLCh* const qname)
{
  _tag = XMLString::transcode(qname);
 
  if(_tag=="question")                  // A question ended
  {
    _current_answer = 0;                // All answer alternatives have been seen
    _questionvector[_level-MINLEVEL].push_back(_question); // Save the current question in the correct vector
 
  }
  else if(_tag=="answer")               // An answer alternative ended
  {
    ++_current_answer;                  // Which means the next is coming
  }
 
  _tag="";                              // Reset tagname
}
 
 
/// Callback, which is called in a CDATA field
/**
 * @param chars The content of the CDATA field
 * @param length The length of the CDATA field
 */
void QuestionHandler::characters(
                  const XMLCh* const chars,
                  const unsigned int length)
{
  string content(XMLString::transcode(chars));
 
  if(_tag=="level")                     // We are in the level field
  {
    istringstream in(content);
    in >> _level;                       // string to int
    if(_level>MAXLEVEL)                 // Set level to a valid value
    {
      _level=MAXLEVEL;
    }
    else if(_level<MINLEVEL)
    {
      _level=MINLEVEL;
    }
  }
  else if(_tag=="text")                 // We are in the question text field
  {
    _question.text = content;
  }
  else if(_tag=="answer")               // We are in an answer alternative field
  {
    _question.answer[_current_answer] = content;
  }
}
 
 
/// Copies the complete local vector-array to the remote one
/**
 * @param questionvector The remote Question vector array
 */
void QuestionHandler::getQuestions(vector<Question>* questionvector) const
{
  for(int i=0; i<=(MAXLEVEL-MINLEVEL); ++i)
  {
    questionvector[i] = _questionvector[i];
  }
}
