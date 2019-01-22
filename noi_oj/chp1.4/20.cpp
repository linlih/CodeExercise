#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/* 注意这道题中需要将-b写成(0-b)的形式
   因为当b = 0.0时，-b = -0.0,0 - b = 0.0,打印出来居然是不一样的
*/

int main(int argc, char const *argv[])
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;

    if (delta > 0)
        cout << setprecision(5) << fixed << "x1=" << ((0 - b) + sqrt(b*b-4*a*c))/(2*a) << ";x2=" << ((0 - b) - sqrt(b*b-4*a*c))/(2*a) << endl;
    else if (delta < 0) {
        cout << setprecision(5) << fixed << "x1=" << (0 - b) / (2*a) << "+" << sqrt(4*a*c-b*b) / (2*a) << "i;";
        cout << setprecision(5) << fixed << "x2=" << (0 - b) / (2*a) << "-" << sqrt(4*a*c-b*b) / (2*a) << "i" << endl;
    }
    else
        cout << setprecision(5) << fixed << "x1=x2=" << (0 - b) / (2*a) << endl;

    return 0;
}


