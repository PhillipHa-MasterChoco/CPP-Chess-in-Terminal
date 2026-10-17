#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "normalGame.h"
#include "../gameData/gameData.h"
#include "../setupGame/setupGame.h"
#include "../boardFunctions/boardFunctions.h"


using namespace std;
using namespace chrono;
using namespace this_thread;

void runGameNormal() {
  gameLoop();
}

void gameLoop() {
  while (1) {
    selectPiece();
  }
}

void selectPiece() {
  bool valid = false;
  do {
    printGameBoard();
    char column;
    int row;
    if(!(cin >> column)) exit(1);
    
    if (column == 'R' || column == 'L') {
      turnSideBarPage(column);
      return;
    }
    
    if(!(cin >> row)) exit(1);
    valid = isValidSelection(column, row);
    
    if (!valid) {
      cout << "Invalid input, enter again\n";
    }
    
  } while(!valid);
}

bool isValidSelection(char column, int row) {
  if (!(column >= 'A' && column <= 'H')) return false;
  if (!(row >= 1 && row <= 8)) return false;
  int boardCol = letterToIndex(column);
  int boardRow = row - 1;

  // cout << "Up to turn check\n";
  // cout << "Piece colour is " << gameData.board[boardRow][boardCol].colour << endl;
  // cout << "Current turn is " << gameData.currentTurn << endl;
  if (gameData.currentTurn != gameData.board[boardRow][boardCol].colour) return false;

  return true;
}

int letterToIndex(char letter) {
  return letter - 65;
}