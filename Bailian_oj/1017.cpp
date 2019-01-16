#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int a[6];
    int sum = 0;
    int flag = 0;
    while (1) {
        // 依次读入体积从1*1*h~6*6*h的产品数目
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        for (int i = 0; i < 6; i++) {
            if (a[i] != 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
        if (a[5] != 0) // 体积为6*6*h的产品一个就要占用一个箱子
            sum+=a[5];
        if (a[4] != 0) { // 体积为5*5*h的占用箱子后只能再放入体积为1*1*h的产品, 共可以放11个
            if (a[0] < a[4]*11)
                a[0] = 0;
            else
                a[0] = a[0] - a[4]*11;
            sum+=a[4];
        }
        if (a[3] != 0) { // 体积为5*5*h的占用箱子后, 能再放入体积为1*1*h 20个和2*2*h 5个
            if (a[1] < a[3]*5) {
                a[1] = 0;
                if (a[0] < (5 - a[1]%5)*4) // 1*1*h的体积用于填充体积为2*2*h未放满的地方
                    a[0] = 0;
                else
                    a[0] = a[0] - (5 - a[1]%5)*4;
            }
            else 
                a[1] = a[1] - a[3] * 5; // 剩下的2*2*h的产品
            sum+=a[3];
        }
        if (a[2]!=0) {
            if (a[2]%4 == 1) { // 没有放满的话可以放4个2*2*h
                if (a[1] < 5) {
                    if (a[0] < (36 - a[1]*4 - 9))
                        a[0] = 0;
                    else 
                        a[0] = a[0] - (36 - a[1]*4 - 9);
                    a[1] = 0;
                    cout << __FUNCTION__ << ":" << __LINE__ << endl;
                }
                else {
                    a[1] = a[1] - 5;
                    if (a[0] < 11)
                        a[0] = 0;
                    else 
                        a[0] = a[0] - 11;
                }
            }
            else if (a[2]%4 == 2) {
                if (a[1] < 2) {
                    if (a[0] < (36 - a[1]*4 - 9 * 2))
                        a[0] = 0;
                    else 
                        a[0] = a[0] - (36 - a[1]*4 - 9 * 2);
                    a[1] = 0;
                }
                else {
                    a[1] = a[1] - 2;
                    if (a[0] < 10)
                        a[0] = 0;
                    else 
                        a[0] = a[0] - 10;
                }
            }
            else if (a[2]%4 == 3) {
                if (a[1] < 1) {
                    if (a[0] < 9)
                        a[0] = 0;
                    else 
                        a[0] = a[0] - 9;
                }
                else {
                    a[1] = a[1] - 1;
                    if (a[0] < 5)
                        a[0] = 0;
                    else 
                        a[0] = a[0] - 5;
                }
            }
            sum+= ceil(a[2]/4.0);
        }

        if (a[1]!=0) {
            if (a[0] < (36 - (4*a[1]%9)))
                a[0] = 0;
            else
                a[0] = a[0] - (36 - (4*a[1]%9));
            sum += ceil(a[1]/9.0);
        }

        if (a[0]!=0) {
            sum += ceil(a[0]/36.0);
        }
        flag = 0;
        cout << sum << endl;
    }


    return 0;
}