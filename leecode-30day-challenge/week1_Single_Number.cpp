/*
   问题描述：找到序列中unique的数值
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        int min_num = *min_element(nums.begin(), nums.end());
        bool neg_flag = false;
        if (min_num < 0) {
            max_num += (-min_num);
            neg_flag = true;
        }
        int single = -1;
        int *arr = new int[max_num+1];
        for (int i = 0; i <= max_num; i++)
            arr[i] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (neg_flag)
                arr[nums[i] + (-min_num)] ++;
            else 
                arr[nums[i]] ++;
        }
        for (int i = 0; i <= max_num; i++) {
            if (arr[i] == 1) {
                if (neg_flag)
                    single = i + min_num;
                else 
                    single = i;
            }
           
        }
        return single;
    }
};

int main(int argc, char const *argv[]) {
    
    Solution sol;
    vector<int> nums;

    nums.push_back(-4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);

    cout << sol.singleNumber(nums) << endl;
    return 0;
}