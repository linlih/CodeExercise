#include <iostream>
#include <tgmath.h>

using namespace std;

#define WATER 20000.0
#define PI 3.14159

int main(int argc, char const *argv[])
{
    int h, r;
    cin >> h >> r;
    double tank;
    tank = (double)PI*r*r*h;
    cout << ((int)(WATER/tank) + 1) << endl;
    return 0;
}