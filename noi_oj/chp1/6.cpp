#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    char a;
    int b;
    float c;
    double d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << a << " " << b << " " << setprecision(6) << fixed << c << " " << setprecision(6) << fixed << d << endl;

    return 0;
}