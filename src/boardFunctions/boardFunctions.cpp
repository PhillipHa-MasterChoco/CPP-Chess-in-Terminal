#include <iostream>

#include "gameData.h"

using namespace std;

void printBoardLine() {
  cout << "+";
  for (int col = 0; col < COLS; col++) {
    cout << "--+";
  }
  cout << "\n";
}