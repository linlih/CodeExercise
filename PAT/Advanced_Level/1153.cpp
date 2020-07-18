/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct REG {
    char level;
    int site_num;
    char date;
};

struct type1 {
    string cardnum;
    int score;
};

struct type2 {
    string date;
    int Nt;
    int Ns;
};

struct type3 {
    string site;
    int nt;
};
map<char, vector<type1> > t1; // A, B, T
map<string, type2> t2; // site
//map<string, set<string>> t3; // date 
map<string, map<string, int>>t3;

bool cmp1 (type1 &s1, type1 &s2) {
    if (s1.score != s2.score)
        return s1.score > s2.score;
    else
        return s1.cardnum < s2.cardnum;
}

bool cmp3 (type3 &s1, type3 &s2) {
    if (s1.nt != s2.nt)
        return s1.nt > s2.nt;
    else
        return s1.site < s2.site;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    string tmp;
    int score;
    
    for (int i = 0; i < n; ++i) {
        cin >> tmp >> score;
        if (tmp[0] == 'A') 
            t1['A'].push_back({tmp, score});
        else if (tmp[0] == 'B') 
            t1['B'].push_back({tmp, score});
        else 
            t1['T'].push_back({tmp, score});

        string site = tmp.substr(1, 3);
        string date = tmp.substr(4, 6);
        if (t2.find(site) == t2.end()) {
            t2[site].Ns = score;
            t2[site].Nt = 1;
            t2[site].date = date;
        }
        else {
            t2[site].Ns += score;
            t2[site].Nt += 1;
        }
        t3[date][site]++;
        //cout << date << " " << site << " " << t3[date][site] << endl;
    }
    for (int i = 1; i <= m; ++i) {
        int a;
        scanf("%d", &a);
        if (a == 1) {
            char c;
            scanf("%s", &c);
            printf("Case %d: 1 %c\n", i, c);
            if (t1[c].size() == 0) {
                printf("NA\n");
                continue;
            }
            sort(t1[c].begin(), t1[c].end(), cmp1);
            for (int j = 0; j < t1[c].size(); ++j) {
                printf("%s %d\n", t1[c][j].cardnum.c_str(), t1[c][j].score);
            }
        }
        else if (a == 2) {
            string str;
            cin >> str;
            printf("Case %d: 2 %s\n", i, str.c_str());
            if (t2.find(str) != t2.end())
                printf("%d %d\n", t2[str].Nt, t2[str].Ns);
            else 
                printf("NA\n");
        }
        else if (a == 3) {
            string str;
            cin >> str;
            vector<type3> v;
            printf("Case %d: 3 %s\n", i, str.c_str());
            for (auto it = t3[str].begin(); it != t3[str].end(); ++it)
                v.push_back({it->first, it->second});
            if (v.size() == 0) {
                printf("NA\n");
                continue;
            }
            sort(v.begin(), v.end(), cmp3);
            for (int i = 0; i < v.size(); ++i) {
                printf("%s %d\n", v[i].site.c_str(), v[i].nt);
            }
        }
    }
    return 0;
}