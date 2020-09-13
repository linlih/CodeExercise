/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> node[110];

int leaves[110];
int max_depth = -1;

void count_leaves(int idx_node, int depth) {
    if (node[idx_node].size() == 0) {

        leaves[depth]++;
        if (max_depth < depth) max_depth = depth;
        return;     
    }
    for (int i = 0; i < node[idx_node].size(); ++i) {
        count_leaves(node[idx_node][i], depth+1);
    }
}


int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int idk;
            cin >> idk;
            node[id].push_back(idk);
        }
    }
    count_leaves(1, 0);
    for (int i = 0; i <= max_depth; ++i) {
        if (i == 0) cout << leaves[i];
        else cout << " " << leaves[i];
    }
    return 0;
}