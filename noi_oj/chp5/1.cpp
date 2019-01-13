#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int temp;
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << setprecision(2) << fixed << sum/(float)(n) << endl;
    return 0;
}