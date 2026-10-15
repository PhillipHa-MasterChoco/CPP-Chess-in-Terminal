#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "setupGame.h"
#include "normalGame.h"
#include "replayGame.h"
#include "statsGame.h"
#include "endGame.h"


int main() {
  gameSetup();
  gameStart();
  gameEnd();

  return 0;
}


