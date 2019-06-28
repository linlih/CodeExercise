/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int cnt[10] = {0};
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        cnt[str[i]-'0']++;
    }
    for (int j = 0; j < 10; ++j) {
        if (cnt[j] != 0)
            cout << j << ":" << cnt[j] << endl;
    }
    return 0;
}