#include "WGame.h"
#include <ctime>
#include <string> 
 
using namespace std;
 
 
/// The constructor initializes the IO object
WGame::WGame()
{
  _IO = new k8055(PWM1, PWM2, 42, IPID);
}
 
 
/// The destructor deletes the IO object
WGame::~WGame()
{
  if(_IO != 0)
  {
    delete _IO;
    _IO = 0;
  }
}
 
 
/// Initializes values and starts the game
void WGame::start()
{
  state = NewGame;
  end = false;
  srand(time(NULL));
  statemachine();
}
 
 
/// This statemachine represents the game logic
void WGame::statemachine()
{
 
  Question nextQuestion;
  string Questionstring[5];
  int i, j, err;
  States timeout_state = NewGame;
  int taste=-1;
 
  while(end != true)
  {
    switch(state)
    {
      case NewGame:
        _Sound.playStart();             // Play start sound
        _GUI.showStart();               // and show start screen
        winCount = 0;                   // A new game starts, no question was answered correct
        key = -1;                       // The pressed key [1,4]; -1 means no key was pressed
        countdown = -1;                 // Time before to go to the next state; -1 means no countdown
        state = Waiting;                // When a new game starts we are waiting for a key to be pressed
        next_state = NewQuestion;       // After the key was pressed we are going to play the first question
        usleep(1000000);                // 1 second
        break;
 
      case Waiting:
        if(next_state == Answer)        // We are waiting for an answer
        {
          _GUI.refresh(countdown/10);   // so we must show the countdown
          --countdown;                  // and of course decrement it
        }
        else if(countdown > 0)          // We are *not* waiting for an answer, just for a key press
        {
          _GUI.refresh();               // so we have *not* to show the countdown
          --countdown;                  // but it must still count, because the player may leave the game
        }
 
        if(countdown == 0)              // Player was too slow, or has left
        {
          state = timeout_state;        // So the game is over
        }
 
        _IO->getAnalogKeys(&key);       // Key is read live from hadrware (no buffer!)
 
        if(key != -1)                   // -1 means no key was pressed
        {
          taste = key;
          while(key!=-1)                // Wait for key to be released
          {
            _IO->getAnalogKeys(&key);
            usleep(100000);             // 0.1 seconds
          }
          state = next_state;           // Key was pressed -> go to the next state
        }
 
        usleep(100000);                 // 0.1 seconds
        break;
 
      case NewQuestion:
        _Sound.playQuestion();
        rightAnswer = (rand()%4)+1;     // rightAnser = [1,4]
        nextQuestion = _QDB.getQuestion(winCount+1);  // get a question with the next hardness level
        Questionstring[0] = nextQuestion.text;
 
        for(i = 1; i < 5; ++i)          // shift the answer alternatives
        {
          j = i - rightAnswer;
          if (j < 0) j = j + 4;
          Questionstring[i] = nextQuestion.answer[j];
        }
 
        countdown = 290;                // Player has 300*0.1 seconds to answer
        _GUI.showQuestion(Questionstring, winCount+1, countdown/10);  // Show the question with countdown
        state = Waiting;                // and now wait for a key
        next_state = Answer;            // evaluate the answer
        usleep(1000000);                // 1 second
        timeout_state = GameOver;
        break;
 
      case Answer:
        _Sound.playAnswer();
 
        if(taste == rightAnswer)        // Player has answered correct
        {
          if(++winCount == 5)           // every question
          {
            next_state = GameOver;      // so the game is over
          }
          else                          // there is another question
          {
            next_state = NewQuestion;
          }
          _GUI.showRight();
        }
        else                            // Player has answered false
        {
          next_state = GameOver;        // so the game is oooovvveerrr!
          _GUI.showWrong();
        }
 
        state = Waiting;
        countdown=20;                   // Player has 30*0.1 seconds to go to the next question
        timeout_state = next_state;
        usleep(1000000);                // 1 second
        break;
 
      case GameOver:
        if(winCount == 5)              // Player has won
        {
          _GUI.showEnd(true);
          _Sound.playEnd(true);
          jar = false;
          while(!jar)                   // Jar detection
          {
            _IO->getJar(&jar);
            usleep(100000);             // 0.1 seconds
          }
          _IO->pumpFluid(&err);         // Jar detected, so pump
 
        }
        else                            // Player has lost
        {
          _GUI.showEnd(false);
          _Sound.playEnd(false);
        }
 
        next_state = NewGame;           // Old game is over, so start a new one
        state = Waiting;
        countdown=40;                   // After 40*0.1 seconds the new game is autmaticliy started
        timeout_state = next_state;
        usleep(1000000);                // 1 second
        break;
    }
  }
}
