/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref : https://www.cnblogs.com/grandyang/p/4325648.html
/*
如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了，代码如下：
*/
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