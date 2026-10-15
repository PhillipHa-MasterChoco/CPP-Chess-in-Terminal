#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "main.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

int main()
{
  gameSetup();

  return 0;
}

void gameSetup() {
  bool valid = false;
  printStart();
  do {
    char input;
    if(!(cin >> input)) exit(0);
    switch (input) {
      case 'P':
        valid = true;
        // startNormalGame
        cout << "Feature not yet implemented\n" << flush;
        sleep_for(seconds(1));
        break;
      case 'G':
        cout << "Feature not yet implemented\n" << flush;
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

void printStart() {
  cout << "\033[2J\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|        Welcome to C++ Chess in terminal!         |\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|    Play normal game    |    View Previous Games  |\n";
  cout << "|        Enter 'P'       |         Enter 'G'       |\n";
  cout << "|                        |   Not yet implemented   |\n";
  cout << "|------------------------|------------------------ |\n";
  cout << "|     View Stats         |           Quit          |\n";
  cout << "|        Enter 'S'       |         Enter 'Q'       |\n";
  cout << "|   Not yet implemented  |                         |\n";
  cout << "|--------------------------------------------------|\n";
}

