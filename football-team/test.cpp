#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    const double pi = 3.14159;
    int angleTemp;
    angleTemp = atan((double)(82 - 74) / (double)(50 - 61)) * 180 / pi;
    angleTemp = 360 + angleTemp;
    cout << angleTemp << endl;
}
