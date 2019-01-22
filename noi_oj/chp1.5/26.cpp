#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string str;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        cin >> skipws;
        if ((str[3] - (str[0] + str[1] + str[2] - 2*'0'))  > 0)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}