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
  printSideBarRowPadding();
  printHeaderLine();

  printSideBarRowPadding();
  cout << "|     CPP Chess In Terminal     |\n";

  printSideBarRowPadding();
  printHeaderLine();

  printSideBarRowPadding();
  cout << "| Lowercase = White             |\n";

  printSideBarRowPadding();
  cout << "| Uppercase = Black             |\n";

  printSideBarRowPadding();
  printHeaderLine();

  printSideBarRowPadding();
  cout << "| Curr Turn : " << currentTurnToString() << "    Page no. | " 
    << sideBar.currentPageIndex + 1 << endl;

  printSideBarRowPadding();
  printHeaderLine();
}

void printGrid() {
  int yCoord = 1;
  int sideBarRow = 0;

  printSideBarBorderLine();
  printBoardLine();

  for (int row = 0; row < ROWS; row++) {
    printCurrentSideBarRow(sideBarRow);
    sideBarRow++;

    for (int col = 0; col < COLS; col++) {
      cout << "|";
      cout << " " << getPieceOnTile(row,col) << " ";
    }

    cout << "| " << yCoord <<endl;
    yCoord++;
    
    printCurrentSideBarRow(sideBarRow);
    sideBarRow++;

    printBoardLine();
  }
  
}

void printFooter() {
  printSideBarRowPadding();
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

void printSideBarBorderLine() {
  cout << "+";
  for (int col = 0; col < PAGE_WIDTH; col++) {
    cout << "=";
  }
}

void printSideBarRowPadding() {
  for (int col = 0; col < PAGE_WIDTH + 1; col++) {
    cout << " ";
  }
}

void printCurrentSideBarRow(int row) {
  if (row < 0 || row >= PAGE_ROWS) {
    printSideBarBorderLine();
    return;
  }

  cout << "|";
  for (int col = 0; col < PAGE_WIDTH; col++) {
    cout << sideBar.pages[sideBar.currentPageIndex].content[row][col];
  }
}