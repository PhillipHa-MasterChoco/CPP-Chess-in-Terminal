#include <iostream>
#include <string>

#include "gameData.h"

using namespace std;
// Initialises the board to empty values
void initBoard() {
  gameData.currentTurn = WHITE;
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      gameData.board[row][col].piece = NONE;
      gameData.board[row][col].colour = EMPTY;
      gameData.board[row][col].threatened = false;
    }
  }
}

void initSideBar() {
  class sideBarPage *newPage = newSideBarPage();
  sideBar.currentPage = newPage;
  appendToSideBar("Hello this is a test!");
  printCurrentSideBarContent();
}

class sideBarPage *newSideBarPage() {
  class sideBarPage *newPage = new sideBarPage;
  newPage->pageNumber = sideBar.numberOfPages + 1;
  ++sideBar.numberOfPages;
  initialiseSideBarPage(newPage);
  
  class sideBarPage *lastPage = sideBar.lastPage;
  if (lastPage) {
    lastPage->next = newPage;
    newPage->prev = lastPage;
  } 
  
  sideBar.lastPage = newPage;

  return newPage;
}

void initialiseSideBarPage(class sideBarPage *page) {
  for (int row = 0; row < PAGE_ROWS; row++) {
    for (int col = 0; col < PAGE_WIDTH; col++) {
      page->content[row][col] = ' ';
    }
  }
}

void turnSideBarPage(char direction) {
  switch (direction) {
    case 'l':
      doTurnSideBarPage(-1);
      break;
    case 'r':
      doTurnSideBarPage(1);
    default:
      return;
  }
}

void doTurnSideBarPage(int offset) {
  if (offset == 0) return;

  class sideBarPage *currentPage = sideBar.currentPage;
  int targetPageNumber = currentPage->pageNumber + offset;
  if (targetPageNumber > sideBar.numberOfPages || targetPageNumber <= 0) {
    return;
  }

  class sideBarPage *nextPage;

  if (offset < 0) {
    nextPage = currentPage->prev;
  }

  if (offset > 0) {
    nextPage = currentPage->next;
  }

  sideBar.currentPage = nextPage;
}

void appendToSideBar(string input) {
  int strIndex = 0;
  cout << "String size is " << input.size() << endl;
  class sideBarPage *page = sideBar.lastPage;

  if (!page) return;

  for (int row = 0; row < PAGE_ROWS; row++) {
    for (int col = 0; col < PAGE_WIDTH; col++) {
      if (page->capacity > page->maxCapacity) {
        page = newSideBarPage();
      }

      if (strIndex >= input.size()) return;

      cout << "Current string index is " << strIndex << endl;
      page->content[row][col] = input[strIndex];
      strIndex++;
      ++page->capacity;

    }
  }
}

// Used for debugging
void printCurrentSideBarContent() {
  class sideBarPage *page = sideBar.currentPage;

  for (int row = 0; row < PAGE_ROWS; row++) {
    for (int col = 0; col < PAGE_WIDTH; col++) {
      cout << page->content[row][col];
    }
    cout << "|" << endl;
  }
}
