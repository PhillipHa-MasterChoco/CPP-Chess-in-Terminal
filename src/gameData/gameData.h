#include <iostream>
#include <string>

const int ROWS = 8;
const int COLS = 8;
const int PAGE_ROWS = 8;
const int PAGE_WIDTH = 30;

extern class gameData gameData;
extern class sideBar sideBar;

using namespace std;

enum Pieces
{
  PAWN,
  BISHOP,
  KNIGHT,
  ROOK,
  QUEEN,
  KING,
  NONE
};

enum Colour {
  WHITE,
  BLACK,
  EMPTY
};

enum GameMode
{
  NORMAL,
  REPLAY,
  STATS,
  NO_GAME_MODE
};

class sideBarPage {
  public:
    int pageNumber;
    int capacity = 0;
    int maxCapacity = PAGE_ROWS * PAGE_WIDTH;
    char content[PAGE_ROWS][PAGE_WIDTH];
    class sideBarPage *next = nullptr;
    class sideBarPage *prev = nullptr;
};

class sideBar {
  public:
    int numberOfPages;
    class sideBarPage *currentPage = nullptr;
    class sideBarPage *lastPage = nullptr;
};

class gridTile
{
public:
  enum Pieces piece;
  enum Colour colour;
  bool threatened;
};

class userOut {
  public:
    bool needed = false;
    string output;
};

class gameData
{
public:
  enum GameMode gameMode;
  enum Colour currentTurn;
  class gridTile board[ROWS][COLS];
};

void initBoard();
void initSideBar();
class sideBarPage *newSideBarPage();
void turnSideBarPage(char direction);
void doTurnSideBarPage(int offset);
void initialiseSideBarPage(class sideBarPage *page);
void turnSideBarPage(char direction);
void doTurnSideBarPage(int offset);
void appendToSideBar(string input);
void printCurrentSideBarContent();