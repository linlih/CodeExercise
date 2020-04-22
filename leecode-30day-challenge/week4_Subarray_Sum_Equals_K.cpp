/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/6810361.html
// 暴力解法
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            if (sum == k) ++res;
            for (int j = i + 1; j < n; ++j) {
                sum += nums[j];
                if (sum == k) ++res;
            }
        }
        return res;
    }
};


class Solution_Best {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>h;
        h[0]++;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(h.count(sum-k))
                count+=h[sum-k];
            h[sum]++;
        }
        return count;
    }
};
int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout << sol.subarraySum(nums, 2) << endl;
    return 0;
}