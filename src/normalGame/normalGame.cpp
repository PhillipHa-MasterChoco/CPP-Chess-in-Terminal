#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "normalGame.h"
#include "../gameData/gameData.h"
#include "../setupGame/setupGame.h"
#include "../boardFunctions/boardFunctions.h"


using namespace std;
using namespace chrono;
using namespace this_thread;

void runGameNormal() {
    printGameBoard();
}