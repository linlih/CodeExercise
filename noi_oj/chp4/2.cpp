#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    float a;
    cin >> a;
    cout << setprecision(2) << fixed <<  abs(a) << endl;    
    return 0;
}