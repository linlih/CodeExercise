#include <cstdio>
#include <cstring>
const int N=11;
int chess[N][N],n,m,x0,y0,nm,ans=0;
int zf[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

void dfs(int step,int x,int y){
    if(step==nm){
        ans++;
    }else{
        for(int i=0;i<8;i++){
            int tempx = x + zf[i][0];
            int tempy = y + zf[i][1];
            if(tempx>=0&&tempx<n&&tempy>=0&&tempy<m&&chess[tempx][tempy]!=1){
                chess[tempx][tempy]=1;
                dfs(step+1,tempx,tempy);
                chess[tempx][tempy]=0;
            }
        }
    }
    
} 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(chess,0,sizeof(chess));
        scanf("%d%d%d%d",&n,&m,&x0,&y0);
        nm=n*m;
        ans=0;
        chess[x0][y0]=1;
        dfs(1,x0,y0);
        printf("%d\n",ans);
    } 
    
    return 0;
}