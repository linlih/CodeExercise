/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/4650187.html
// 思想是知道当前数字前后的乘积，根据这两个的乘积可以得到结果
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] * nums[i - 1]; // 计算当前数字左边的乘积
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right; // 乘以右边的乘积
            right *= nums[i];
        }
        return res;
    }
};

// 思想是一致的，只不过这里是先计算右边的乘积
class Solution_Best {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> output = nums;
        for (int i = 1; i < N; i++) {
            output[i] *= output[i-1];
        }
        int suffix = 1;
        for (int i = N-1; i>0; --i) {
            output[i] = output[i - 1] * suffix;
            suffix*=nums[i];
        }
        output[0] = suffix;
        return output;
    }
}

int main(int argc, char const *argv[]) {

    return 0;
}