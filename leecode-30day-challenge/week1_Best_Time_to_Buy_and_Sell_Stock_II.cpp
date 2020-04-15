/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        for (int i = 0; i < n - 1; ++i) {
            if (prices[i] < prices[i + 1]) { // 这个解法可以accept，但是有点奇怪，如果是1，2，3，4，5，那第一天买，第二天卖的同时又买，不是不符合题意
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};

class Solution_Best {
public: 
    //[7,1,5,3,6,4]
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        
        for(int i = 0 ; i < n-1 ; i++){
            int j = i;
            while(i+1 < n && prices[i] < prices[i+1]){ // 找到后一天价格跌落前的最高价格
                i++;
            }
            profit += prices[i] - prices[j];
        }
        
        return profit;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> nums;
    
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(4);

    cout << sol.maxProfit(nums) << endl;

    return 0;
}