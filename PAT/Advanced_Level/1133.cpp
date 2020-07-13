// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct NODE {
//     int val;
//     int next;
// }node[100010];

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int start, n, k;
//     cin >> start >> n >> k;
//     int addr, data, next;
//     for (int i = 0; i < n; ++i) {
//         cin >> addr >> data >> next;
//         node[addr].val = data;
//         node[addr].next = next;
//     }
//     int pre_postive = -1;
//     next = start;
//     while (node[next].val < 0) {
//         pre_postive = next;
//         next = node[next].next;
//     }

//     int after_postive = next;
//     int insert = node[next].next;
//     while (insert != -1) {
//         if (node[insert].val >= 0) {
//             node[after_postive].next = insert;
//             after_postive = insert;
//         }
//         else {
//             if (pre_postive = -1) {
//                 start = insert;
//                 node[insert].next = after_postive;
//             }
//             else {
//                 node[pre_postive].next = insert;
//             }
//             pre_postive = insert;
//         }
//         insert = node[insert].next;
//     }
//     while (start != -1) {
//         cout << node[start].val << endl;
//         start = node[start].next;
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int id, data, next;
};

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int begin, n, k, s, d, e;
    scanf("%d%d%d", &begin, &n, &k);
    node a[100010];
    vector<node> v, ans;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &s, &d, &e);
        a[s] = {s, d, e};
    }
    for (; begin != -1; begin = a[begin].next)
        v.push_back(a[begin]);
    for (int i = 0; i < v.size(); ++i) 
        if (v[i].data < 0) ans.push_back(v[i]);
    for (int i =  0; i < v.size(); ++i) 
        if (v[i].data >= 0 && v[i].data <= k) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); ++i)
        if (v[i].data > k) ans.push_back(v[i]);
    for (int i = 0; i < ans.size() - 1; ++i) {
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i+1].id);
    }
    printf("%05d %d -1\n", ans[ans.size() - 1].id, ans[ans.size() - 1].data);

    return 0;
}