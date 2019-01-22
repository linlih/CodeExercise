#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    float price[10];
    price[0] = 28.9;
    price[1] = 32.7;
    price[2] = 45.6;
    price[3] = 78;
    price[4] = 35;
    price[5] = 86.2;
    price[6] = 27.8;
    price[7] = 43;
    price[8] = 56;
    price[9] = 65;
    int tmp;
    double sum = 0;

    for (int i = 0; i < 10; ++i) {
        cin >> tmp;
        cin >> skipws;
        sum += (tmp*price[i]);
    }

    cout << setprecision(1) << fixed << sum << endl;

    return 0;
}