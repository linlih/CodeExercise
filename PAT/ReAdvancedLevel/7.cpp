/*******************************************************************
  > File Name    : 7.cpp
  > Author       : linlh
  > Created  Time: 2021.03.31 15:05
  > Modified Time: 2021.03.31 16:15
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num[10010];
    fill(num, num + 10010, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    int idx = 0;
    int tmp = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (tmp > 0) {
            if (tmp + num[i] > 0) {
                tmp += num[i];
            }
            else {
                tmp = num[i];
            }
        }
        else {
            tmp = num[i];
        }
        if (max < tmp) {
            idx = i;
            max = tmp;
        }
    }
    int start = 0;
    for (int i = idx; i >= 0; --i)  {
        if (num[i] < 0) {
            start = i;
            break;
        }
    }
    if (num[start] < 0) start = start + 1;
    cout << max << " " << start << " " << idx  << endl;
    return 0;
}
