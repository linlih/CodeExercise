#if 0
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int cnt = 0;
    int cnt_o = 0;
    int flag = 0;
    for (long i = 2; i < LONG_MAX; ++i) {
        for (long j = 2; j < i; j ++)
            if (i % j == 0)
                flag = 1;
        if (!flag) {
            cnt++;
            if (cnt >= m) {
                cnt_o ++;
                cout << i;
            }
            if (cnt_o!= 0 && cnt_o%10 == 0 ) {
                cout << endl;
            }
            else if (cnt_o!= 0 && cnt != n)
                cout << " ";
            if (cnt == n) {
                if (cnt_o%10 != 0)
                    cout << endl;
                //cout  << "time = " << clock() << " ms" << endl;
                return 0;
            }
        }
        flag = 0;
    }
    return 0;
}
#else

/*
 * 运行数据：308 ms	852 KB
 */
#include <bits/stdc++.h>
#include <limits.h>
#include <math.h>

using namespace std;

int arr[1000000] = {0}; // 数组要够大，否则会出现段错误

int main() {
    int m, n;
    cin >> m >> n;
    int cnt = 0;
    int cnt_o = 0;
    int flag = 0;
    for (long i = 2; i < LONG_MAX; ++i) {
        if (arr[i])
            continue;
        // for (long j = 2; j < i; j ++)
        for (long j = 2; j <= sqrt(i); j ++) // 只需要判断到根号的大小就可以，这样可以解决超时的问题
            if (i % j == 0)
                arr[i] = 1;
        if (!arr[i]) {
            cnt++;
            if (cnt >= m) {
                cnt_o ++;
                cout << i;
            }
            if (cnt_o!= 0 && cnt_o%10 == 0 ) {
                cout << endl;
            }
            else if (cnt_o!= 0 && cnt != n)
                cout << " ";
            if (cnt == n) {
                if (cnt_o%10 != 0)
                    cout << endl;
                //cout  << "time = " << clock() << " ms" << endl;
                return 0;
            }
        }
        flag = 0;
    }
    return 0;
}
#endif

