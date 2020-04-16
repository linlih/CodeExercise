/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& arr) {
        int max_num = *max_element(arr.begin(), arr.end());
        vector<int> cnt(max_num+2, 0); // 假设最大值为4，那么数组的大小要为5，因为下标是从0开始，同时下面还要判断+1，所以这里的大小要+2

        for (int i = 0; i < arr.size(); i++) 
            cnt[arr[i]] += 1;

        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (cnt[arr[i] + 1] != 0)
                count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> arr;
    
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    cout << sol.countElements(arr) << endl;
    return 0;
}