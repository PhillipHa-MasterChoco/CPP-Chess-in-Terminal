#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "main.h"
#include "normalGame.h"
#include "replayGame.h"
#include "statsGame.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

int main() {
  modeSetup();
  gameStart();
  gameEnd();

  return 0;
}

void printStart() {
  cout << "\033[2J\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|        Welcome to C++ Chess in terminal!         |\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|    Play normal game    |    View Previous Games  |\n";
  cout << "|        Enter 'P'       |         Enter 'R'       |\n";
  cout << "|                        |   Not yet implemented   |\n";
  cout << "|------------------------|------------------------ |\n";
  cout << "|     View Stats         |           Quit          |\n";
  cout << "|        Enter 'S'       |         Enter 'Q'       |\n";
  cout << "|   Not yet implemented  |                         |\n";
  cout << "|--------------------------------------------------|\n";
}

void modeSetup() {
  bool valid = false;
  printStart();
  do {
    char input;
    if(!(cin >> input)) exit(0);
    switch (input) {
      case 'P':
        valid = true;
        GameMode gameData.gameMode = GameMode::NORMAL;
        cout << "Feature not yet implemented\n" << flush;
        sleep_for(seconds(1));
        break;
      case 'R':
        cout << "Feature not yet implemented\n" << flush;
        GameMode gameData.gameMode = REPLAY;
        sleep_for(seconds(1));
        break;
      case 'S':
        cout << "Feature not yet implemented\n" << flush;
        sleep_for(seconds(1));
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

void printEnd() {
  cout << "\033[2J\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|                  Thanks for playing!             |\n";
  cout << "|--------------------------------------------------|\n";
}

void gameEnd() {
  // This function will later be used to store data once the game has ended
  // for now it will just call printEnd
  printEnd();
}

