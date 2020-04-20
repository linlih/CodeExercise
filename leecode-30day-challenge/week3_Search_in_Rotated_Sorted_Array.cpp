/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref : https://www.cnblogs.com/grandyang/p/4325648.html
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }

    int binary_search(vector<int>& nums, int s) {
        int i = 0;
        int j = nums.size() - 1;
        int ret = -1;
        while (i <= j) {
            int mid = (i + j)/2;
            if (nums[mid] > s) j = mid - 1;
            else if (nums[mid] < s) i = mid + 1;
            else {
                ret = i;
                break;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> nums;
    nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    cout << sol.search(nums, 3) << endl;
    return 0;
}