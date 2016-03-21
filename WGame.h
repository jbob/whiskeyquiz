#include "questiondb.h"
#include "gui.h"
#include "sound.h"
#include "k8055.h" 
 
/**
 * @enum States
 * @brief Contains the different states for the statemachine
 * @author Andreas Janning
 * @version 1.0
 * @date 2008-12-10
 * @bug None
 * @warning None
 * @todo Nothing
 */
enum States
{
  /// A new game starts
  NewGame,
  /// A new question comes
  NewQuestion,
  /// An answer was given
  Answer,
  /// The game is over
  GameOver,
  /// We are waiting for a key press
  Waiting
};
 
 
/**
 * @class WGame
 * @brief An object of this class represents one game
 * @author Andreas Janning
 * @version 1.5
 * @date 2008-12-10
 * @bug None
 * @warning None
 * @todo Nothing
 */
class WGame
{
public:
  WGame();
  ~WGame();
  void start();
 
private:
  /// Object that holds the questions
  QuestionDB _QDB;
  /// Object for GUI handling
  GUI _GUI;
  /// Object used to play the sounds
  Sound _Sound;
  /// Object for hardware interaction
  k8055* _IO;
  /// The current state of the statemachine
  States state;
  /// The next state of the statemachine
  States next_state;
  /// The right answer for the current question [1,4]
  int rightAnswer;
  /// Number of correct answered questions
  int winCount;
  /// The pressed key, [1,4] or -1 if no key was pressed
  int key;
  /// The timeout before the game is lost
  int countdown;
  /// Tells us if there is a jar, or not
  bool jar;
  /// If true, the game is over, and no new one is started
  bool end;
 
  void statemachine();
};
