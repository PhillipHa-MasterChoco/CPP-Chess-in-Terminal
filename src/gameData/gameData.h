const int ROWS = 8;
const int COLS = 8;
const int PAGE_ROWS = 8;
const int PAGE_WIDTH = 8;

extern class gameData gameData;

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
    char content[PAGE_ROWS][PAGE_WIDTH];
    class sideBarPage *next;
    class sideBarPage *prev;
}

class sideBar {
  public:
    class sideBarPage *currentPage;
}

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
}

class gameData
{
public:
  enum GameMode gameMode;
  enum Colour currentTurn;
  class gridTile board[ROWS][COLS];
};

void initBoard();