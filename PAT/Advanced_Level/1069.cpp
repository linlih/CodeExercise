/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

int tonum(string a) {
    int res = 0;
    // 默认情况下，从左到右的index依次增加，6677,所以实际的个位是从index最大的地方开始的
    for (int i = a.size() - 1; i >= 0; --i) {
        res += (a[i] - '0')*(pow(10, a.size() - 1 - i));
    }
    return res;
}

int main(int argc, char const *argv[]) {
    string num;
    cin >> num;
    sort(num.begin(), num.end()); 
    string num_r(num);
    reverse(num_r.begin(), num_r.end());
    while(num_r.size() < 4) // 这句话很重要，如果小于3位的话，补零的位置要在其后面补上，如果没补上会导致错误，比如说123，4位数表示为0123，反过来应该是3210，没补上0的话，结果是0321
        num_r.push_back('0');
    int res = -1;
    while(res != 0 && res !=  6174) {
        res = tonum(num_r) - tonum(num);
        //cout << tonum(num_r) << " - " << tonum(num) << " = " << res << endl;
        printf("%04d - %04d = %04d\n", tonum(num_r), tonum(num), res);
        num = to_string(res);
        sort(num.begin(), num.end());
        num_r = num;
        reverse(num_r.begin(), num_r.end());
        while(num_r.size() < 4)
        num_r.push_back('0');
    }
    // if (tonum(num_r) - tonum(num) == 0)
    //     cout << num_r << ' - ' << num << " = 0"  << endl;
    // else if (tonum(num_r) - tonum(num) == 6174)
    //     cout << num_r << ' - ' << num << " = 6174"  << endl;
    return 0;
}