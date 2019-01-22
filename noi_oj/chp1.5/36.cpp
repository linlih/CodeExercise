#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    float x;
    int n;
    cin >> x;
    cin >> skipws;
    cin >> n;
    double sum = 1;
    float temp = 1;
    for (int i = 1; i <= n; i++) {
        temp = temp*x;
        sum += temp;
    }   
    cout << setprecision(2) << fixed << sum << endl;
    return 0;
}