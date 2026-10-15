#include <iostream>

#include "../gameData/gameData.h"

using namespace std;

void printBoardLine() {
  cout << "+";
  for (int col = 0; col < COLS; col++) {
    cout << "---+";
  }
  cout << "\n";
}

void printGameBoard() {
  printBoardLine();
  cout << "| CPP Chess In Terminal |\n";
  printBoardLine();
}