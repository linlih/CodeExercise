#include <iostream>

using namespace std;

bool contain(int num) {
    int i = num%10;
    int j = num/10;
    while (j!=0) {
        if (i == 7) {
            return true;
        }
        else {
            i = j%10;
            j = j/10;
        }
    }
    if (i == 7) {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    long sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i%7 == 0) {
            continue;
        }
        else {
            if (contain(i)) {
                continue;
            }
            else {
                sum+=(i*i);
            }
        }
    }
    cout << sum << endl;
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int n, a, b, c, sum = 0;
//     scanf("%d", &n);
//     for (int i = n; i > 0; i--)
//     {
//         a = i % 10;
//         b = i / 10;
//         c = i % 7;
//         if (a != 7 && b != 7 && c != 0) {
//             sum += i * i;
//         }
//         else {
//             printf("%d ", i);
//         }
//     }
//     printf(" %d\n", sum);
//     return 0;
// }