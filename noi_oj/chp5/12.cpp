#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> skipws;
        if (temp == m)
            cnt ++;
    }
    cout << cnt << endl;
    return 0;
}