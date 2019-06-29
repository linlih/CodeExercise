/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int main(int argc, char const *argv[])
{
    float cal[1001] = {0};
    int cnt_a, cnt_b;
    int exp;
    float coef;
    scanf("%d", &cnt_a);
    for (int i = 0; i < cnt_a; ++i) {
        scanf("%d%f", &exp, &coef);
        cal[exp] += coef;
    }
    scanf("%d", &cnt_b);
    for (int i = 0; i < cnt_b; ++i) {
        scanf("%d%f", &exp, &coef);
        cal[exp] += coef;
    }

    int total_exp = 0;
    for (int i = 0; i < 1001; ++i) {
        if (cal[i] != 0)
            total_exp ++;
    }
    
    printf("%d", total_exp);
    for (int i = 1000; i >= 0; --i) {
        if (cal[i] != 0) {
            printf(" %d %.1f", i, cal[i]);
        }
    }
    printf("\n");
    return 0;
}