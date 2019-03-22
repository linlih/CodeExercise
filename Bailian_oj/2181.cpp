
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[151000][2];
int maxd(int a,int b)
{
    return a<b?b:a;
}
int main()
{
    int n,i,t;
    while (scanf("%d",&n) != EOF)
    {
        dp[0][0]=0;
        dp[0][1]=0;
        for (i=1; i<=n; i++)
        {
            scanf("%d",&t);
            dp[i][0]=maxd(dp[i-1][0],dp[i-1][1]-t);
            dp[i][1]=maxd(dp[i-1][1],dp[i-1][0]+t);
        }
        printf("%d\n",maxd(dp[n][0],dp[n][1]));
    }

}