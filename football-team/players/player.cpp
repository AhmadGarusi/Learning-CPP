#include "players/player.h"

Player::Player(int id)
{
    playerID = id;
    x = rand() % (120 + 1);
    y = rand() % (90 + 1);
    angle = rand() % 360;
    rotate = 0;
}
//....................................................................................................

void Player::playerRotate(Ball ball)
{
    // final angle
    angleTemp = atan((double)(y - ball.y) / (double)(x - ball.x)) * 180 / PI;

    if (angleTemp < 0)
        angleTemp = 360 + angleTemp;

    rotate = angleTemp - angle;

    if (rotate > 180)
        rotate = 360 - rotate;

    else if (rotate < -180)
        rotate = 360 + rotate;

    if (angle + rotate != angleTemp)
        rotate = rotate * (-1);

    angle = angleTemp;
}
