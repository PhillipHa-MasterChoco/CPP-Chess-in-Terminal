#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "setupGame/setupGame.h"
#include "normalGame/normalGame.h"
#include "replayGame/replayGame.h"
#include "statsGame/statsGame.h"
#include "endGame/endGame.h"


int main() {
  gameSetup();
  gameStart();
  gameEnd();

  return 0;
}


