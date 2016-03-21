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
 
 
#ifndef _questiondb_h_
#define _questiondb_h_
 
#include <vector>
#include <string>
 
#include "question.h"                   // The Question struct
 
using namespace std;
 
/// The minimal allowed level value
const int MINLEVEL = 1;
 
/// The maximal allowed level value
const int MAXLEVEL = 5;
 
 
/**
 * @class QuestionDB
 * @brief An object of this class represents the complete Question Database
 * @author Markus Koch
 * @version 1.5
 * @date 2008-11-17
 * @bug None
 * @warning None
 * @todo Nothing
 */
class QuestionDB
{
  public:
    QuestionDB(const string& = "/opt/usr/etc/questions.xml");
    ~QuestionDB();
 
    Question getQuestion(int = 1) const;
    bool getSuccess() const;
 
  private:
    /// This is the filename of the XML file to parse
    string _xmlFile;
 
    /// Vectorarray of the questions
    /** One array-element is a vector of questions from one level */
    vector<Question> _questionvector[(MAXLEVEL-MINLEVEL)+1];
 
    bool _parseFile();
 
    /// Indicates if the file was parsed sucessfully
    bool _success;
};
 
#endif
