#include "games/game.h"

using namespace std;

Game::Game()
{
    for (int i = 1; i <= 11; i++)
        players.push_back(Player(i));
}
//...................................................................................................................

void Game::printState() const
{
    for (const Player &i : players)
    {
        i.print();
        if (nearestPlayer == &i)
            cout << "\t (nearest)";
        cout << endl;
    }

    cout << "ball: x = " << ball1.x << "\ty =" << ball1.y << endl;
}
//.....................................................................................

void Game::play()
{
    for (Player &i : players)
        i.playerRotate(ball1);

    nearestPlayerFromTheBall();
}
//......................................................................................

void Game::putBall()
{
    cout << "where do you want to put your ball" << endl;
    ball1.put();
}
//....................................................................................

void Game::nearestPlayerFromTheBall()
{
    for (Player &i : players)
    {
        vectorTemp1 = i.playerVector(ball1);
        if (vectorTemp1 <= vectorTemp2)
        {
            nearestPlayer = &i;
            vectorTemp2 = vectorTemp1;
        }
    }
}
