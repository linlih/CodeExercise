/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// 参考比较正确的解法
class Solution {
public: 
    int sum(int num) {
        int sum = 0;
        while(num>0) {
            int digit = num % 10;
            num /= 10;
            sum = sum + ( digit * digit);
        }
        return sum;
    }
    
    bool isHappy(int n) {
        map<int, int> seen; // 创建一个序列记录计算结果
        int theSum = n;
        while(1) {
            theSum = sum(theSum);
            if (theSum == 1) {
                return true;
            }
            else {
                seen[theSum]++;
                if(seen[theSum] > 1) {
                    return false;
                }
            }
        }
    }
};
int main(int argc, char const *argv[]) {
    int  num;
    cin >> num;
    int tmp2 = -1;
    int tmp = num;
    int single;
    int res = 0;
    while (tmp2 != num || tmp2 < 1000) {
        while (tmp != 0) {
            single = tmp % 10;
            res += single * single;
            tmp = tmp / 10;
        }
        tmp2 = res;
        tmp = res;
        res = 0;
        if (tmp2 == 1) break;
        if (tmp2 == 145) break; // 这里做了一个取巧的判断，因为不是happy数的规律中会循环出现145
    }
    if (tmp2 == 1) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}