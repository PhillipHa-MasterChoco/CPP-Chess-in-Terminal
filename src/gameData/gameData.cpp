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

  for (int i = 0; i < 40; i++ ) {
    appendToSideBar("Hello this is a test!");
  }

  // printCurrentSideBarContent();
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
    case 'L':
      doTurnSideBarPage(-1);
      break;
    case 'R':
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
  // cout << "String size is " << input.size() << endl;
  class sideBarPage *page = sideBar.lastPage;

  
  if (!page) return;
  cout << "Page number is " << page->pageNumber << endl;
  
  if (page->capacity >= page->maxCapacity) {
    cout << "Ran out of capacity, creating new page" << endl;
    page = newSideBarPage();
  }

  cout << "Capacity is " << page->capacity << endl;
  int colStart = page->capacity % PAGE_WIDTH;
  int rowStart = (page->capacity - colStart)/PAGE_WIDTH;

  cout << "colStart rowStart is: " << colStart << ", " << rowStart << endl;
  for (int row = rowStart, col = colStart; row < PAGE_ROWS; row++) {
    for (int colLoop = col; colLoop < PAGE_WIDTH; colLoop++) {
      if (strIndex >= input.size()) return;
      // cout << "Current string index is " << strIndex << endl;
      page->content[row][colLoop] = input[strIndex];
      strIndex++;
      ++page->capacity;
    }
    
    col = 0;
  }
  
  // If string hasn't finished printing, 
  // recursive call to finish off string
  if (strIndex < input.size()) {
    appendToSideBar(input.substr(strIndex));
  }

  cout << "Returned printing successfully\n";
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
