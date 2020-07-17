/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

//int e[1010][1010] = {0};
int indegree[1010] = {0};
int tmpdegree[1010] = {0};
vector<int> e[1010];

int n, m;
bool judge(vector<int> &node) {
    if (tmpdegree[node[0]] != 0) return false;

    /** 这个方法两个测试样例过不了 **/
    // queue<int> q;
    // q.push(node[0]);
    // int i = 0;
    // while(!q.empty()) {
    //     int a = q.front();
    //     q.pop();
    //     bool flag = false;
    //     i+=1;
    //     if(i == n) return true;
    //     for (int j = 0; j < e[a].size(); ++j) {
    //         tmpdegree[e[a][j]]--;
    //         if (tmpdegree[node[i]] == 0)
    //             flag = true;
    //     }
    //     //cout << i <<" " <<node[i] << endl;
    //     if (!flag) {
    //         //cout << "FALSE: " << node[i] << endl;
    //         return false;
    //     }
    //     else {
    //         //cout << "PUSH: " << node[i] << endl;
    //         q.push(node[i]);
    //     }
    // }

    /** 这个方法一个测试样例过不了, 过不了的原因是memcpy函数拷贝indegree导致的 **/
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < e[node[i-1]].size(); ++j) {
            tmpdegree[e[node[i-1]][j]]--;
        }
        if (tmpdegree[node[i]] != 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    //fill(e[0], e[0] + 1010 * 1010, 0);
    fill(indegree, indegree + 1010, 0);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        //e[a][b] = 1;
        e[a].push_back(b);
        indegree[b]++;
    }
    int k;
    scanf("%d", &k);
    vector<int> node(n);
    vector<int> nottop;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j)
            scanf("%d", &node[j]);
        
        //memcpy(tmpdegree, indegree, 1010); // 使用memcpy会导致最后一个样例测试错误
        for (int j = 1; j <= n; ++j) {
            tmpdegree[j] = indegree[j];
        } 
        if(!judge(node))
            nottop.push_back(i);
    }
    printf("%d", nottop[0]);
    for (int i = 1; i < nottop.size(); ++i)
        printf(" %d", nottop[i]);
    return 0;
}


// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n, m, a, b, k, flag = 0, in[1010];
//     vector<int> v(1010);
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < m; ++i) {
//         scanf("%d %d", &a, &b);
//         v[a].push_back(b);
//         in[b]++;
//     }
//     scanf("%d", &k);
//     for (int i = 0; i < k; ++i) {
//         int judge = 1;
//         vector<int> tin(in, in + n + 1);
//         for (int j = 0; j < n; ++j) {
//             scanf("%d", &a);
//             if (tin[a] != 0) judge = 0;
//             for (int it : v[a]) tin[it]--;
//         }
//         if (judge == 1) continue;
//         printf("%s%d", flag == 1 ?" ":"", i);
//         flag = 1;
//     }
//     return 0;
// }

