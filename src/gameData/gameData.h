const int ROWS = 8;
const int COLS = 8;

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

class gridTile
{
public:
  enum Pieces piece;
  enum Colour colour;
  bool threatened;
};

class gameData
{
public:
  enum GameMode gameMode;
  enum Colour currentTurn;
  class gridTile board[ROWS][COLS];
};

void initBoard();