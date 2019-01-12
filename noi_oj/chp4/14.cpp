#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int k;
    char pri;
    cin >> k >> pri;
    int total = 0;
    if (k <= 1000)
        total = 8;
    else if (k > 1000) {
        total = 8 + (int)((k - 1000) / 500) * 4;
        if ((k-1000)%500 != 0)
            total += 4;
    }
    
    if (pri == 'y')
        total += 5;
    
    cout << total << endl;
    return 0;
}