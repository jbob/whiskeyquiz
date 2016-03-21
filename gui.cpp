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
#include "gui.h"
 
/// The constructor, the private class objects are initialized here and the GUI is plugged together
GUI::GUI()
{
  _app = new QApplication(0, 0);          // Not perferct, but works
  _app->setOverrideCursor(QCursor(Qt::BlankCursor));
  _window = new QWidget();
  _window->resize(XSize, YSize);
 
  _fontstyle = new QFont("SansSerif", 28);
  _bottle = new QPixmap("/opt/usr/share/pixmaps/bottle.png");
 
  _blacktext = new QPalette();
  _blacktext->setColor(QPalette::WindowText, QColor(Qt::black));
  _blacktext->setColor(QPalette::ButtonText, QColor(Qt::black));
 
  _greentext = new QPalette();
  _greentext->setColor(QPalette::WindowText, QColor(Qt::green));
  _greentext->setColor(QPalette::ButtonText, QColor(Qt::green));
 
  _redtext = new QPalette();
  _redtext->setColor(QPalette::WindowText, QColor(Qt::red));
  _redtext->setColor(QPalette::ButtonText, QColor(Qt::red));
 
  _bluetext = new QPalette();
  _bluetext->setColor(QPalette::WindowText, QColor(Qt::blue));
  _bluetext->setColor(QPalette::ButtonText, QColor(Qt::blue));
 
  _yellowtext = new QPalette();
  _yellowtext->setColor(QPalette::WindowText, QColor(Qt::yellow));
  _yellowtext->setColor(QPalette::ButtonText, QColor(Qt::yellow));
 
  _bottleleft = new QLabel(_window);
  _bottleleft->setPixmap(*_bottle);
  _bottleleft->setGeometry(0, 0, XSize/8, YSize/2);
 
  _bottleright = new QLabel(_window);
  _bottleright->setPixmap(*_bottle);
  _bottleright->setGeometry((XSize/8)*7, 0, XSize/8, YSize/2);
 
  _level = new QLabel(_window);
  _level->setGeometry(XSize/8, 0, (XSize/8)*3, YSize/12);
  _level->setAlignment(Qt::AlignLeft);
  _level->setFont(*_fontstyle);
 
  _countdown = new QLabel(_window);
  _countdown->setGeometry(XSize/2, 0, (XSize/8)*3, YSize/12);
  _countdown->setAlignment(Qt::AlignRight);
  _countdown->setFont(*_fontstyle);
 
  _question = new QLabel(_window);
  _question->setGeometry(XSize/8, YSize/12, (XSize/8)*6, YSize/2);
  _question->setAlignment(Qt::AlignCenter);
  _question->setWordWrap(true);
  _question->setFont(*_fontstyle);
 
  _answer1 = new QPushButton(_window);
  _answer1->setGeometry(0, YSize/2, XSize, YSize/8);
  _answer1->setFont(*_fontstyle);
  _answer1->setPalette(*_yellowtext);
  _answer1->setFocusPolicy(Qt::NoFocus);
  _answer1->setEnabled(false);
 
 
  _answer2 = new QPushButton(_window);
  _answer2->setGeometry(0, (YSize/2)+(YSize/8), XSize, YSize/8);
  _answer2->setFont(*_fontstyle);
  _answer2->setPalette(*_greentext);
  _answer2->setFocusPolicy(Qt::NoFocus);
  _answer2->setEnabled(false);
 
  _answer3 = new QPushButton(_window);
  _answer3->setGeometry(0, (YSize/2)+2*(YSize/8), XSize, YSize/8);
  _answer3->setFont(*_fontstyle);
  _answer3->setPalette(*_bluetext);
  _answer3->setFocusPolicy(Qt::NoFocus);
  _answer3->setEnabled(false);
 
  _answer4 = new QPushButton(_window);
  _answer4->setGeometry(0, (YSize/2)+3*(YSize/8), XSize, YSize/8);
  _answer4->setFont(*_fontstyle);
  _answer4->setPalette(*_redtext);
  _answer4->setFocusPolicy(Qt::NoFocus);
  _answer4->setEnabled(false);
 
  _window->show();
  _app->processEvents();
}
 
 
/// The destructor, the private class objects are deleted here
GUI::~GUI()
{
  if(_app != 0)
  {
    delete _app;
    _app = 0;
  }
 
  if(_window != 0)
  {
    delete _window;
    _window = 0;
  }
 
  if(_question != 0)
  {
    delete _question;
    _question = 0;
  }
 
  if(_answer1 != 0)
  {
    delete _answer1;
    _answer1 = 0;
  }
 
  if(_answer2 != 0)
  {
    delete _answer2;
    _answer2 = 0;
  }
 
  if(_answer3 != 0)
  {
    delete _answer3;
    _answer3 = 0;
  }
 
  if(_answer4 != 0)
  {
    delete _answer4;
    _answer4 = 0;
  }
 
  if(_fontstyle != 0)
  {
    delete _fontstyle;
    _fontstyle = 0;
  }
 
  if(_blacktext != 0)
  {
    delete _blacktext;
    _blacktext = 0;
  }
 
  if(_greentext != 0)
  {
    delete _greentext;
    _greentext = 0;
  }
 
  if(_redtext != 0)
  {
    delete _redtext;
    _redtext = 0;
  }
 
  if(_bluetext != 0)
  {
    delete _bluetext;
    _bluetext = 0;
  }
 
  if(_yellowtext != 0)
  {
    delete _yellowtext;
    _yellowtext = 0;
  }
 
  if(_bottle != 0)
  {
    delete _bottle;
    _bottle = 0;
  }
 
  if(_bottleright != 0)
  {
    delete _bottleright;
    _bottleright = 0;
  }
 
  if(_bottleleft != 0)
  {
    delete _bottleleft;
    _bottleleft = 0;
  }
 
  if(_level != 0)
  {
    delete _level;
    _level = 0;
  }
 
  if(_countdown != 0)
  {
    delete _countdown;
    _countdown = 0;
  }
}
 
 
/// Shows an start screen at the beginning of a game
void GUI::showStart()
{
  _question->setText(QString::fromUtf8("+++ SPIEL BEGINNT +++"));
  _question->setPalette(*_blacktext);
 
  _level->setText(QString(""));
  _countdown->setText(QString(""));
 
  _answer1->setText(QString(""));
  _answer2->setText(QString(""));
  _answer3->setText(QString(""));
  _answer4->setText(QString(""));
 
  refresh();
}
 
 
/// Shows a new question and the answer alternatives
/**
 * @param strings A string array which contains the question and the four answer alternatives
 * @param level The current level, which is displayed in the upper left corner of the GUI
 * @param countdown The countdown, which is displayed in the upper right corner of the GUI
 */
