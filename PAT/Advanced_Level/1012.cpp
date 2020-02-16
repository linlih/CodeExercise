// /*
//    问题描述：
//    解题思路： 这道题难度不大，难点在于比较麻烦，实现起来的思路不难
//               这个实现用例有的测试不过
//  */
// #include <bits/stdc++.h>

// using namespace std;

// typedef struct stu{
//     int best_rank;
//     int best_i;
//     int rank[4];
//     int grade[4]; // A C M E
//     string id;
// }stu;

// bool cmp_a(stu& s1, stu& s2) {
//     return s1.grade[0] > s2.grade[0];
// }

// bool cmp_c(stu& s1, stu& s2) {
//     return s1.grade[1] > s2.grade[1];
// }

// bool cmp_m(stu& s1, stu& s2) {
//     return s1.grade[2] > s2.grade[2];
// }

// bool cmp_e(stu& s1, stu& s2) {
//     return s1.grade[3] > s2.grade[3];
// }

// int main(int argc, char const *argv[])
// {
//     int n, M;
//     cin >> n >> M;
//     stu *gradelist = new stu[n];
//     int temp = 0;
//     char subject[5] = "ACME";
//     for (int i = 0; i < n; i++) {
//         temp = 0;
//         gradelist[i].best_rank = 0;

//         cin >> gradelist[i].id >> gradelist[i].grade[1] >> gradelist[i].grade[2] >> gradelist[i].grade[3];
//         gradelist[i].grade[0] = (gradelist[i].grade[1] + gradelist[i].grade[2] + gradelist[i].grade[3]) / 3;
//     }
//     sort(gradelist, gradelist + n, cmp_a);
//     for (int i = 1; i <= n; i++) {
//         gradelist[i - 1].rank[0] = i;
//         //cout << "test:" <<gradelist[i - 1].id << endl;
//     }
//     sort(gradelist, gradelist + n, cmp_c);
//     for (int i = 1; i <= n; i++) {
//         gradelist[i - 1].rank[1] = i;
//     }
//     sort(gradelist, gradelist + n, cmp_m);
//     for (int i = 1; i <= n; i++) {
//         gradelist[i - 1].rank[2] = i;
//     }
//     sort(gradelist, gradelist + n, cmp_e);
//     for (int i = 1; i <= n; i++) {
//         gradelist[i - 1].rank[3] = i;
//     }
//     int temp_rank;
//     for (int i = 0; i < n; i++) {
//         temp = 0;
//         temp_rank = gradelist[i].rank[0];
//         for (int j = 1; j < 4; j++) {
//             if (temp_rank > gradelist[i].rank[j]) {
//                 temp_rank = gradelist[i].rank[j];
//                 temp = j;
//             }
//         }
//         gradelist[i].best_rank = temp_rank;
//         gradelist[i].best_i = temp;
//         //cout << gradelist[i].id << " " << gradelist[i].best_rank << " " << gradelist[i].best_i << endl;
//     }

//     for (int i = 0; i < M; i++) {
//         string temp_name;
//         cin >> temp_name;
//         bool found = false;
//         for (int j = 0; j < n; j++) {
//             if (gradelist[j].id == temp_name) {
//                 found = true;
//                 cout << gradelist[j].best_rank << " " << subject[gradelist[j].best_i] << endl;
//             }
//         }
//         if (!found)
//             cout << "N/A" << endl;
//     }
//     return 0;
// }



