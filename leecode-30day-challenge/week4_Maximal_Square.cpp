/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// ref: https://www.cnblogs.com/grandyang/p/4550604.html
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> v(matrix[i].size(), 0);
            for (int j = i; j < matrix.size(); j++) {
                for (int k = 0; k < matrix[j].size(); ++k) {
                    if (matrix[j][k] == '1') ++v[k];
                }
                res = max(res, getSquareArea(v, j - i + 1));
            }
        }
        return res;
    }
    int getSquareArea(vector<int>& v, int k) {
        if (v.size() < k) return 0;
        int count = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != k) count = 0;
            else ++count;
            if (count == k) return k * k;
        }
        return 0;
    }
};

static int z = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution_Best {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int i,j,k,l=0,m,n;
        n=matrix.size();
        m=matrix[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(i=0;i<=n;i++) {
            for(j=0;j<=m;j++) {
                if(i==0||j==0)
                    dp[i][j]=0;
                else {
                    if(matrix[i-1][j-1]=='1') {
                       // cout<<i<<" "<<j<<endl;
                        dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                        l=max(l,dp[i][j]);
                    }
                }
            }
        }
        return l*l;       
    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}