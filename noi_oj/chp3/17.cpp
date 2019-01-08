#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double distance(double xa, double ya, double xb, double yb) {
    return (double)sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
}

int main(int argc, char const *argv[])
{
    double x1,y1,x2,y2,x3,y3;
    double a, b, c, p;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    a = distance(x1, y1, x2, y2);
    b = distance(x1, y1, x3, y3);
    c = distance(x2, y2, x3, y3);
    p = (a + b + c)/2;
    cout << setprecision(2) << fixed << sqrt(p*(p-a)*(p-b)*(p-c)) << endl;
    return 0;
}