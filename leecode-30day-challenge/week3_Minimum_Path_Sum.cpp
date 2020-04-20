/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<int> >dp;
        for (int i = 0; i < grid.size(); i++) {
            dp.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++)
                dp[i].push_back(0);
        }
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for (int j = 1; j < grid[i].size(); j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() -1];
    }
};

class Solution_Best {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0)
            return 0;
        int col = grid[0].size();
        int dp[rows][col];
        dp[0][0] = grid[0][0];
        for(int i=1;i<col;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int j=1;j<rows;j++)
        {
            dp[j][0]= dp[j-1][0] + grid[j][0];
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<col;j++)
            {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[rows-1][col-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<vector<int>> grid;
    for (int i = 0; i < 3; i++)
        grid.push_back(vector<int>());
    grid[0].push_back(1);
    grid[0].push_back(3);
    grid[0].push_back(1);
    grid[1].push_back(1);
    grid[1].push_back(5);
    grid[1].push_back(1);
    grid[2].push_back(4);
    grid[2].push_back(2);
    grid[2].push_back(1);
    cout << sol.minPathSum(grid) << endl;
    return 0;
}