#include <iostream>
#include <string>

#include "boardFunctions.h"
#include "../gameData/gameData.h"

using namespace std;

const int letterCaseOffset = 32;

void printBoardLine() {
  cout << "+";
  for (int col = 0; col < COLS; col++) {
    cout << "---+";
  }
  cout << "\n";
}

// Prints the entire game board
void printGameBoard() {
  printHeader();
  printBoardLine();
  printGrid();
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
  cout << "\033[2J\n";
  printHeaderLine();
  cout << "|     CPP Chess In Terminal     |\n";
  printHeaderLine();
  cout << "| Lowercase = White             |\n";
  cout << "| Uppercase = Black             |\n";
  printHeaderLine();
  cout << "| Curr Turn : " << currentTurnToString() << "             |\n";
  printHeaderLine();
}

void printGrid() {
  int yCoord = 1;

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      cout << "|";
      cout << " " << getPieceOnTile(row,col) << " ";
    }
    cout << "| " << yCoord <<endl;
    yCoord++;
    printBoardLine();
  }
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

char getPieceOnTile(int row, int col) {
  char piece;
  switch (gameData.board[row][col].piece) {
    case PAWN:
      piece = 'p';
      break;
    case BISHOP:
      piece = 'b';
      break;
    case KNIGHT:
      piece = 'k';
      break;
    case ROOK:
      piece = 'r';
      break;
    case QUEEN:
      piece = 'q';
      break;
    case KING:
      piece = 'k';
      break;
    default:
      return ' ';
  }

  if (gameData.board[row][col].colour == BLACK) {
    piece -= letterCaseOffset;
  }

  return piece;
}
