// /*
//    问题描述：
//    解题思路： AC
//  */
// #include <bits/stdc++.h>

// using namespace std;

// vector<int> e[10010];
// bool visit[10010];
// bool flag = false;
// void dfs(int idx, vector<int> &color) {
//     if (flag) return;
//     visit[idx] = true;
//     for (int i = 0; i < e[idx].size(); ++i) {
//         //cout << "compare: " << idx << ":" << e[idx][i] << endl;
//         //cout << "color  : " << color[idx] << ":" << color[e[idx][i]] << endl;
//         if (color[e[idx][i]] == color[idx]) {
//             //cout << "No" << endl;
//             flag = true;
//             return;
//         }
//         //cout << i << ":" << visit[i] << endl;
//         if (visit[e[idx][i]] == false)
//             dfs(e[idx][i], color);
//     }
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     //fill(e[0],e[0] + 1010*1010, -1);
//     fill(visit, visit+10010, false);
//     int n, m;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         e[a].push_back(b);
//         e[b].push_back(a);
//     }
//     int k;
//     scanf("%d", &k);
//     for (int i = 0; i < k; ++i) {
//         vector<int> v(n);
//         fill(visit, visit+10010, false);
//         flag = false;
//         set<int> s;
//         for(int j = 0; j < n; ++j) {
//             scanf("%d", &v[j]);
//             s.insert(v[j]);
//         }
//         dfs(0, v);
//         if (!flag)
//             printf("%d-coloring\n", s.size());
//         else 
//             printf("No\n");
//     }
//     return 0;
// }


// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>
// struct node {
//     int t1, t2;
// };
// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n, m, k;
//     cin >> n >> m;
//     vector<node> v(m);
//     for (int i = 0; i < m; ++i) {
//         scanf("%d %d", &v[i].t1, &v[i].t2);
//     }  
//     cin >> k;
//     while(k--) {
//         int a[10009] = {0};
//         bool flag = true;
//         set<int> s;
//         for (int i = 0; i <  n; ++i) {
//             scanf("%d", &a[i]);
//             s.insert(a[i]);
//         }
//         for (int i = 0; i < m; ++i) {
//             if (a[v[i].t1] == a[v[i].t2]){
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//             printf("%d-coloring\n", s.size());
//         else {
//             printf("No\n");
//         }
        
//     }
//     return 0;
// }

#if 1
#include <bits/stdc++.h>

using namespace std;

struct Peo {
    bool flag;
    int boy;
    //vector<int> boy;
    //vector<int> girl;
};

vector<Peo> x[10010];

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        x[0].boy = 1;
        if (t1 < 0) {
//            if (t2 > 0) {
//                v[abs(t1)].boy.push_back(t2);
//            }
//            else {
//                v[abs(t1)].girl.push_back(abs(t2));
//            }
//            v[abs(t1)].flag = false;
        }
        else {
//            if (t2 > 0) {
//                v[t1].boy.push_back(t2);
//            }
//            else {
//                v[t1].girl.push_back(abs(t2));
//            }
//            v[t1].flag = true;
        }
    }
    return 0;
}


#endif // 1
