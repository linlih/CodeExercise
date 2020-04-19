/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_num = 0;
        vector<vector<int> > mark;
        for (int i = 0; i < grid.size(); i++) {
            mark.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++)
                mark[i].push_back(0);
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (mark[i][j] == 0 && grid[i][j] == '1') {
                    DFS(mark, grid, i, j);
                    island_num++;
                }
            }
        }
        return island_num;
    }
    void DFS(vector<vector<int> >& mark, vector<vector<char> >& grid, int x, int y) {
        mark[x][y] = 1;
        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newx = dx[i] + x;
            int newy = dy[i] + y;
            if (newx < 0 || newx >= mark.size() ||
                newy < 0 || newy >= mark[newx].size()) {
                    continue;
                }
            if (mark[newx][newy] == 0 && grid[newx][newy] == '1')
                DFS(mark, grid, newx, newy);
        }
    }
};

// Best
static const auto _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    return 0;
}();
class UnionFind{
    int n,m;
    int* arr=NULL;
    int islands=0;
    int *size=NULL;
    public:
        int islandCount(){
            return islands;
        }
        UnionFind(vector<vector<char> > &grid){
            n=grid.size();
            m=grid[0].size();
            arr=new int[n*m];
            size=new int[n*m];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1'){
                        islands++;arr[i*m+j]=i*m+j;
                        size[i*m+j]=1;
                    }
                }
            }
        }
        int find(int value){
            while(value!=arr[value]){
                arr[value]=arr[arr[value]];
                value=arr[value];
            }
            return value;
        }   
        int isConnected(int p,int q){
            return find(p)==find(q);
        }
        void unite(int p,int q){
            int rp=find(p),rq=find(q);
            if(rp==rq)return;
            if(size[rp]<size[rq]){
                arr[rp]=rq;
                size[rq]+=size[rp];
            }else if(size[rq]<size[rp]){
                arr[rq]=rp;
                size[rp]+=size[rq];
            }else if(rp<rq){
                arr[rq]=rp;
                size[rp]+=size[rq];
            }else{
                arr[rp]=rq;
                size[rq]+=size[rp];
            }
            islands--;
        }
};
class Solution_Best {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();if(n==0)return 0;
        int m=grid[0].size();
        if(m==0)return 0;
        UnionFind uf=UnionFind(grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    int value=i*m+j;
                    int q;
                    if(i+1<n && grid[i+1][j]=='1'){
                        q=value+m;
                        uf.unite(value,q);
                    }
                    if(j+1<m && grid[i][j+1]=='1'){
                        q=value+1;
                        uf.unite(value,q);
                    }
                }
            }
        }
        return uf.islandCount();
    }
};
int main(int argc, char const *argv[]) {
    vector<vector<char> > grid;
    char str[10][10] = {"11100", "11000", "00100", "00011"};
    for (int i = 0; i < 4; i++) {
        grid.push_back(vector<char>());
        for (int j = 0; j < 5; j++) {
            grid[i].push_back(str[i][j]);
        }
    }
    Solution sol;
    printf("%d\n", sol.numIslands(grid));
    return 0;
}