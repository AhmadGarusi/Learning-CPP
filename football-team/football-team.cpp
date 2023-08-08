#include <iostream>
#include <vector>
#include <thread>
#include "games/game.h"

using namespace std;

int main()
{
    srand(std::clock());
    Game game1;
    game1.putBall(x, y);
    game1.play();
    game1.printState();
}
