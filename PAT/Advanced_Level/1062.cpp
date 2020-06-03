/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct person{
    string id;
    int v;
    int t;
    int total;
};

bool cmp(person &p1, person &p2) {
    if (p1.total == p2.total) {
        if (p1.v == p2.v)
            return p1.id < p2.id;
        return p1.v > p2.v;
    }
    return p1.total > p2.total;
}

int main(int argc, char const *argv[]) {
    int n, l, h;
    cin >> n >> l >> h;
    person *sages = new person[n];
    person *noblemen = new person[n];
    person *foolmen = new person[n];
    person *last = new person[n];
    person tmp;
    int cnt_s, cnt_n, cnt_f, cnt_l;
    cnt_s = cnt_n = cnt_f = cnt_l = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp.id >> tmp.v >> tmp.t;
        tmp.total = tmp.v + tmp.t;
        if (tmp.v >= h && tmp.t >= h) {
            sages[cnt_s] = tmp;
            cnt_s++;
        }
        else if (tmp.v >= h && tmp.t >= l && tmp.t <= h) {
            noblemen[cnt_n] = tmp;
            cnt_n++;
        }
        else if (tmp.v >= l && tmp.t >= l && tmp.v <= h && tmp.t <= h && tmp.v >= tmp.t) {
            foolmen[cnt_f] = tmp;
            cnt_f++;
        }
        else if (tmp.v >= l && tmp.t >= l){
            last[cnt_l] = tmp;
            cnt_l++;
        }
    }
    sort(sages, sages+cnt_s, cmp);
    sort(noblemen, noblemen+cnt_n, cmp);
    sort(foolmen, foolmen+cnt_f, cmp);
    sort(last, last+cnt_l, cmp);

    cout << cnt_s + cnt_n + cnt_f + cnt_l << endl;
    for(int i = 0; i < cnt_s; ++i) {
        cout << sages[i].id << " " << sages[i].v << " " << sages[i].t << endl;
    }
    for(int i = 0; i < cnt_n; ++i) {
        cout << noblemen[i].id << " " << noblemen[i].v << " " << noblemen[i].t << endl;
    }
    for(int i = 0; i < cnt_f; ++i) {
        cout << foolmen[i].id << " " << foolmen[i].v << " " << foolmen[i].t << endl;
    }
    for(int i = 0; i < cnt_l; ++i) {
        cout << last[i].id << " " << last[i].v << " " << last[i].t << endl;
    }
    return 0;
}