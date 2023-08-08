#include <iostream>
#include <cstdlib>
#include <math.h>
#include "ball/ball.h"

#define PI 3.14159

class Player
{
private:
    int playerID;

public:
    int x, y;
    int angle, angleTemp, rotate;

    Player(int id);
    int getID() const
    {
        return playerID;
    }

    void playerRotate(Ball); // this function rotate the players so that the players facing the ball

    void print() const
    {
        cout << getID() << ": x = " << x << "\ty = " << y << "\tangle = " << angle << "\t" << rotate << " rotated";
    }

    double playerVector(Ball ball) // this function calculates the distance between player and ball
    {
        return sqrt((x - ball.x) * (x - ball.x) + (y - ball.y) * (y - ball.y));
    }
};