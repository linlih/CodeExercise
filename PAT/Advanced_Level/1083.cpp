/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
struct stu {
    int grade;
    string id;
    string name;
};

bool cmp(stu &s1, stu &s2) {
    return s1.grade > s2.grade;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    stu *s = new stu[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i].name >> s[i].id >> s[i].grade;
    }
    int start, end;
    cin >> start >> end;
    
    sort(s, s+n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i].grade >= start && s[i].grade <= end) {
            cout << s[i].name << " " << s[i].id << endl;
            cnt++;
        }
    }
    if (cnt == 0)
        cout << "NONE" << endl;

    return 0;
}