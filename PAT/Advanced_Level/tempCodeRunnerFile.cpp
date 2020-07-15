/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node{
    string school;
    int t;
    int a;
    int b;
    int final;
    int cnt;
};

bool cmp(node &a, node &b) {
    if (a.final != b.final)
        return a.final > b.final;
    else
        return a.cnt < b.cnt;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    string str;
    int score;
    string school;
    map<string, node> m;
    for (int i = 0; i < n; ++i) {
        cin >> str >> score >> school;
        for (int j = 0; j < school.size(); j++) {
            if (school[j] >= 'A' && school[j] <= 'Z')
                school[j] = school[j] - 'A' + 'a';
        }
        //cout<< school << endl;
        if (m.find(school) == m.end()) {
            m[school] = {school, 0, 0, 0, 0, 1};
            if (str[0] == 'T')
                m[school].t = score;
            if (str[0] == 'A')
                m[school].a = score;
            if (str[0] == 'B')
                m[school].b = score;
        }
        else {
            if (str[0] == 'T')
                m[school].t = score;
            if (str[0] == 'A')
                m[school].a = score;
            if (str[0] == 'B')
                m[school].b = score;
            m[school].cnt ++;
        }
    }
    vector<node> v;
    for (auto it = m.begin(); it != m.end(); ++it) {
        //cout << it->second.school << " "  << it->second.cnt << endl;
        it->second.final = (int)(it->second.b/1.5 + it->second.a + it->second.t*1.5);
        v.push_back(it->second);
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 1;
    int rank = cnt;
    cout << v.size() << endl;
    cout << "1 " << v[0].school << " " << v[0].final << " " << v[0].cnt << endl;
    int pre_rank = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].final != v[i-1].final) {
            cout << i + 1;
            pre_rank = i + 1;
        }
        else
            cout << pre_rank;
        cout << " " <<v[i].school << " " << v[i].final << " " << v[i].cnt << endl;
    }
    return 0;
}