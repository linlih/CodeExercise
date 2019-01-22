#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    float x, y;
    int num;
    float dis;
    cin >> n;
    float t = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> num;
        dis = sqrt(x*x + y*y);
        t += (dis/25 + num*1.5);
    }
    cout << ceil(t) <<  endl;
    return 0;
}