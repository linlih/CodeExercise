#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    double a;
    double b;
    cin >> a >> b;
    cout << setprecision(9) << fixed << a/b << endl;
    return 0;
}