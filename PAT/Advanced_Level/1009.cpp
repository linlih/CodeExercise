/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

typedef struct num{
    int exp;
    float coef;
}num;

int main(int argc, char const *argv[])
{
    int cnt_a, cnt_b;
    float cal[1001] = {0};
    int tmp_i;
    float tmp_n;
    
    scanf("%d", &cnt_a);
    num *a = new num[cnt_a];
    for (int i = 0; i < cnt_a; ++i) {
        scanf("%d %f", &a[i].exp, &a[i].coef);
    }

    scanf("%d", &cnt_b);
    num *b = new num[cnt_b];
    for (int i = 0; i < cnt_b; ++i) {
        scanf("%d %f", &b[i].exp, &b[i].coef);
    }

    num *res = new num[cnt_a + cnt_b];
    int res_i = 0;
    for (int i = 0; i < cnt_a; ++i) {
        for (int j = 0; j < cnt_b; ++j) {
            res[a[i].exp + b[j].exp].coef += a[i].coef * b[j].coef;
            res_i++;
        }
    }
    int cnt = res_i - 1;
    cout << cnt;
    for (int i = cnt; i > 0; --i) {
        if (res[i].coef > 0)
            printf(" %d %.1f", i, res[i].coef);
    }
    return 0;
}