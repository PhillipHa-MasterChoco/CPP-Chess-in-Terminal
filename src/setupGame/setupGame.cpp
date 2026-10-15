#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "../gameData/gameData.h"
#include "setupGame.h"
#include "../normalGame/normalGame.h"
#include "../replayGame/replayGame.h"
#include "../statsGame/statsGame.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

class gameData gameData;

// Prints the starting interface
void printStart() {
  cout << "\033[2J\n";
  cout << "+--------------------------------------------------+\n";
  cout << "|        Welcome to C++ Chess in terminal!         |\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|    Play normal game    |    View Previous Games  |\n";
  cout << "|        Enter 'P'       |         Enter 'R'       |\n";
  cout << "|                        |   Not yet implemented   |\n";
  cout << "|------------------------|------------------------ |\n";
  cout << "|     View Stats         |           Quit          |\n";
  cout << "|        Enter 'S'       |         Enter 'Q'       |\n";
  cout << "|   Not yet implemented  |                         |\n";
  cout << "+--------------------------------------------------+\n";
}

// Waits for the user to select a valid gameMode
// upon successfully entering a gamemode it set the
// gamemode in game data
void gameModeSelect() {
  bool valid = false;
  printStart();
  do {
    char input;
    if(!(cin >> input)) exit(0);
    switch (input) {
      case 'P':
        valid = true;
        gameData.gameMode = NORMAL;
        cout << "Feature not yet implemented\n" << flush;
        sleep_for(seconds(1));
        break;
      case 'R':
        cout << "Feature not yet implemented\n" << flush;
        gameData.gameMode = REPLAY;
        sleep_for(seconds(1));
        exit(1);
        break;
      case 'S':
        gameData.gameMode = STATS;
        cout << "Feature not yet implemented\n" << flush;
        sleep_for(seconds(1));
        exit(1);
        break;
      case 'Q':
        exit(0);
      case EOF:
        exit(0);
      default:
        cout << "Invalid input, enter again\n" << flush;
        sleep_for(seconds(1));
    }
  } while (!valid);
}

// Starts the game in its intended mode
void gameStart() {
  switch (gameData.gameMode) {
    case NORMAL:
      runGameNormal();
      break;
    case REPLAY:
      runGameReplay();
      break;
    case STATS:
      runGameStats();
    default:
      cout << "Error no game mode\n" << flush;
  }
}

