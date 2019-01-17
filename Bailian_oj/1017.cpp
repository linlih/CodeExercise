// #include <iostream>
// #include <cmath>
// #include <math.h>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     int a[6];
//     int sum = 0;
//     int flag = 0;
//     while (1) {
//         // 依次读入体积从1*1*h~6*6*h的产品数目
//         cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
//         for (int i = 0; i < 6; i++) {
//             if (a[i] != 0) {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0) {
//             break;
//         }

//         if (a[5] > 0) // 体积为6*6*h的产品一个就要占用一个箱子
//             sum+=a[5];
//         //cout << __LINE__ << " sum:" << sum << endl; 
        
//         if (a[4] > 0) { // 体积为5*5*h的占用箱子后只能再放入体积为1*1*h的产品, 共可以放11个
//             if (a[0] < a[4]*11)
//                 a[0] = 0;
//             else
//                 a[0] = a[0] - a[4]*11;
//             sum+=a[4];
//         }
//         //cout << __LINE__ << " sum:" << sum << endl; 

//         if (a[3] > 0) { // 体积为5*5*h的占用箱子后, 能再放入体积为1*1*h 20个和2*2*h 5个
//             if (a[1] < a[3]*5) {
//                 a[1] = 0;
//                 if (a[0] < (5 - a[1]%5)*4) // 1*1*h的体积用于填充体积为2*2*h未放满的地方
//                     a[0] = 0;
//                 else
//                     a[0] = a[0] - (5 - a[1]%5)*4;
//             }
//             else 
//                 a[1] = a[1] - a[3] * 5; // 剩下的2*2*h的产品
//             sum+=a[3];
//         }
//         //cout << __LINE__ << " sum:" << sum << endl; 

//         if (a[2] > 0) {
//             if (a[2]%4 == 1) { // 没有放满的话可以放5个2*2*h
//                 if (a[1] < 5) {
//                     if (a[0] < (36 - a[1]*4 - 9))
//                         a[0] = 0;
//                     else 
//                         a[0] = a[0] - (36 - a[1]*4 - 9);
//                     a[1] = 0;
//                 }
//                 else {
//                     //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//                     a[1] = a[1] - 5;
//                     if (a[0] < 7)
//                         a[0] = 0;
//                     else 
//                         a[0] = a[0] - 7;
//                 }
//             }
//             else if (a[2]%4 == 2) {
//                 if (a[1] < 2) {
//                     if (a[0] < (36 - a[1]*4 - 9 * 2))
//                         a[0] = 0;
//                     else 
//                         a[0] = a[0] - (36 - a[1]*4 - 9 * 2);
//                     a[1] = 0;
//                 }
//                 else {
//                     a[1] = a[1] - 2;
//                     if (a[0] < 10)
//                         a[0] = 0;
//                     else 
//                         a[0] = a[0] - 10;
//                 }
//             }
//             else if (a[2]%4 == 3) {
//                 if (a[1] < 1) {
//                     if (a[0] < 9)
//                         a[0] = 0;
//                     else 
//                         a[0] = a[0] - 9;
//                 }
//                 else {
//                     a[1] = a[1] - 1;
//                     if (a[0] < 5)
//                         a[0] = 0;
//                     else 
//                         a[0] = a[0] - 5;
//                 }
//             }
//             //cout << "sum:" << sum << endl; 
//             sum+= ceil(a[2]/4.0);
//             //cout << "sum " << sum << "a[2]/4.0 " <<  a[2]/4.0 <<endl;
//         }

//         if (a[1] > 0) {
//             if (a[0] < (36 - (4*a[1]%9)))
//                 a[0] = 0;
//             else
//                 a[0] = a[0] - (36 - (4*a[1]%9));
//             sum += ceil(a[1]/9.0);
//         }

//         if (a[0] > 0) {
//             sum += ceil(a[0]/36.0);
//         }
//         flag = 0;
//         cout << sum << endl;
//         sum = 0;
//     }


//     return 0;
// }

#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int N, a, b, c, d, e, f, y, x; // N用来存储需要的箱子数目, y用来存放2*2的空位数目, x用来存放1*1的空位数目
    int u[4] = {0, 5, 3, 1}; // 数组u表示3*3的产品数目分别是4的倍数, 4的倍数+1, 4的倍数+2, 4的倍数+3, 时
                             // 为3*3的产品打开的新箱子中剩余的2*2的空位个数

    while (1) {
        cin >> a >> b >> c >> d >> e >> f;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) break;
        N = f + e + d + (c + 3) / 4; // 这里有一个小技巧, (c+3)/4正好等于c除以4向上取整的结果
        y = 5 * d + u[c%4];
        if (b > y) N += (b - y + 8)/9;
        x = 36*N - 36*f - 25*e - 16*d - 9*c - 4*d;
        if (a > x) N += (a - x + 35)/36;
        printf("%d\n", N);
    }
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int a1, a2, a3, a4, a5, a6;
    while (cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6)
    {
        if (a1 + a2 + a3 + a4 + a5 + a6 == 0)
            break;
        int sp1 = 0, sp2 = 0;
        int sum = 0;
        sum += a6;
        sum += a5;
        sp1 += (11 * a5);
        sum += a4;
        sp2 += (5 * a4);
        sum += ((a3 + 3) / 4);
        switch (a3 % 4)
        {
        case 3:
            sp2 += 1, sp1 += 5;
            break;
        case 1:
            sp2 += 5, sp1 += 7;
            break;
        case 2:
            sp2 += 3, sp1 += 6;
            break;
        default:
            break;
        }
        if (a2 <= sp2 && a1 <= (4 * (sp2 - a2)) + sp1)
            cout << sum << endl;
        else if (a2 <= sp2 && a1 > (4 * (sp2 - a2)) + sp1)
        {
            a1 = a1 - 4 * (sp2 - a2) - sp1;
            sum += ((a1 + 26) / 27);
            cout << sum << endl;
        }
        else
        {
            a2 -= sp2;
            a1 -= sp1;
            sum = sum + (a2 + 8) / 9;
            if (a2 % 9 != 0)
                a1 = a1 - (9 - (a2 % 9)) * 4;
            if (a1 <= 0)
                cout << sum << endl;
            else
            {
                sum += ((a1 + 35) / 36);
                cout << sum << endl;
            }
        }
    }
    return 0;
}