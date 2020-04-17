/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

class Solution { 
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end(), cmp);
            int res = stones[0] - stones[1];
            if (res != 0) {
                // stones.erase(stones.begin(), stones.begin() +1);
                stones.erase(stones.begin());
                stones.erase(stones.begin());
                stones.push_back(res);
            } else {
                //stones.erase(stones.begin(), stones.begin() +1);
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            }
            // for (int i = 0; i < stones.size(); i++)
            //     cout << stones[i] << " ";
            // cout << endl;
        }
        if (stones.size() != 0)
            return stones[0];
        else
            return 0;
    }
};

// 利用堆，make_heap默认为最大堆
class Solution_Best {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while(stones.size()) {
            int n = stones.size();
            if (n == 1) 
                return stones.front();
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if (x > y) {
                stones.push_back(x - y);
                push_heap(stones.begin(), stones.end());
            }
            else if (y > x) {
                stones.push_back(y-x);
                push_heap(stones.begin(), stones.end());
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> stones;

    stones.push_back(2);
    stones.push_back(7);
    stones.push_back(4);
    stones.push_back(1);
    stones.push_back(8);
    stones.push_back(1);

    // stones.push_back(2);
    // stones.push_back(2);
    
    cout << sol.lastStoneWeight(stones) << endl;
    return 0;
}