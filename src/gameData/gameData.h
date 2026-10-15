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
  bool threatened;
};

class gameData
{
public:
  enum GameMode gameMode;
  class gridTile board[ROWS][COLS];
};