/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

bool cmp1(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

bool cmp2(pair<int, string> p1, pair<int, string> p2) {
    return p1.first > p2.first;
}
int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    vector<pair<int, string> > in;
    vector<pair<int, string> > out;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char str[20];
        int h1, m1, s1, h2, m2, s2;
        scanf("%s %d:%d:%d %d:%d:%d", str, &h1, &m1, &s1, &h2, &m2, &s2);
        in.push_back(make_pair(h1*3600+m1*60+s1, string(str)));
        out.push_back(make_pair(h2*3600+m2*60+s2, string(str)));
    }
    sort(in.begin(), in.end(), cmp1);
    sort(out.begin(), out.end(), cmp2);
    cout << in[0].second << " " << out[0].second << endl;
    return 0;
}