#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    float total = 0;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp < 70) {
            total += 0.1;
        }
        else {
            while(tmp > 70) {
                total += 0.1;
                tmp -= 70;
            }
            total += 0.1;
        }
        tmp = 0;
    }
    cout << total << endl;
    return 0;
}