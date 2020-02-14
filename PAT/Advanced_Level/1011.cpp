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


#include <bits/stdc++.h>

using namespace std;

int main(int argc, char*argv[]) {
    char c[4] = {'WTL'};
    double ans = 1.0;
    for (int i = 0; i < 3; i++) {
        double maxvalue = 0.0;
        int maxchar = 0;
        for (int j = 0; j < 3; j++) {
            double temp;
            scanf("%lf", &temp);
            if (maxvalue <= temp) {
                maxvalue = temp;
                maxchar = j;
            }
        }
        ans *= maxvalue;
        printf("%c ", c[maxchar]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2)

    return 0;
}
