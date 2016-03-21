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
 
 
#ifndef _questionhandler_h_
#define _questionhandler_h_
 
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>
 
#include <vector>
 
#include "questiondb.h"
 
XERCES_CPP_NAMESPACE_USE
 
using namespace std;
 
 
/**
 * @class QuestionHandler
 * @brief A class for the callback functions of the XML parser
 * @author Markus Koch
 * @version 1.5
 * @date 2008-11-17
 * @bug None
 * @warning None
 * @todo Nothing
 */
class QuestionHandler : public DefaultHandler
{
  public:
    virtual void startDocument();
    virtual void endDocument();
 
    virtual void startElement(
      const XMLCh* const uri,
      const XMLCh* const localname,
      const XMLCh* const qname,
      const Attributes& attrs);
 
    virtual void endElement(
      const XMLCh* const uri,
      const XMLCh* const localname,
      const XMLCh* const qname);
 
    virtual void characters(
      const XMLCh* const chars,
      const unsigned int length);
 
    void getQuestions(vector<Question>*) const;
 
  private:
    /// Saves the tagname, we are current in
    string _tag;
 
    /// Saves the level of the question, which is currently parsed
    int _level;
 
    /// Saves the number of the answer alternative (0-3)
    unsigned int _current_answer;
 
    /// Saves the complete question, which is currently parsed
    Question _question;
 
    /// Vectorarray of the questions
    /** One array-element is a vector of questions from one level */
    vector<Question> _questionvector[(MAXLEVEL-MINLEVEL)+1];
 
};
 
#endif
