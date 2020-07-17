// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// //int incomp[50100][50100] = {0};
// map<int, vector<int> > mp;

// map<int, int> id2num;
// map<int, int> num2id;
// int incomp[10010][10010] = {0};


// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n, m;
//     scanf("%d %d", &n, &m);
//     vector<int> ship; 
//     //map<int, int> mp;
//     int cnt = 0;
//     fill(incomp[0], incomp[0] + 10010 * 10010, -1);
//     for (int i = 0; i < n; ++i) {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         if (id2num.find(a) == id2num.end()) {
//             id2num[a] = cnt;
//             num2id[cnt] = a;
//            // cout << a << " map: " << cnt << endl;
//             cnt++;
//         }
//         if (id2num.find(b) == id2num.end()) {
//             id2num[b] = cnt;
//             num2id[cnt] = b;
//            // cout << b << " map: " << cnt << endl;

//             cnt++;
//         }
//         incomp[id2num[a]][id2num[b]] = 1;
//         incomp[id2num[b]][id2num[a]] = 1;
//         // if (mp.find(a) == mp.end()) {
//         //     //mp[a] = vector<int>();
//         //     mp[a].push_back(b);
//         // }
//         //mp[a].push_back(b);
//         //mp[b].push_back(a);
//         //incomp[a][b] = 1;
//         //incomp[b][a] = 1;
//        // mp[a] = b;
//        // mp[b] = a;      
//     }
//     for (int i = 0; i < m; ++i) {
//         int k;
//         scanf("%d", &k);
//         for (int j = 0; j < k; ++j) {
//             int a;
//             scanf("%d", &a);
//             ship.push_back(a);
//         }
//         bool flag = true;
//         for (int j = 0; j < ship.size(); ++j) {
//             if (id2num.find(ship[j]) == id2num.end()) continue;
//             for (int s = j + 1; s < ship.size(); ++s) {
//                 // for (int l = 0; l < mp[ship[j]].size(); ++l) {
//                 //     if (mp[ship[j]][l] == ship[s])
//                 //         flag = false;
//                 //     //cout << ship[j] << "  "<< ship[s] << endl;
//                 // }
//                 if (id2num.find(ship[s]) == id2num.end()) continue;
//                 if (incomp[id2num[ship[j]]][id2num[ship[s]]] == 1 || incomp[id2num[ship[s]]][id2num[ship[j]]] == 1) {
//                     //cout << id2num[ship[j]] << " " << id2num[ship[s]] << " "<< ship[j] << " " << ship[s] << endl;
//                     flag = false;
//                     break;
//                 }
//             }
//             if (!flag) break;
//         }
//         if (flag) printf("Yes\n");
//         else printf("No\n");
//         ship.clear();
//     }
//     return 0;
// }


/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, k, t1, t2;
    map<int, vector<int>> m;// 记录的是不兼容的产品
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &t1, &t2);
        m[t1].push_back(t2);
        m[t2].push_back(t1);
    }
    while(k--) {
        int cnt, flag = 0, a[100000] = {0};
        scanf("%d", &cnt);
        vector<int> v(cnt);
        for (int i = 0; i < cnt; ++i) {
            scanf("%d", &v[i]);
            a[v[i]] = 1;
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < m[v[i]].size(); j++)
                if (a[m[v[i]][j]] == 1) flag = 1;
        }
        printf("%s\n", flag ? "No" : "Yes");
    }
    return 0;
}