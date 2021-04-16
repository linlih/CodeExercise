/*******************************************************************
  > File Name    : 4.cpp
  > Author       : linlh
  > Created  Time: 2021.03.30 11:23
  > Modified Time: 2021.03.30 11:45
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;

// vector<int> node[110];
//
// int leaves[110];
// int max_depth = -1;
//
// void count_leaves(int idx_node, int depth) {
//     if (node[idx_node].size() == 0) {
//         leaves[depth]++;
//         if (max_depth < depth) max_depth = depth;
//         return;
//     }
//     for (int i = 0; i < node[idx_node].size(); ++i) {
//         count_leaves(node[idx_node][i], depth +1);
//     }
// }
//
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; ++i) {
//         int id, k;
//         cin >> id >> k;
//         for (int j = 0; j < k; ++j) {
//             int idk;
//             cin >> idk;
//             node[id].push_back(idk);
//         }
//     }
//     count_leaves(1, 0);
//     for (int i = 0;i <= max_depth; ++i) {
//         if (i == 0) cout << leaves[i];
//         else cout << " " << leaves[i];
//     }
//     return 0;
// }

vector<int> node[110];
int max_depth = -1;
int leaves[110];

void count_leaves(int idx_node, int depth) {
    if (node[idx_node].size() == 0) {
        leaves[depth] ++;
        if (max_depth < depth) max_depth = depth;
    }
    for (int i = 0; i < node[idx_node].size(); ++i) {
        count_leaves(node[idx_node][i], depth + 1);
    }
}

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m; ++i) {
        int idk, k;
        cin >> idk >> k;
        for (int j = 0;j < k; ++j) {
            int id;
            cin >> id;
            node[idk].push_back(id);
        }
    }
    count_leaves(1, 0);
    for (int i = 0; i <= max_depth; ++i) {
        if (i == 0) cout << leaves[i];
        else cout << " " << leaves[i];
    }
    return 0;
}
