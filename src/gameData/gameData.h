#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ROWS = 8;
const int COLS = 8;
const int PAGE_ROWS = 15;
const int PAGE_WIDTH = 31;
const int MISC_PAGE_ROWS = 2;
const int TURN_PAGE_LEFT = -1;
const int TURN_PAGE_RIGHT = 1;
const int FIRST_MISC_ROW = 0;
const int SECOND_MISC_ROW = 1;
const int INDEX_OFFSET = 1;

const string INVALID_PIECE = "Invalid piece selected";
const string INVALID_ERROR_MESSAGE = "Invalid message size";
const string ERROR_TEST = "This is a test for errors";

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
    int pageIndex;
    int capacity = 0;
    int maxCapacity = PAGE_ROWS * PAGE_WIDTH;
    char content[PAGE_ROWS][PAGE_WIDTH];
};

class sideBar {
  public:
    int currentPageIndex;
    vector<class sideBarPage> pages;
    bool hasError = true;
    char errorContent[PAGE_WIDTH];
    char miscContent[MISC_PAGE_ROWS][PAGE_WIDTH];
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
int newSideBarPage();
void initSideBarPageContent(class sideBarPage *page);
void turnSideBarPage(char direction);
void doTurnSideBarPage(int offset);
void turnSideBarPage(char direction);
void doTurnSideBarPage(int offset);
void appendToSideBar(string input);
void dumpCurrentSideBarContent();
void addErrorMessage(string input);
void initMiscContent();
void appendToMiscContentRow(int row, string input);
void appendBackMiscContentRow(int row, string input);
string pageStatusToString();
void dumpMiscContent();