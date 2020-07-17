// /*
//    问题描述：
//    解题思路： 一个样例测试错误，错误原因是不能直接用cnt判断是否等于n+1来确定访问了所有的结点，需要建立一个set<int>来插入结点，保证这个set的结点数等于所有结点数
//  */
// #include <bits/stdc++.h>

// using namespace std;

// int e[210][210] = {-1};


// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n, m;
//     scanf("%d %d", &n, &m);
//     fill(e[0], e[0] + 210 * 210, -1);
//     for (int i = 0; i < m; ++i) {
//         int a, b, d;
//         scanf("%d %d %d", &a, &b, &d);
//         e[a][b] = d;
//         e[b][a] = d;
//     } 
//     int k;
//     scanf("%d", &k);
//     int minidx = -1, mincost = INT_MAX;
//     for (int i = 1; i <= k; ++i) {
//         int cnt;
//         scanf("%d", &cnt);
//         vector<int> path(cnt+1);
//         set<int> node;
//         for (int j = 1; j <= cnt; ++j) {
//             scanf("%d", &path[j]);
//             node.insert(path[j]);
//         }
//         bool flag = true;
//         int cost = 0;
//         for (int j = 1; j < cnt; ++j) {
//             if (e[path[j]][path[j+1]] == -1) {
//                 //cout << path[j] << " --> " << path[j + 1] << endl;
//                 flag = false;
//                 break;
//             }
//             else {
//                 cost += e[path[j]][path[j+1]];
//             }
//         }
//         if (flag && cnt >= (n + 1)&& cost < mincost) {
//             mincost = cost;
//             minidx = i;
//         }
//         // if (flag && cnt == (n + 1)  && path[1] == path[cnt]) 
//         //     printf("Path %d: %d (TS simple cycle)\n", i, cost);
//         // else if (flag && cnt >= (n + 1)  && path[1] != path[cnt]) printf("Path %d: %d (Not a TS cycle)\n", i, cost);
//         // else if (flag && cnt > (n + 1) && path[1] == path[cnt]) printf("Path %d: %d (TS cycle)\n", i, cost); 
//         // else if (flag && cnt > (n + 1) && path[1] != path[cnt]) printf("Path %d: %d (Not a TS cycle)\n", i, cost); 
//         // else if (flag && cnt < (n + 1)) printf("Path %d: %d (Not a TS cycle)\n", i, cost);
//         // else printf("Path %d: NA (Not a TS cycle)\n", i); 

//         if (flag == false) 
//             printf("Path %d: NA (Not a TS cycle)\n", i); 
//         else if (path[1] != path[cnt] || node.size() < n)
//             printf("Path %d: %d (Not a TS cycle)\n", i, cost);
//         else if (node.size() == n && cnt > (n + 1))
//             printf("Path %d: %d (TS cycle)\n", i, cost);
//         else 
//             printf("Path %d: %d (TS simple cycle)\n", i, cost);

//     }
//     printf("Shortest Dist(%d) = %d\n", minidx, mincost);
//     return 0;
// }


/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int e[300][300], n, m, k, ans = 99999999, ansid;
vector<int> v;
void check(int index) {
    int sum = 0, cnt, flag = 1;
    scanf("%d", &cnt);
    set<int> s;
    vector<int> v(cnt);
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &v[i]);
        s.insert(v[i]);
    }
    for (int i = 0; i < cnt - 1; i++) {
        if(e[v[i]][v[i+1]] == 0) flag = 0;
        sum += e[v[i]][v[i+1]];
    }
    if (flag == 0)
        printf("Path %d: NA (Not a Ts cycle)\n", index);
    else if (v[0] != v[cnt - 1] || s.size() != n)
        printf("Path %d: %d (Ts cycle)\n", index, sum);
    else if (cnt != n + 1) {
        printf("Path %d: %d (Ts cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    }
    else {
        printf("Path %d: %d (Ts simple cycle)\n", index, sum);
        if (sum < ans) {
            ans = sum;
            ansid = index;
        }
    }

}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int t1, t2, t;
        scanf("%d%d%d", &t1, &t2, &t);
        e[t1][t2] = e[t2][t1] = t;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) check(i);
    printf("Shortest Dist(%d) = %d\n", ansid, ans);

    return 0;
}