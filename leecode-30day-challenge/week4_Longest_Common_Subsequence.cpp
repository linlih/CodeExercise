/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {        
        int m=text1.size();  
        int n=text2.size();
        int dp[m+1][1+n]; //dp table

        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=0;           //initializing the table when the empty string are compared with ant string--> then its 0 only always
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(text1[i-1]==text2[j-1]) //when char at cur index is same , we just check last highest value of matching subsequence till that index.
                    dp[i][j]=1+dp[i-1][j-1];
                else         // when the values of char at curr index is not rqual
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
};
int main(int argc, char const *argv[]) {
    
    return 0;
}