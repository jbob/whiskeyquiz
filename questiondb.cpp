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
 
 
#include "questiondb.h"
#include "questionhandler.h"            // Callback functions for parsing
 
#include <iostream>
 
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/ContentHandler.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>
 
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/LocalFileInputSource.hpp>
 
 
XERCES_CPP_NAMESPACE_USE
 
using namespace std;
 
/// The constructor
/**
 * @param filename The filename of the XML file with the questions
 */
QuestionDB::QuestionDB(const string& filename)
{
  _xmlFile = filename;                  // Set the filename
  _success=_parseFile();                // Start parsing the file
}
 
 
/// The destructor, does nothing
QuestionDB::~QuestionDB()
{
 
}
 
/// Returns one specific question
/**
 * @param level Describes the hardness of the question (MINLEVEL - MAXLEVEL)
 * @return A random struct Question object from the current level
 */
Question QuestionDB::getQuestion(int level) const
{
  if(level>MAXLEVEL)                    // Set level to a valid value
  {
    level=MAXLEVEL;
  }
  else if(level<MINLEVEL)
  {
    level=MINLEVEL;
  }
 
  level -= MINLEVEL;                    // Adjust level to array index 
 
  // Get the size of the questionvector from the current level
  int size = static_cast<int>(_questionvector[level].size());
 
  // Get a random number in the range from 0 - size
  // The random number generator is initialized in WGame.cpp
  int i = rand() % size;                
  return _questionvector[level][i];
}
 
 
 
/// Delivers the success state of parsing 
/**
 * @return Returns true if the XML File was parsed successfully
 */
bool QuestionDB::getSuccess() const
{
  return _success;
}
 
 
/// Parses a XML File
/**
 * @return Returns the success status of the parse operation
 */
bool QuestionDB::_parseFile()
{
  try
  {
    XMLPlatformUtils::Initialize();
  }
  catch(const XMLException& toCatch)
  {
    string message = XMLString::transcode(toCatch.getMessage());
    cerr << "Error during initialization!" << endl
         << "Exception message is:" << endl
         << message << endl;
    return false;
  }
 
  SAX2XMLReader   *parser  = XMLReaderFactory::createXMLReader();
  QuestionHandler *handler = new QuestionHandler();
 
  parser->setContentHandler(handler);   // Install the handler on the parser
  parser->setErrorHandler(handler);
 
  try
  {
    parser->parse(_xmlFile.c_str());         // Start parsing the file
  }
  catch(const XMLException& toCatch)
  {
    string message = XMLString::transcode(toCatch.getMessage());
    cerr << "XML Exception!" << endl
         << "Exception message is:" << endl
         << message << endl;
    return false;
  }
  catch(const SAXParseException& toCatch)
  {
    string message = XMLString::transcode(toCatch.getMessage());
    cerr << "SAX Exception!" << endl
         << "Exception message is:" << endl
         << message << endl;
    return false;
  }
  catch(...)
  {
    cerr << "Unexpected Exception!" << endl;
    return false;
  }
 
  handler->getQuestions(_questionvector);// Get the questions, which were parsed
 
 
  bool retval=true;
 
  // Check every level to have at least one question
  for(int i=0; i<=(MAXLEVEL-MINLEVEL); ++i)
  {
    if(_questionvector[i].size() < 1)
    {
      cerr << "Level " << i-MINLEVEL << " has no question!" << endl;
      retval=false;
    }
  }
 
  delete handler;
  delete parser;
 
  XMLPlatformUtils::Terminate();
 
  return retval;
}