// 正确的代码 牛客网：https://www.nowcoder.com/pat/1/problem/3992
#include<cstdio>
#include <iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<string, int> mp;
int a[2000][4], have[102];
char c[4] = { 'A','C','M','E' };
int main() {
    int n, m;
    char s[10];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", s, &a[i][1], &a[i][2], &a[i][3]);
        a[i][0] = (a[i][1] + a[i][2] + a[i][3]) / 3;
        mp[s] = i;
    }
    for (int i = 0; i < 4; i++) {
        memset(have, 0, sizeof(have));
        // 利用数组计算排名
        for (int j = 0; j < n; j++) {
            have[a[j][i]]++;
            //cout << "add : " << a[j][i] << " " << have[a[j][i]] << endl;
        }
        for (int j = 100; j >= 0; j--) {
            have[j] += have[j + 1]; 
        }
        // a[j][i] = 90
        for (int j = 0; j < n; j++) {
            //cout << "test: " << a[j][i] << " " << have[a[j][i]] << endl;
            a[j][i] = have[a[j][i] + 1] + 1; // ？
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        auto it = mp.find(s);
        if(it==mp.end()){
            printf("N/A\n");
        }
        else {
            int t = 0;
            for (int j = 1; j < 4; j++) {
                if (a[it->second][j] < a[it->second][t]) {
                    t = j;
                }
            }
            printf("%d %c\n", a[it->second][t], c[t]);
        }
    }
    return 0;
}

// #include<cstdio>
// #include<cstring>
// #include<string>
// #include<map>
// using namespace std;
// map<string, int> mp;
// int a[2000][4], have[102];
// char c[4] = { 'A','C','M','E' };
// int main() {
//     int n, m;
//     char s[10];
//     scanf("%d%d", &n, &m);
//     for (int i = 0; i < n; i++) {
//         scanf("%s%d%d%d", s, &a[i][1], &a[i][2], &a[i][3]);
//         a[i][0] = (a[i][1] + a[i][2] + a[i][3]) / 3;
//         mp[s] = i;
//     }
//     for (int i = 0; i < 4; i++) {
//         memset(have, 0, sizeof(have));
//         for (int j = 0; j < n; j++) {
//             have[a[j][i]]++;
//         }
//         for (int j = 100; j >= 0; j--) {
//             have[j] += have[j + 1];
//         }
//         for (int j = 0; j < n; j++) {
//             a[j][i] = have[a[j][i] + 1] + 1;
//         }
//     }
//     for (int i = 0; i < m; i++) {
//         scanf("%s", s);
//         auto it = mp.find(s);
//         if(it==mp.end()){
//             printf("N/A\n");
//         }
//         else {
//             int t = 0;
//             for (int j = 1; j < 4; j++) {
//                 if (a[it->second][j] < a[it->second][t]) {
//                     t = j;
//                 }
//             }
//             printf("%d %c\n", a[it->second][t], c[t]);
//         }
//     }
//     return 0;
// }
// #include <iostream>
// #include <map>
// #include <string>
 
// using namespace std;
 
// int main(int argc, const char * argv[]) {
//     int grade[4][101] = {0};
//     int rank[4][101] = {0};
//     int students[2010][4] = {0};
//     char course[5] = "ACME";
//     int m, n;
//     scanf("%d %d", &n, &m);
//     map<string, int> stu;
//     for (int i = 0; i < n; i++) {
//         char id[7];
//         scanf("%s", id);
//         pair<string, int> value(id, i);
//         stu.insert(value);
//         int tmp = 0;
//         for (int j = 1; j < 4; j++) {
//             scanf("%d", &students[i][j]);
//             grade[j][students[i][j]]++;
//             tmp += students[i][j];
//         }
//         tmp /= 3;
//         students[i][0] = tmp;
//         grade[0][tmp]++;
//     }
//     for (int i = 0; i < 4; i++) {
//         int cnt = 1;
//         for (int j = 100; j > -1; j--) {
//             if (grade[i][j] != 0) {
//                 rank[i][j] = cnt;
//                 cnt += grade[i][j];
//             }
//         }
//     }
//     for (int i = 0; i < m; i++) {
//         char id[7];
//         scanf("%s", id);
//         if (stu.find(id) == stu.end()) {
//             printf("N/A\n");
//         } else {
//             int tmp = 2010, k = 0;
//             for (int j = 0; j < 4; j++) {
//                 if (rank[j][students[stu[id]][j]] < tmp) {
//                     int num = stu[id];
//                     tmp = rank[j][students[num][j]];
//                     k = j;
//                 }
//             }
//             printf("%d %c\n", tmp, course[k]);
//         }
//     }
//     return 0;
// }