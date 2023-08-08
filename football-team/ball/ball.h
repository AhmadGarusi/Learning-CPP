#include <iostream>
using namespace std;

class Ball
{
public:
    int x, y;
    Ball()
    {
        x = 0;
        y = 0;
    }
    //..............................................................................................

    void put()
    {
        cout << "Enter x: ";
        cin >> x;

        cout << "Enter y: ";
        cin >> y;
    }
};