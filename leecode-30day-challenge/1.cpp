/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int *visit;
    int t;
    int **arr;
    int cnt = 0;
    int size;
    int numWays(int n, vector<vector<int>>& relation, int k) {
        arr = new int*[n];
        visit = new int[n];
        size = n;
        for (int i = 0; i < n; i++) {
            visit[i] = 0;
            arr[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                arr[i][j] = 0;
        }
        for (int i = 0; i < relation.size(); i++) {
            arr[relation[i][0]][relation[i][1]] = 1;
            //arr[relation[i][1]][relation[i][0]] = 1;
        }
        t = k;

        dfs(n-1);
        // for (int m = 0; m < k; m++) {
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; i < n; j++) {
        //             if ()
        //         }
        //     }
        // }

        return cnt;
    }

    void dfs (int u){
        visit[u] = 1;
        if (u == t) {
            cnt++;
        }
        for (int i = 0; i < size; i++) {
            if (visit[i] == false && arr[u][i] == 1) {
                dfs(i);
            }
        }
    }

};

class Solution_1 {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        map<int, vector<int> rel;
        for (int i = 0; i < n; i++)
            rel.insert(make_pair(0, vector<int>()));
        for (int i = 0; i < relation.size(); i++) {
            for (int j = 0; j < relation[i].size(); j++)
                rel[relation[i][0]].push_back(relation[i][1]);
        }
        int cnt = 0;
        while (k) {
            for (int i = 0;i < n; i++) {
                next = rel[next][i];
                if (next == (n-1)) cnt++;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution_1 sol;
    vector<vector<int>> relation;
    vector<int> tmp;
    tmp.push_back(0);
    tmp.push_back(2);
    relation.push_back(tmp);
    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(1);
    relation.push_back(tmp);
    tmp.clear();
    tmp.push_back(3);
    tmp.push_back(4);
    relation.push_back(tmp);
    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(3);
    relation.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(4);
    relation.push_back(tmp);
    tmp.clear();
    tmp.push_back(2);
    tmp.push_back(0);
    relation.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(4);
    relation.push_back(tmp);
    // relation.push_back();
    // relation.push_back();
    // relation.push_back();
    // relation.push_back();
    // relation.push_back();
    cout << sol.numWays(5, relation, 3) << endl;
    return 0;
}