/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int cnt[10] = {0};
    for (int i = 0; i < 10; ++i) {
        cin >> cnt[i];
        cin >> skipws;
    }

    // 输出首位
    int i = 1;
    while (cnt[i] == 0) {
        i++;
    }
    cout << i;
    cnt[i] --;

    for (int j = 0; j < 10; ++j) {
        if (cnt[j] != 0) {
            for (int k = 0; k < cnt[j]; ++k) {
                cout << j;
            }
        }
    }
    cout << endl;
    return 0;
}