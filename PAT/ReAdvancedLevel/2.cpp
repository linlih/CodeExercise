/*******************************************************************
  > File Name    : 2.cpp
  > Author       : linlh
  > Created  Time: 2021.03.29 21:17
  > Modified Time: 2021.03.29 21:58
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;

int main()
{
    int len = 2004;
    float res[len] = {0};
    memset(res, 0, len*sizeof(float)); // 这里的第三个参数是字节数，所以一定要记得乘以类型的大小

    int al, bl;
    cin >> al; 
    int tmp;
    float dat;
    for (int i = 0; i < al; ++i) {
        cin >> tmp >> dat;
        res[tmp] = dat;
    }
    cin >> bl;
    for (int i = 0; i < bl; ++i) {
        cin >> tmp >> dat;
        res[tmp] += dat;
    }
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (res[i] != 0) cnt ++;
    }
    cout << cnt ;
    for (int i = len-1; i >= 0; --i) {
        // 这里很重要的一点就是输出保留的小数位数，一定更要满足题目的要求
        if (res[i] != 0) 
            // cout的方式一开始不行的，需要在前面加上fixed才可以, TODO: check下原因
            // cout << " " << i << " "  << fixed << setprecision(1) << res[i]; 
            printf(" %d %.1f", i, res[i]);

    }
    return 0;
}
// 这道题柳姐的做法一致，就不在重复了
