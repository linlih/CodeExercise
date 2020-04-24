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
// 题目的要求是得到所有范围内数值的二进制数左边相同的部分
// 实现上就可以用给一个32位的MASK，每次移动一位，直到最后相等

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int d = INT_MAX; // 注意这里，leetcode是不支持int类型移位的，所以要改成unsigned
        while ((m & d) != (n & d)) {
            d <<= 1;
        }
        return m & d;
    }
};

// 这个实现思路和上面一致
class Solution_1 {
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

/*
如果n大于m，那么就对m和n分别除以2，并且调用递归函数，对结果再乘以2，一定要乘回来，不然就不对了，就举一个最简单的例子，m = 10, n = 11，注意这里是二进制表示的，然后各自除以2，都变成了1，调用递归返回1，这时候要乘以2，才能变回10，
*/
class Solution_2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    }
};


/*
如果m小于n就进行循环，n与上n-1，那么为什么要这样与呢，举个简单的例子呗，110与上(110-1)，得到100，这不就相当于去掉最低位的1么，n就这样每次去掉最低位的1，如果小于等于m了，返回此时的n即可
*/
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
    cout << sol.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
