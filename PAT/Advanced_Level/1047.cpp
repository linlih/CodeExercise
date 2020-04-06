/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    map<int, vector<string>> course;
    string name;
    int id;
    int m;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> skipws;
        cin >> m;
        cin >> skipws;
        for (int j = 0; j < m; j++) {
            cin >> id;
            cin >> skipws;
            if (course.find(id) == course.end()) {
                vector<string> tmp;
                course.insert(make_pair(id, tmp));
                course[id].push_back(name);
            }
            else 
                course[id].push_back(name);
        }
    }
    for (int i = 0; i < k; i++) {
        cout << (i + 1) << " " << course[id].size() << endl;
        sort(course[id].begin(), course[id].end());
        for (int j = 0; j < course[id].size(); j++)
            cout << course[id][j] << endl;
    }
    return 0;
}