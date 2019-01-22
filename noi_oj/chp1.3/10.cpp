#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    float r1, r2;
    cin >> r1 >> r2;
    cout << setprecision(2) << fixed << 1/(1/r1+1/r2) << endl;
    return 0;
}