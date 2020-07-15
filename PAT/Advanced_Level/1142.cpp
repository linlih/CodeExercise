// /*
//    问题描述：
//    解题思路： 这个思路是是错误的
//  */
// #include <bits/stdc++.h>

// using namespace std;

// vector<int> node[210];

// int judge_clique(vector<int> &judge, int idx) {

//     if (idx == judge.size()) return 0;
//     for (int i = 0; i < node[idx].size(); ++i) {
//         if (node[idx][i] == judge[idx + 1])
//             return judge_clique(judge, idx + 1);
//         else
//             if (idx == judge.size() - 1)
//                 return 1;
//             else {
//                 return 2;
//             }
            
//     }
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int v, e;
//     cin >> v >> e;
//     for (int i = 0; i < e; ++i) {
//         int a, b;
//         cin >> a >> b;
//         node[a].push_back(b);
//         node[b].push_back(a);
//     }
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         int m;
//         scanf("%d", &m);
//         vector<int> clique;
//         for (int j =  0; j < m; ++j) {
//             int a;
//             scanf("%d", &a);
//             clique.push_back(a);
//         }
//         cout << judge_clique(clique, 1) << endl;
//     } 
//     return 0;
// }


/*
   问题描述：
   解题思路： ref: https://blog.csdn.net/liuchuo/article/details/79618797
 */
#include <bits/stdc++.h>

using namespace std;

int e[210][210];

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; ++i) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &k);
        vector<int> v(k);
        int hash[210] = {0}, isclique = 1, isMaxmial = 1;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;
        }
        for (int j = 0; j < k; ++j) {
            if (isclique == 0) break;
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        for (int j = 1; j <= nv; ++j) {
            if (hash[j] == 0) {
                for (int l = 0; l < k; ++l) {
                    if(e[v[l]][j] == 0) break;
                    if(l == k - 1) isMaxmial = 0;
                }
            }
            if (isMaxmial == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaxmial == 1) printf("Yes\n");
    }

    return 0;
}

315360000