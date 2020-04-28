/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/4371526.html
/*
每个位置上的数字表示的是最大的跳力而不是像玩大富翁一样摇骰子摇出几一定要走几。这里可以用动态规划 Dynamic Programming 来解，维护一个一维数组 dp，其中 dp[i] 表示达到i位置时剩余的跳力，若到达某个位置时跳力为负了，说明无法到达该位置。接下来难点就是推导状态转移方程啦，想想啊，到达当前位置的剩余跳力跟什么有关呢，其实是跟上一个位置的剩余跳力（dp 值）和上一个位置新的跳力（nums 数组中的值）有关，这里新的跳力就是原数组中每个位置的数字，因为其代表了以当前位置为起点能到达的最远位置。所以当前位置的剩余跳力（dp 值）和当前位置新的跳力中的较大那个数决定了当前能到的最远距离，而下一个位置的剩余跳力（dp 值）就等于当前的这个较大值减去1，因为需要花一个跳力到达下一个位置，所以就有状态转移方程了：dp[i] = max(dp[i - 1], nums[i - 1]) - 1，如果当某一个时刻 dp 数组的值为负了，说明无法抵达当前位置，则直接返回 false，最后循环结束后直接返回 true 
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], nums[i-1]) - 1;
            if (dp[i]  < 0) return false;
        }
        return true;
    }
};

class Solution_1 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};

class Solution_Best {
public:
    bool canJump(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        int maxRight = 0;
        for (int i = 0; i < n; ++i){
            if (i > maxRight) return false;
            maxRight = ((i+nums[i])>maxRight)?(i+nums[i]):maxRight;            
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    cout << sol.canJump(nums) << endl;
    return 0;
}