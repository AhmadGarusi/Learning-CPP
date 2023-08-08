#include <iostream>
using namespace std;

int main()
{
    int x, *p1, *p2;
    float y;
    x = 1350;
    y = 1460.1356;
    p1 = &x;
    p2 = &y;
    cout << "x = " << x << " y = " << y << endl;
    cout << "p1 = " << p1 << " *p1" << *p1 << " p2 = " << p2 << " *p2 = " << *p2;
}