/*
   问题描述：
   解题思路： 
   最后一个测试样例有时候会超时
 */
#include <bits/stdc++.h>

using namespace std;

struct col {
    string id;
    string name;
    int grade;
};

bool cmp1(col &a, col &b) {
    if (a.id < b.id) {
        return true;
    }
    return false;
}

bool cmp2(col &a, col &b) {
    if (a.name <= b.name) {
        return true;
    }
    return false;
}

bool cmp3(col &a, col &b) {
    if (a.grade <= b.grade) {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int N, C;
    cin >> N >> C;
    col *stu = new col[N];
    for (int i = 0; i < N; i++) {
        cin >> stu[i].id >> stu[i].name >> stu[i].grade;
    }
    if (C == 1)
        sort(stu, stu + N, cmp1);
    if (C == 2)
        sort(stu, stu + N, cmp2);
    if (C == 3)
        sort(stu, stu + N, cmp3);
    
    for (int i = 0; i < N; i++) 
        cout << stu[i].id << " " << stu[i].name << " " << stu[i].grade << endl;

    return 0;
}