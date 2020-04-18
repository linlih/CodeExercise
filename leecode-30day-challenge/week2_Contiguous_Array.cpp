/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// 题意理解错了，不是找到最长的上升或者下降的子序列，而是找到最长子序列中0和1的数目相同
class Solution_wrong {
public:
    int findMaxLength(vector<int>& nums) {
        int* dp_increase = new int[nums.size()];
        int* dp_decrease = new int[nums.size()];
        dp_increase[0] = 1;
        dp_decrease[0] = 1;
        int i_max = 1;
        int d_max = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp_increase[i] = 1;
            dp_decrease[i] = 1;
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp_increase[i] < dp_increase[j] + 1)
                    dp_increase[i] = dp_increase[j] + 1;
                
                if (nums[i] < nums[j] && dp_decrease[i] < dp_decrease[j] + 1)
                    dp_decrease[i] = dp_decrease[j] + 1;
            }
            if (i_max < dp_increase[i])
                i_max = dp_increase[i];
            if (d_max < dp_decrease[i])
                d_max = dp_decrease[i];
        }
        return max(i_max, d_max);
    }
};

// ref: https://www.cnblogs.com/grandyang/p/6529857.html
/*
这道题给了我们一个二进制的数组，让找邻近的子数组使其0和1的个数相等。
对于求子数组的问题，需要时刻记着求累积和是一种很犀利的工具，但是这里怎么将子数组的和跟0和1的个数之间产生联系呢？
这里需要用到一个 trick，遇到1就加1，遇到0，就减1，这样如果某个子数组和为0，就说明0和1的个数相等，这个想法真是太叼了，不过博主木有想出来。
知道了这一点，就用一个 HashMap 建立子数组之和跟结尾位置的坐标之间的映射。
如果某个子数组之和在 HashMap 里存在了，说明当前子数组减去 HashMap 中存的那个子数字，得到的结果是中间一段子数组之和，必然为0，说明0和1的个数相等，更新结果 res。
注意这里需要在 HashMap 初始化一个 0 -> -1 的映射，这是为了当 sum 第一次出现0的时候，即这个子数组是从原数组的起始位置开始，需要计算这个子数组的长度，而不是建立当前子数组之和 sum 和其结束位置之间的映射。
比如就拿例子1来说，nums = [0, 1]，当遍历0的时候，sum = -1，此时建立 -1 -> 0 的映射，当遍历到1的时候，此时 sum = 0 了，若 HashMap 中没有初始化一个 0 -> -1 的映射，此时会建立 0 -> 1 的映射，而不是去更新这个满足题意的子数组的长度，所以要这么初始化，参见代码如下：
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 1) ? 1: -1;
            if (m.count(sum))
                res = max(res, i - m[sum]);
            else 
                m[sum] = i;
        }
        return res;
    }
};

// 没看懂？
class Solution_Best {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int best = 0;
        const int NO_POS = -2;
        const int n = nums.size();
        vector ar_pos(n*2 + 2, NO_POS);
        int sum = 0;
        ar_pos[n+sum] = -1;
        for (int idx = 0; idx < n; idx++) {
            sum += (nums[idx] == 0?-1:1);
            int& pos(ar_pos[n+sum]);
            if (pos == NO_POS)
                pos=idx;
            else {
                int len = idx - pos;
                if (best < len) best = len;
            }
        }
        return best;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> nums;
    
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);

    cout << sol.findMaxLength(nums) << endl;
    return 0;
}