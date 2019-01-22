#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int t = 1;
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        sum += t;
        cnt ++;
        if (cnt == t) {
            ++t;
            cnt = 0;
        }
    }
    cout << sum << endl;
    return 0;
}