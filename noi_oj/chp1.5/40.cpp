#include <iostream>

using namespace std;

int contain(int num, int flag) {
    int i = num%10;
    int j = num/10;
    int cnt = 0;
    while (j!=0) {
        if (i == flag) {
            cnt++;
        }
        i = j%10;
        j = j/10;
    }
    if (i == flag) {
        cnt++;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += contain(i, 1);
    }
    cout << cnt << endl;
    return 0;
}