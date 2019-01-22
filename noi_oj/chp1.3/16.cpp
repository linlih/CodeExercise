#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    double xa, ya;
    double xb, yb;
    double distance;
    cin >> xa >> ya;
    cin >> xb >> yb;
    distance = (double)sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    cout << setprecision(3) << fixed << distance << endl;
    return 0;
}