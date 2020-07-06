/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
struct PERSON{
    string name;
    int height;    
}person[100010];

bool cmp(PERSON &p1, PERSON &p2) {
    return p1.height != p2.height ? p1.height > p2.height : p1.name < p2.name;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> person[i].name >> person[i].height;
    }
    sort(person, person + n, cmp);
    vector<PERSON> line;
    int m;
    int t = 0;
    for (int i = k; i > 0; i--) {
        if(i == k) m = n - (n/k)*(k-1);
        else m = n/k;
        vector<PERSON> line(m);
        line[m/2] = person[t];
        // 这段是核心代码！！
        int j = m/2 - 1;
        for (int k = t + 1; k < t + m; k = k + 2)
            line[j--] = person[k];
        j = m/2 + 1;
        for (int k = t + 2; k < t + m; k = k + 2)
            line[j++] = person[k];
        cout << line[0].name ;
        for (int k = 1; k < m; ++k)
            cout << " " << line[k].name;
        cout << endl;
        t = t + m;
    }
    return 0; 
}