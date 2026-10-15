#include "gameData.h"

// Initialises the board to empty values
void initBoard() {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      gameData.board[row][col].piece = NONE;
      gameData.board[row][col].threatened = false;
    }
  }
}