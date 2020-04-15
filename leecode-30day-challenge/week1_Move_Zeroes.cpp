/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// 这个方法可以，但是时间复杂度为O(n^2)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};

class Solution_Best {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int zeroPos = 0;
        for (int i = 0;  i < size; i++) {
            int val = nums[i];
            // 根据不等于的值来进行交换，这样只需要O(n)的复杂度
            if (val != 0)
                swap(nums[zeroPos++],nums[i]);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> nums;
    
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);

    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}