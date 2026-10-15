#include <iostream>

using namespace std;

void printEnd()
{
    cout << "\033[2J\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|                  Thanks for playing!             |\n";
    cout << "+--------------------------------------------------+\n";
}

void gameEnd()
{
    // This function will later be used to store data once the game has ended
    // for now it will just call printEnd
    printEnd();
}