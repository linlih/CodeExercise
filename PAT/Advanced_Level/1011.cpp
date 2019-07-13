/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    float res = 1;
    float a, b, c;

    for (int i = 0; i < 3; ++i) {
        cin >> a >> b >> c;
        float max = -1.0;
        char odds = ' ';
        if (max < a) {
            max = a;
            odds = 'W';
        }
        if (max < b) {
            max = b;
            odds = 'T';
        }
        if (max < c) {
            max = c;
            odds = 'L';
        }
        printf("%c ", odds);
        res *= max;
    }
    float bonus = 0;
    bonus = (res * 0.65 - 1) * 2;
    printf("%.2f", bonus);
    return 0;
}