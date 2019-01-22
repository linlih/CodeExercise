#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int sum = 0;
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }

    cout << sum << " " << setprecision(5) << fixed << (sum * 1.0)/n << endl;
    return 0;
}