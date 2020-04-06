// /*
//    问题描述：
//    解题思路： 
//    有一个样例超时
//  */
// #include <bits/stdc++.h>

// using namespace std;
// int main(int argc, char const *argv[]) {
//     int n, k;
//     cin >> n >> k;
//     map<int, vector<string>> course;
//     string name;
//     int id;
//     int m;
//     for (int i = 0; i < n; i++) {
//         cin >> name;
//         cin >> skipws;
//         cin >> m;
//         cin >> skipws;
//         for (int j = 0; j < m; j++) {
//             cin >> id;
//             cin >> skipws;
//             if (course.find(id) == course.end()) {
//                 vector<string> tmp;
//                 course.insert(make_pair(id, tmp));
//                 course[id].push_back(name);
//             }
//             else 
//                 course[id].push_back(name);
//         }
//     }
//     for (int i = 1; i <= k; i++) {
//         cout << i << " " << course[i].size() << endl;
//         sort(course[i].begin(), course[i].end());
//         for (int j = 0; j < course[i].size(); j++)
//             cout << course[i][j] << endl;
//     }
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

char name[40010][5];
vector<int> course[2510];

bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main(int argc, char const *argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for (int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}