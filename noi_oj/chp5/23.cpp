#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int total;
    int n;
    int temp;
    cin >> total;
    cin >> n;
    int i;
    int cnt = 0;
    for (i = 0; i < n; ++i) {
        cin >> temp;
        if (total - temp >=0) {
            total -= temp;
        }
        else
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}