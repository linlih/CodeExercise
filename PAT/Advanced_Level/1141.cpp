// /*
//    问题描述：
//    解题思路： 这个方法可以，但是实现上有点复杂
//  */
// #include <bits/stdc++.h>

// using namespace std;

// struct node{
//     string school;
//     int t;
//     int a;
//     int b;
//     int final;
//     int cnt;
// };

// bool cmp(node &a, node &b) {
//     if (a.final != b.final)
//         return a.final > b.final;
//     else if (a.cnt != b.cnt)
//         return a.cnt < b.cnt;
//     else 
//         return a.school < b.school;
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     int n;
//     cin >> n;
//     string str;
//     int score;
//     string school;
//     map<string, node> m;
//     for (int i = 0; i < n; ++i) {
//         cin >> str >> score >> school;
//         for (int j = 0; j < school.size(); j++) {
//             if (school[j] >= 'A' && school[j] <= 'Z')
//                 school[j] = school[j] - 'A' + 'a';
//         }
//         //cout<< school << endl;
//         if (m.find(school) == m.end()) {
//             m[school] = {school, 0, 0, 0, 0, 1};
//             if (str[0] == 'T')
//                 m[school].t = score;
//             if (str[0] == 'A')
//                 m[school].a = score;
//             if (str[0] == 'B')
//                 m[school].b = score;
//         }
//         else {
//             if (str[0] == 'T')
//                 m[school].t += score;
//             if (str[0] == 'A')
//                 m[school].a += score;
//             if (str[0] == 'B')
//                 m[school].b += score;
//             m[school].cnt ++;
//         }
//     }
//     vector<node> v;
//     for (auto it = m.begin(); it != m.end(); ++it) {
//         //cout << it->second.school << " "  << it->second.cnt << endl;
//         it->second.final = (int)(it->second.b/1.5 + it->second.a + it->second.t*1.5);
//         v.push_back(it->second);
//     }
//     sort(v.begin(), v.end(), cmp);
//     int cnt = 1;
//     int rank = cnt;
//     cout << v.size() << endl;
//     cout << "1 " << v[0].school << " " << v[0].final << " " << v[0].cnt << endl;
//     int pre_rank = 1;
//     for (int i = 1; i < v.size(); ++i) {
//         if (v[i].final != v[i-1].final) {
//             cout << i + 1;
//             pre_rank = i + 1;
//         }
//         else
//             cout << pre_rank;
//         cout << " " <<v[i].school << " " << v[i].final << " " << v[i].cnt << endl;
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 柳神的代码提交的测试时间和上面自己实现的差不多。
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    string school;
    int tws, ns;
};

bool cmp(node a, node b) {
    if (a.tws != b.tws)
        return a.tws > b.tws;
    else if (a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.school < b.school;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;

    for (int i = 0; i < n; ++i) {
        string id, school;
        cin >> id;
        double score;
        scanf("%lf", &score);
        cin >> school;
        for (int j = 0; j < school.length(); ++j) 
            school[j] = tolower(school[j]);
        if (id[0] == 'B')
            score = score / 1.5;
        else if (id[0] == 'T')
            score = score * 1.5;
        sum[school] += score;
        cnt[school]++;
    }

    vector<node> ans;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        ans.push_back(node{it->first, (int)sum[it->first], cnt[it->first]});
    }
    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pres = -1;
    printf("%d\n", (int)ans.size());
    for (int i =0; i < ans.size(); ++i) {
        if (pres != ans[i].tws) rank = i + 1;
        pres = ans[i].tws;
        printf("%d ", rank);
        cout << ans[i].school;
        cout << " " << ans[i].tws << " " << ans[i].ns << endl;
    }



    return 0;
}