/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    int arr[40], index = 0;
    while(a != 0) {
        // 存储系数
        arr[index++] = a % b;
        a = a / b;
    }
    int flag = 0;
    // 判断是否对称
    for (int i = 0; i < index / 2; i++) {
        if (arr[i] != arr[index - i - 1]) {
            printf("No\n");
            flag = 1;
            break;
        }
    }
    if (!flag) printf("Yes\n");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i != 0) printf(" ");
    }
    if (index == 0)
        printf("0");
    return 0;
}