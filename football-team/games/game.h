#include <vector>
#include "players/player.h"

class Game
{
public:
    double vectorTemp1, vectorTemp2 = 150.0; // these are the varriebles for finding the nearest player from ball
    Ball ball1;
    Player *nearestPlayer = NULL;
    std::vector<Player> players;

    Game();
    void printState() const;
    void putBall();                  // tell program where do u want to put your ball
    void play();                     // players do their stuff
    void nearestPlayerFromTheBall(); // finding nearest player from ball
};