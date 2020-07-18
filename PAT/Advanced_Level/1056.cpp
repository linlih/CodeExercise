// /*
//    问题描述：
//    解题思路： ref:https://blog.csdn.net/CV_Jason/article/details/85238006
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n, m;
//     scanf("%d %d", &n, &m);
//     vector<int> np(n);
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &np[i]);
//     }
//     vector<int> ng;
//     for (int i = 0; i < n; ++i) {
//         int a;
//         scanf("%d", &a);
//         ng.push_back(np[a]);
//         //cout << np[a] << endl;
//     }
//     vector<int> rank;
//     vector<int> tmp = ng;
//     vector<int> res;
//     vector<int> rank;
//     int cnt;
//     while (1) {
//         int i;
//         cnt = tmp.size()/m + 1;
//         for (i = 0; i < tmp.size()/m; ++i) {
//             auto it = max_element(tmp.begin() + i*m, tmp.begin() +(i +1)*m);
//             res.push_back(*it);
//             rank.push_back(cnt);
//         }
//         if (tmp.size() % m != 0) {
//             auto it  = max_element(tmp.begin() + i*m, tmp.end());
//             res.push_back(*it);
//             rank.push_back(cnt);
//         }
//         tmp.clear();
//         tmp = res;
//         res.clear();
//         if (tmp.size() == 1)
//             break;
//         //cout << tmp.size() << endl;
//     }
//     cout << tmp[0] << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int weight, index, rank, index0;
};

bool cmp(node a, node b) {
    return a.index0 < b.index0;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }

    queue<node> q;
    for (int i = 0;i < n; ++i) 
        q.push(w[i]);
    while(!q.empty()) {
        int size = q.size();
        if (size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if (size % g != 0)
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for (int i = 0; i <size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if (temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if (cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if (i != 0) printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}
