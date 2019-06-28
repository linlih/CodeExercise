/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int N, p;
    cin >> N >> p;
    int *num = new int[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> num[i];
        cin >> skipws;
    }

    /*int M = num[0];
    int m = num[0];
    for (int i = 1; i < N; ++i) {
        if (num[i] > M) {
            M = num[i];
        }
        if (num[i] < m) {
            m = num[i];
        }
    }
    cout << M << " " << m << endl;*/

    sort(num, num + N); // 从小到大排列

    int m = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + m; j < N; j++) {
            if (num[j] > num[i] * p)
                break;
            m++;
        }
    }
    cout << m << endl;
    return 0;
}