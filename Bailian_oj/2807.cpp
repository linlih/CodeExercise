#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a[100] = {0};
    int n;
    int cnt = 0;
    while(1) {
        cin >> n;
        if (n == 0)
            break;
        a[n] = 1;
    }
    for (int i = 0; i <= 50; i++) {
        if ((a[i] != 0) && a[2*i] != 0)
            cnt ++;
    }
    cout << cnt << endl;
    return 0;
}