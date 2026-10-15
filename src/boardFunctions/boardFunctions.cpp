#include <iostream>
#include <string>

#include "boardFunctions.h"
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
  printHeader();
  printBoardLine();
  int yCoord = 8;

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      cout << "|";
      cout << "   ";
    }
    cout << "| " << yCoord <<endl;
    yCoord--;
    printBoardLine();
  }
  printFooter();
}

void printHeaderLine() {
  cout << "+";
  for (int col = 0; col < COLS; col++) {
    cout << "===+";
  }
  cout << "\n";
}

void printHeader() {
  printHeaderLine();
  cout << "|     CPP Chess In Terminal     |\n";
  printHeaderLine();
  cout << "| Lowercase = White             |\n";
  cout << "| Uppercase = Black             |\n";
  printHeaderLine();
  cout << "| Curr Turn : " << currentTurnToString() << "             |\n";
  printHeaderLine();
}

void printFooter() {
  char xCoord = 'A';
  cout << "  ";
  for (int col = 0; col < COLS; col++, xCoord++) {
    cout << xCoord << "   ";
  }
  cout << endl;
}

string currentTurnToString() {
  string currentTurn = "Error";
  
  switch (gameData.currentTurn) {
    case WHITE:
      currentTurn = "White";
      break;
    case BLACK:
      currentTurn = "Black";
      break;
    default:
      break;
  }

  return currentTurn;
}