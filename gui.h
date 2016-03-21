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

#ifndef _gui_h_
#define _gui_h_
 
#include <string>
#include <sstream>
 
#include <QtGui/QApplication>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QFont>
#include <QtGui/QWidget>
#include <QtGui/QSound>
#include <QtCore/QString>
 
 
/// The horizontal size of our window (screensize)
const int XSize = 800;
 
/// The vertical size of our window (screensize)
const int YSize = 600;
 
 
/**
 * @class GUI
 * @brief This class handles the GUI
 * @author Markus Koch
 * @version 1.0
 * @date 2008-12-02
 * @bug None
 * @warning None
 * @todo Maybe polish the GUI a bit more
 */
class GUI
{
  public:
    GUI();
    ~GUI();
    void showStart();
    void showQuestion(std::string*, int, int);
    void showRight();
    void showWrong();
    void showEnd(bool);
    void refresh(int=-1);
 
  private:
    /// *The* application object
    QApplication* _app;
    /// The main window (and only one ;-))
    QWidget* _window;
    /// A label which contains the current question
    QLabel* _question;
    /// This label is left of the question and contains the bottle picture
    QLabel* _bottleleft;
    /// This label is right of the question and contains the bottple picture
    QLabel* _bottleright;
    /// This label shows the current level in the upper left corner
    QLabel* _level;
    /// This label shows an countdown in the upper right corner
    QLabel* _countdown;
    /// The first answer alternative button
    /** Button is without function, but looks better as a QLabel Object */
    QPushButton* _answer1;
    /// The second answer alternative button
    /** Button is without function, but looks better as a QLabel Object */
    QPushButton* _answer2;
    /// The third answer alternative button
    /** Button is without function, but looks better as a QLabel Object */
    QPushButton* _answer3;
    /// The fourth answer alternative button
    /** Button is without function, but looks better as a QLabel Object */
    QPushButton* _answer4;
    /// Defines a good looking an *big* font
    QFont* _fontstyle;
    /// Black text object
    QPalette* _blacktext;
    /// Green text object (right answer, game one, one answer alternative)
    QPalette* _greentext;
    /// Red text object (false answer, game lost, one answer alternative)
    QPalette* _redtext;
    /// Blue text Object (one answer alternative)
    QPalette* _bluetext;
    /// Yellow text Object (one answer alternative)
    QPalette* _yellowtext;
    /// This object represents a picture of a bottle (png format)
    QPixmap* _bottle;
 
};
 
#endif
