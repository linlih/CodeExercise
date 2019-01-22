// #include <iostream>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     char n;
//     int a;
//     cin >> n; 
//     a = n;
//     if (a % 2 == 0)
//         cout << "NO";
//     else
//         cout << "YES";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    char b;
    b = getchar();
    a = b;
    if (a % 2 == 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}

// cin方式没有办法读取空格，只能调用getchar或者用scanf
// 参考自：https://blog.csdn.net/u011982340/article/details/39100535


