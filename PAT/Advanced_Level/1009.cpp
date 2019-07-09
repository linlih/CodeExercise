/*
   问题描述：
   解题思路： 
 */

#if 1 // 错误解法
#include <bits/stdc++.h>

using namespace std;

typedef struct num{
    int exp;
    double coef;
}num;

int main(int argc, char const *argv[])
{
    int cnt_a, cnt_b;
    //double cal[2001] = {0};
    
    scanf("%d", &cnt_a);
    num *a = new num[cnt_a];
    for (int i = 0; i < cnt_a; ++i) {
        scanf("%d %lf", &a[i].exp, &a[i].coef);
    }

    scanf("%d", &cnt_b);
    num *b = new num[cnt_b];
    for (int i = 0; i < cnt_b; ++i) {
        scanf("%d %lf", &b[i].exp, &b[i].coef);
    }

    num *res = new num[cnt_a + cnt_b + 1];
    int res_i = 0;
    for (int i = 0; i < cnt_a; ++i) {
        for (int j = 0; j < cnt_b; ++j) {
            res[a[i].exp + b[j].exp].coef += a[i].coef * b[j].coef;
            res_i++;
        }
    }
    int cnt = res_i - 1;
    cout << cnt;
    for (int i = cnt_a + cnt_b; i > 0; --i) {
        if (res[i].coef != 0)
            printf(" %d %.1f", i, res[i].coef);
    }
    return 0;
}
#else
#include <iostream>
using namespace std;
int main() {
    int n1, n2, a, cnt=0;
    double b, arr[1001] = {0.0}, ans[2001] = {0.0};

    scanf("%d", &n1);
    for (int i = 0; i < n1; ++i) {
        scanf("%d %lf", &a, &b);
        arr[a] = b;
    }
    
    scanf("%d", &n2);
    for (int i = 0; i < n2; ++i) {
        scanf("%d %lf", &a, &b);
        for (int j = 0; j < 1001; ++j) {
            ans[j + a] += arr[j] * b;
        } 
    }
    for (int i = 2000; i >= 0; i--) {
        if (ans[i] != 0.0) cnt ++;
    }
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--)
        if (ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    return 0;
}
#endif