#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    long m;
    int k;
    cin >> m;
    cin >> skipws;
    cin >> k;
    int cnt = 0;
    int tmp = 0;
    if (m%19 == 0) {
        while (m!=0) {
            tmp = m%10;
            if (tmp == 3)
                cnt ++;
            m = m/10;
        }
        if (cnt == k) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}