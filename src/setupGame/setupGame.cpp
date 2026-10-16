#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "../gameData/gameData.h"
#include "setupGame.h"
#include "../normalGame/normalGame.h"
#include "../replayGame/replayGame.h"
#include "../statsGame/statsGame.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

class gameData gameData;
class sideBar sideBar;

// Prints the starting interface
void printStart() {
  cout << "\033[2J\n";
  cout << "+--------------------------------------------------+\n";
  cout << "|        Welcome to C++ Chess in terminal!         |\n";
  cout << "|--------------------------------------------------|\n";
  cout << "|    Play normal game    |    View Previous Games  |\n";
  cout << "|        Enter 'P'       |         Enter 'R'       |\n";
  cout << "|                        |   Not yet implemented   |\n";
  cout << "|------------------------|------------------------ |\n";
  cout << "|     View Stats         |           Quit          |\n";
  cout << "|        Enter 'S'       |         Enter 'Q'       |\n";
  cout << "|   Not yet implemented  |                         |\n";
  cout << "+--------------------------------------------------+\n";
}

// Waits for the user to select a valid gameMode
// upon successfully entering a gamemode it set the
// gamemode in game data
void gameModeSelect() {
  bool valid = false;
  printStart();
  do {
    char input;
    if(!(cin >> input)) exit(0);
    switch (input) {
      case 'P':
        valid = true;
        gameData.gameMode = NORMAL;
        break;
      case 'R':
        cout << "Feature not yet implemented\n" << flush;
        gameData.gameMode = REPLAY;
        sleep_for(seconds(1));
        exit(1);
        break;
      case 'S':
        gameData.gameMode = STATS;
        cout << "Feature not yet implemented\n" << flush;
        sleep_for(seconds(1));
        exit(1);
        break;
      case 'Q':
        exit(0);
      case EOF:
        exit(0);
      default:
        cout << "Invalid input, enter again\n" << flush;
        sleep_for(seconds(1));
    }
  } while (!valid);
}

// Starts the game in its intended mode
void gameStart() {
  switch (gameData.gameMode) {
    case NORMAL:
      setupBoard();
      runGameNormal();
      break;
    case REPLAY:
      runGameReplay();
      break;
    case STATS:
      runGameStats();
    default:
      cout << "Error no game mode\n" << flush;
  }
}

// Sets up the chess board
void setupBoard() {
  initBoard();
  placePieces();
  initSideBar();
}

void placePieces() {
  placePawns();
  placeBishops();
  placeKnights();
  placeRooks();
  placeQueens();
  placeKings();
}

void placePawns() {
  for (int col = 0; col < COLS; col++) {
    gameData.board[BLACK_PAWN_ROW][col].piece = PAWN;
    gameData.board[BLACK_PAWN_ROW][col].colour = BLACK;

    gameData.board[WHITE_PAWN_ROW][col].piece = PAWN;
    gameData.board[WHITE_PAWN_ROW][col].colour = WHITE;
  }
}

void placeBishops() {
  gameData.board[WHITE_KING_ROW][BISHOP_LEFT_COL].piece = BISHOP;
  gameData.board[WHITE_KING_ROW][BISHOP_LEFT_COL].colour = WHITE;

  gameData.board[WHITE_KING_ROW][BISHOP_RIGHT_COL].piece = BISHOP;
  gameData.board[WHITE_KING_ROW][BISHOP_RIGHT_COL].colour = WHITE;

  gameData.board[BLACK_KING_ROW][BISHOP_LEFT_COL].piece = BISHOP;
  gameData.board[BLACK_KING_ROW][BISHOP_LEFT_COL].colour = BLACK;

  gameData.board[BLACK_KING_ROW][BISHOP_RIGHT_COL].piece = BISHOP;
  gameData.board[BLACK_KING_ROW][BISHOP_RIGHT_COL].colour = BLACK;
}

void placeKnights() {
  gameData.board[WHITE_KING_ROW][KNIGHT_LEFT_COL].piece = KNIGHT;
  gameData.board[WHITE_KING_ROW][KNIGHT_LEFT_COL].colour = WHITE;

  gameData.board[WHITE_KING_ROW][KNIGHT_RIGHT_COL].piece = KNIGHT;
  gameData.board[WHITE_KING_ROW][KNIGHT_RIGHT_COL].colour = WHITE;

  gameData.board[BLACK_KING_ROW][KNIGHT_LEFT_COL].piece = KNIGHT;
  gameData.board[BLACK_KING_ROW][KNIGHT_LEFT_COL].colour = BLACK;

  gameData.board[BLACK_KING_ROW][KNIGHT_RIGHT_COL].piece = KNIGHT;
  gameData.board[BLACK_KING_ROW][KNIGHT_RIGHT_COL].colour = BLACK;
}

void placeRooks() {
  gameData.board[WHITE_KING_ROW][ROOK_LEFT_COL].piece = ROOK;
  gameData.board[WHITE_KING_ROW][ROOK_LEFT_COL].colour = WHITE;

  gameData.board[WHITE_KING_ROW][ROOK_RIGHT_COL].piece = ROOK;
  gameData.board[WHITE_KING_ROW][ROOK_RIGHT_COL].colour = WHITE;

  gameData.board[BLACK_KING_ROW][ROOK_LEFT_COL].piece = ROOK;
  gameData.board[BLACK_KING_ROW][ROOK_LEFT_COL].colour = BLACK;

  gameData.board[BLACK_KING_ROW][ROOK_RIGHT_COL].piece = ROOK;
  gameData.board[BLACK_KING_ROW][ROOK_RIGHT_COL].colour = BLACK;
}

void placeQueens() {
  gameData.board[WHITE_KING_ROW][QUEEN_COL].piece = QUEEN;
  gameData.board[WHITE_KING_ROW][QUEEN_COL].colour = WHITE;

  gameData.board[BLACK_KING_ROW][QUEEN_COL].piece = QUEEN;
  gameData.board[BLACK_KING_ROW][QUEEN_COL].colour = BLACK;
}

void placeKings() {
  gameData.board[WHITE_KING_ROW][KING_COL].piece = KING;
  gameData.board[WHITE_KING_ROW][KING_COL].colour = WHITE;

  gameData.board[BLACK_KING_ROW][KING_COL].piece = KING;
  gameData.board[BLACK_KING_ROW][KING_COL].colour = BLACK;
}

