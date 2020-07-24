// /*
//    问题描述：
//    解题思路： 理解错误，是have some common hobbies of them
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     map<int, int> cluster;
//     int ki;
//     int temp;
//     for (int i = 1; i <= n; ++i) {
//         scanf("%d:", &ki);
//         for (int j = 0; j < ki; ++j) {
//             scanf("%d", &temp);
//             if (cluster.find(temp) == cluster.end())
//                 cluster[temp] = 1;
//             else 
//                 cluster[temp]++;
//         }
//     }
//     int cnt = 0;
//     vector<int> num;
//     for (auto it = cluster.begin(); it != cluster.end(); it++) {
//         if (it->second > 1) {
//             cnt++;
//             num.push_back(it->second);
//         }
//     }
//     cout << cnt << endl;
//     sort(num.begin(), num.end(), greater<int>());
//     for (int i = 0; i < num.size(); i++) {
//         if (i == 0) cout << num[i];
//         else cout << " " << num[i];
//     }
//     cout << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> father, isRoot;
int cmp1(int a, int b) {return a > b;}
int findFather(int x) {
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = a;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, k, t, cnt = 0;
    int course[1001] = {0}; // 表示任意一个喜欢t活动的编号
    scanf("%d", &n);    
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    } 
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            if (course[t] == 0) // 这个活动没有人喜欢过的话，那么就标记为新的编号
                course[t] = i;
            Union(i, findFather(course[t])); // findFather就是表示喜欢这个活动所处的社交圈子的根节点，合并根节点和当前人编号的结点i
        }
    }
    for(int i = 1; i <= n; i++)
        isRoot[findFather(i)]++; // isRoot中记录的就是每个社交圈子中的人数
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) cnt++; // isRoot不为0代表一个圈子
    }
    printf("%d\n", cnt);
    sort(isRoot.begin(), isRoot.end(), cmp1);
    for(int i = 0; i < cnt; i++) {
        printf("%d", isRoot[i]);
        if(i != cnt - 1) printf(" ");
    }
    return 0;
}