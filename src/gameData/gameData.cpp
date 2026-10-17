#include <iostream>
#include <string>
#include <vector>

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
  sideBar.currentPageIndex = newSideBarPage();

  for (int i = 0; i < 40; i++ ) {
    cout << "Attempting to add\n";
    appendToSideBar("Hello this is a test!");
  }

  addErrorMessage(ERROR_TEST);

  // printCurrentSideBarContent();
}

// Creates a new sideBarPage and points to its index
// in the sideBar.sideBarPages vector
int newSideBarPage() {
  sideBarPage newPage;
  newPage.pageIndex = sideBar.pages.size(); 
  initSideBarPageContent(&newPage);
  sideBar.pages.push_back(newPage);

  return newPage.pageIndex;
}

// Initialise all content to empty spaces
void initSideBarPageContent(class sideBarPage *page) {
  for (int row = 0; row < PAGE_ROWS; row++) {
    for (int col = 0; col < PAGE_WIDTH; col++) {
      page->content[row][col] = ' ';
    }
  }
}

// Turn sideBarPage left or right
void turnSideBarPage(char direction) {
  switch (direction) {
    case 'L':
      doTurnSideBarPage(TURN_PAGE_LEFT);
      break;
    case 'R':
      doTurnSideBarPage(TURN_PAGE_RIGHT);
    default:
      return;
  }
}

// Turns the sidebar by a given offset
void doTurnSideBarPage(int offset) {
  // Returns early if there is no offset
  if (offset == 0) return;

  int targetPageNumber = sideBar.currentPageIndex + offset;
  // If it would scroll to a non existent page, return early
  if (targetPageNumber >= sideBar.pages.size() 
    || targetPageNumber < 0) {
    return;
  }

  sideBar.currentPageIndex = targetPageNumber;
}

// Appends a given string input to the sidebar
// if the string overflows the page, it creates
// a new page for this content
// Might add auto turn
void appendToSideBar(string input) {
  int strIndex = 0;

  if (sideBar.pages.size() < 1) {
    newSideBarPage();
    appendToSideBar(input);
    return;
  }
  // cout << "String size is " << input.size() << endl;
  sideBarPage *page = &sideBar.pages.back();

  if (page->capacity >= page->maxCapacity) {
    newSideBarPage();
    appendToSideBar(input);
    return;
  }

  int colStart = page->capacity % PAGE_WIDTH;
  int rowStart = (page->capacity - colStart)/PAGE_WIDTH;

  // For loop loops to the end of the page and then ends
  for (int row = rowStart, col = colStart; row < PAGE_ROWS; row++) {
    for (int colLoop = col; colLoop < PAGE_WIDTH; colLoop++) {
      if (strIndex >= input.size()) return;
      page->content[row][colLoop] = input[strIndex];
      strIndex++;
      ++page->capacity;
    }
    
    col = 0;
  }
  
  // Because of this,
  // If string hasn't finished printing due to space, 
  // recursive call to finish off string on a new page
  if (strIndex < input.size()) {
    appendToSideBar(input.substr(strIndex));
  }
}

// Used for debugging; print outs all apge content
// outside of sidebar
void printCurrentSideBarContent() {
  sideBarPage page = sideBar.pages[sideBar.currentPageIndex];

  for (int row = 0; row < PAGE_ROWS; row++) {
    for (int col = 0; col < PAGE_WIDTH; col++) {
      cout << page.content[row][col];
    }
    cout << "|" << endl;
  }
}

// Adds an error message to the sideBar
void addErrorMessage(string input) {
  // If the error message is too long return early
  // and put in an error message
  if (input.size() >= PAGE_WIDTH) {
    addErrorMessage(INVALID_ERROR_MESSAGE);
    return;
  }

  for (int i = 0; i < input.size(); i++) {
    sideBar.errorContent[i] = input[i];
  }

  // Fill the rest of the space with empty spaces for padding
  if (input.size() <= PAGE_WIDTH) {
    for (int i = input.size(); i < PAGE_WIDTH; i++) {
      sideBar.errorContent[i] = ' ';
    }
  }
}