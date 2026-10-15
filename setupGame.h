const int MAX_ROWS = 8;
const int MAX_COLUMNS = 8;

extern class gameData gameData;

enum Pieces {
  PAWN,
  BISHOP,
  KNIGHT,
  ROOK,
  QUEEN,
  KING
};

enum GameMode {
  NORMAL,
  REPLAY,
  STATS,
  NO_GAME_MODE
};

class gridTile {
public:
  enum Pieces piece;
  bool threatened;
};

class gameData {
  public:
    enum GameMode gameMode;
    class gridTile board[MAX_ROWS][MAX_COLUMNS];
};


// ======================================
// =========== Iteration 0 ==============
// ======================================
void gameSetup();
void printStart();
void printEnd();
void gameEnd();
void gameStart();