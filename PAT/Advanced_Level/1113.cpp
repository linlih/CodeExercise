/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> num;
    int temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    int mi = 0, ma = 0;
    if (num.size() % 2 == 0) {
        cout << "0 ";
        for (int i = 0; i < num.size()/2; ++i)
            mi += num[i];
        for (int i = num.size()/2; i < num.size(); ++i)
            ma += num[i];
    }
    else {
        cout << "1 ";
        for (int i = 0; i < num.size()/2; ++i)
            mi += num[i];
        for (int i = num.size()/2 ; i < num.size(); ++i)
            ma += num[i];
    }
    cout << (ma - mi) << endl;
    return 0;
}