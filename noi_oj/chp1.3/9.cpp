#include <iostream>
#include <iomanip>

using namespace std;
#define PI 3.14159
int main(int argc, char const *argv[])
{
    double r;
    cin >> r;
    cout << setprecision(4) << fixed << 2*r << " " << 2*PI*r << " " << PI*r*r << endl; 
    return 0;
}