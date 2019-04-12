#include <bits/stdc++.h>
#include <iostream>
#include<stdio.h>
#include <iomanip>

using namespace std;
int main() {
    double A1, A2, A3, A4, A5;
    A1 = A2 = A3 = A4 = A5 = 0;
    long a;
    int i = 0;
    int cnt_a4 = 0;
    long max_a5 = 0;
    char c;
    while ((c=getchar())!='\n') {
        cin >> a;
        if (a%5 == 0 && a%2 == 0)
            A1+=a;
        if (a%5 == 1) {
            if (i%2==0)
                A2 += a;
            else
                A2 -= a;
            i++;
        }
        if (a%5 == 2)
            A3 ++;
        if (a%5 == 3) {
            A4 += a;
            cnt_a4 ++;
        }
        if (a%5 == 4) {
            if (A5 < a)
                A5 = a;
        }
    }
    if (A1 == 0)
        cout << "N ";
    else
        cout << A1 << " ";
    if (A2 == 0)
        cout << "N ";
    else
        cout << A2 << " ";
    if (A3 == 0)
        cout << "N ";
    else
        cout << A3 << " ";
    if (A4 == 0)
        cout << "N ";
    else
        cout << setprecision(1) << fixed << (A4*1.0)/cnt_a4 << " ";
    if (A5 == 0)
        cout << "N";
    else
        cout << setprecision(0) << fixed << A5;
    cout << endl;
    return 0;
}