void GUI::showQuestion(std::string* strings, int level, int countdown)
{
  _question->setText(QString::fromUtf8(strings[0].c_str()));
  _question->setPalette(*_blacktext);
 
  std::ostringstream oss;               // This three lines make a conversion
  oss << "Level: " << level;            // int -> QString
  _level->setText(QString((oss.str()).c_str()));
 
  std::ostringstream oss2;              // This three lines make a conversion
  oss2 << countdown;                    // int -> QString
  _countdown->setText(QString((oss2.str()).c_str()));
 
  _answer1->setText(QString::fromUtf8(strings[1].c_str()));
  _answer2->setText(QString::fromUtf8(strings[2].c_str()));
  _answer3->setText(QString::fromUtf8(strings[3].c_str()));
  _answer4->setText(QString::fromUtf8(strings[4].c_str()));
 
  refresh();
}
 
 
/// Displays that a question was answered right
void GUI::showRight()
{
  _question->setText(QString::fromUtf8("+++ RICHTIG +++"));
  _question->setPalette(*_greentext);
 
  _level->setText(QString(""));
  _countdown->setText(QString(""));
 
  _answer1->setText(QString(""));
  _answer2->setText(QString(""));
  _answer3->setText(QString(""));
  _answer4->setText(QString(""));
 
  refresh();
}
 
 
/// Displays that a question was answered false
void GUI::showWrong()
{
  _question->setText(QString::fromUtf8("+++ FALSCH +++"));
  _question->setPalette(*_redtext);
 
  _level->setText(QString(""));
  _countdown->setText(QString(""));
 
  _answer1->setText(QString(""));
  _answer2->setText(QString(""));
  _answer3->setText(QString(""));
  _answer4->setText(QString(""));
 
  refresh();
}
 
 
/// Shows an end screen if the game is over
/** @param endstatus If this parameter is true a "game-won" screen is showed, otherwise a "game-lost" screen */
void GUI::showEnd(bool endstatus)
{
  if(endstatus == true)
  {
    _question->setText(QString::fromUtf8("+++ SPIEL GEWONNEN +++"));
    _question->setPalette(*_greentext);
  }
  else
  {
    _question->setText(QString::fromUtf8("+++ SPIEL VERLOREN +++"));
    _question->setPalette(*_redtext);
  }
 
  _level->setText(QString(""));
  _countdown->setText(QString(""));
 
  _answer1->setText(QString(""));
  _answer2->setText(QString(""));
  _answer3->setText(QString(""));
  _answer4->setText(QString(""));  
 
  refresh();
 
}
 
/// Refreshes the GUI, this is not done automaticly, because we can't run QApplication::exec()
/**
 * @param countdown The countdown, which is displayed in the upper right corner of the GUI
 */
void GUI::refresh(int countdown)
{
  if(((_countdown->text()).toInt() != countdown) && (countdown != -1))
  {
    std::ostringstream oss;
    oss << countdown;  
    _countdown->setText(QString((oss.str()).c_str()));
  }
 
  _window->repaint();
  _app->processEvents();
}
