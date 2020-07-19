/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int k, n, m;
map<int, map<int, int> > mp;
bool cmp(set<int> &s1, set<int> &s2) {
    return s1.size() > s2.size();
}
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        mp[a][b]+=c;
    }
    vector<int> suspects;
    for (auto i = mp.begin(); i != mp.end(); ++i) {
        int call_cnt = 0; // short call number
        int call_back_cnt = 0;
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            //cout << i->first << " : " << j->first << " " << j->second << endl;
            if (j->second > 0 && j->second <= k) {
                call_cnt++;
                if (mp[j->first][i->first] > 0)
                    call_back_cnt++;
            }
        }
        // no more than 20% percent
        //cout << call_cnt << " " << call_back_cnt << endl;
        if (call_cnt > k) {
            if (call_back_cnt * 1.0 / call_cnt <= 0.2) {
                suspects.push_back(i->first);
                //cout << "FOUND a suspect: " << i->first << endl;
            }
        }
    }
    map<int, int> gang;
    //cout << gang[0] << endl;
    int gangid = 1;
    vector<set<int>> gangs;
    if(suspects.size() == 0) {
        printf("None\n");
        return 0;
    }
    else {
        for (int i = 0; i < suspects.size(); ++i) {
            //gang[i] = gangid;
            set<int> g;
            if (!gang[i]) {
                g.insert(suspects[i]);
                for (int j = i + 1; j < suspects.size(); ++j) {
                    if (mp[suspects[i]][suspects[j]] > 0) {
                        gang[j] = gangid;
                        //cout << suspects[i] << " " << suspects[j] << endl;
                        g.insert(suspects[j]);
                    }
                }
                gangid++;
                gangs.push_back(g);
            }
        }
    }
    sort(gangs.begin(), gangs.end(), cmp);
    for (int i = 0;  i < gangs.size(); i++) {
        for (auto it = gangs[i].begin(); it != gangs[i].end(); it++) {
            if (it != gangs[i].begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }
    // set<int> out[gangid];
    // for (int i = 0; i < suspects.size(); ++i) {
    //     out[gang[suspects[i]]].insert(suspects[i]);
    // }
    // for (int i = 1; i < gangid; ++i) {
    //     for (auto it = out[i].begin(); it!=out[i].end(); ++it) {
    //         if (it != out[i].begin()) cout << " " << endl;
    //         cout << *it << endl;
    //     }
    // }
    return 0;
}