#include <iostream>

using namespace std;

// 为了防止重复的计算，用一个数组来保存已经计算过的值
int num[50] = {0};
int fi(int k) {
    if (num[k]) return num[k];
    if (k == 1 || k == 2) {
        num[k] = 1;
        return 1;
    }
    else {
        num[k] = fi(k - 1) + fi(k - 2);
        return num[k];
    }
}


int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    cout << fi(k) << endl;
    return 0;
}