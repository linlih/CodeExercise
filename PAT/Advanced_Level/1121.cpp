/*
   问题描述：
   解题思路：思路正确，但是不是最优的解法
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    int a, b;
    map<int, int> nonsingle;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        nonsingle[a] = b;
        nonsingle[b] = a;
    }
    int k;
    cin >> k;
    int d;
    set<int> party;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &d);
        party.insert(d);
    }
    set<int> out;
    for (auto it : party) {
        if (nonsingle.find(it) == nonsingle.end() || party.find(nonsingle[it]) == party.end())
            out.insert(it);
    }
    int i = 0;
    cout << out.size() <<endl;
    for (auto it : out) {
        if (i == 0) {
            printf("%05d", it);
            i++;
        }
        else printf(" %05d", it);
    }
        
    return 0;
}

/*
   问题描述：
   解题思路：柳神的效率高很多
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, a, b, m;
    scanf("%d", &n);
    vector<int> couple(100000);
    for (int i = 0; i < n; ++i) {
        couple[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    vector<int> guest(m), isExist(100000);
    for (int i = 0; i < m; i++) {
        scanf("%d", &guest[i]);
        if (couple[guest[i]] != -1)
            isExist[couple[guest[i]]] = 1;
    }
    set<int> s;
    for (int i = 0; i < m; ++i) {
        if (!isExist[guest[i]]) s.insert(guest[i]);
    }
    printf("%d\n", s.size());
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it != s.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}