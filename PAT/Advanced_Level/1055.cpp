/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct person {
    string name;
    int age;
    int net_worth;
};

// 这里要注意：资产是从大到小，年龄和名字是从小到大
bool cmp(person &p1, person& p2) {
    if (p1.net_worth > p2.net_worth)
        return true;
    else if (p1.net_worth < p2.net_worth)
        return false;
    else {
        if (p1.age < p2.age)
            return true;
        else if (p1.age > p2.age)
            return false;
        else
            return p1.name < p2.name;
    }
}

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    vector<person> total;
    person tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp.name >> tmp.age >> tmp.net_worth;
        total.push_back(tmp);
    }
    sort(total.begin(), total.end(), cmp);
    int m, s, e;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cin >> m >> s >> e;
        cnt = 0;
        cout << "Case #" << i + 1 << ":" << endl;
        for (int j = 0; j < total.size(); j++) {
            if (total[j].age >=s && total[j].age <= e) {
                cout << total[j].name << " " << total[j].age << " " << total[j].net_worth << endl;
                cnt ++;
            }
            if (cnt >= m) break;
        }
        if (cnt == 0) cout << "None" << endl;
    }
    return 0;
}