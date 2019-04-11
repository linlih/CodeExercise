/*
 * 运行数据：4 ms 496 KB
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    string A, B;
    char DA, DB;
    cin >> A >> DA >> B >> DB;
    int a = 0;
    int b = 0;
    int a_i = 1;
    int b_i = 1;
    for (int i = 0; i < A.length(); ++i) {
        if (A[i] == DA) {
            a += ((int)(DA - '0'))*a_i;
            a_i *= 10;
        }
    }
    for (int i = 0; i < B.length(); ++i) {
        if (B[i] == DB) {
            b += ((int)(DB - '0'))*b_i;
            b_i *= 10;
        }
    }
    cout << a+b << endl;
    return 0;
}