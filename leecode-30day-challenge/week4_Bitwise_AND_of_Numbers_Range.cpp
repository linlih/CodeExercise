/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// 想法是可以，但是会超时，太多的for循环
class My_Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        char tmp1[100000] = {0};
        char tmp2[100000] = {0};
        int2bit(m, tmp1);
        // for (int i = 0; i < 20; i++)
        //     cout << (int)tmp1[i] << " ";
        // cout << endl;
        for (int i = m + 1; i <=n; i++) {
            int2bit(i, tmp2);
            // for (int i = 0; i < 20; i++)
            //     cout << (int)tmp1[i] << " ";
            // cout << endl;
            for (int j = 0; j < 20; j++) {
                if (tmp1[j] == 1 && tmp2[j] == 1)
                    tmp1[j] = 1;
                else
                    tmp1[j] = 0;
                tmp2[j] = 0;
            }
        }
        int res = 0;
        int index = 1;
        for (int i = 0; i < 20; i++) {
            res += tmp1[i]*index;
            index *= 2;
        }
        return res;
        //return 0;
    }
    void int2bit(int n, char res[20]) {
        int i = 0;
        while (n != 0) {
            res[i] = n % 2;
            n = n / 2;
            i++;
        }
    }
};

// ref: https://www.cnblogs.com/grandyang/p/4431646.html
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return (m << i);
    }
};

class Solution_Best {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {  // Remove the last bit 1 until n <= m.
            n &= n - 1;
        }
        return n;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    cout << sol.rangeBitwiseAnd(0, 1) << endl;
    return 0;
}
