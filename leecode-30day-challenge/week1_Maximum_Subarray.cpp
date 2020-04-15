/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res;
        dp[0] = nums[0];
        res = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            if (dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};

class Solution_best {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int localmax = 0;
        int globalmax = INT_MIN;

        for (int i = 0; i < n; i++) {
            localmax = max(nums[i], nums[i] + localmax);
            if (localmax > globalmax) {
                globalmax = localmax;
            }
        }
        return globalmax;
    }
}

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}