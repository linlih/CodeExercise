/*
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