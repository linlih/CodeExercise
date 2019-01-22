#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    double temp;
    double sum = 0;
    for (int i = 0; i < 12; i++) {
        cin >> temp;
        sum += temp;
    }

    cout << setprecision(2) << fixed << "$" << sum/12.0 << endl;

    return 0;
}