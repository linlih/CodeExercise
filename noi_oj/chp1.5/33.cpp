#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i%2 == 0)
            sum -= ((1.0*1)/i);
        else 
            sum += ((1.0*1)/i);            
    }

    cout << setprecision(4) << fixed << sum << endl;
    return 0;
}