/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    int gp, gm, gf, g;
};

bool cmp(node a, node b) {
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}

map<string, int> idx; // 核心的要点是这里记录是string和对应的vector下标

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int p, m, n, score, cnt = 1;
    cin >> p >> m >> n;
    vector<node> v, ans;
    string s;
    // 这个方法可以的原因在于，首先的要求是program成绩一定要大于200
    // 如果不满足这个要求，就不需要考虑这个学生的成绩了
    // 所以最终的结果只会在program成绩有效的学生中
    // 后面出现新的学生的成绩，是不需要加入最终的结果的
    // 好像也可以。。。。cnt++就好了
    for (int i = 0; i < p; ++i){
        cin >> s >> score;
        if (score >= 200) {
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> s >> score;
        if (idx[s] != 0) v[idx[s] - 1].gm = score;
    }
    for (int i = 0; i < n; ++i) {
        cin >> s >> score;
        if (idx[s] != 0) {
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].g = score;
            if (v[temp].gm > v[temp].gf) v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5); // + 0.5的原因是为了保证round up，这个很重要，没有做round up的话，会导致两个测试点过不来
            // 也可以使用round函数，但是使用了round函数，就不要加0.5了
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].g >= 60) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    }
    return 0;
}