/*
   问题描述：
   解题思路： 
   一个样例测试超时
 */
#include <bits/stdc++.h>

using namespace std;

map<string, vector<int >> stu;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;
    int course_i, num;
    string name;
    vector<int> c;
    for (int i = 0; i < k; i++) {
        cin >> course_i >> num;
        for (int j = 0; j < num; j ++) {
            cin >> name;
            cin >> skipws;
            if (stu.find(name) == stu.end()) {
                stu.insert(make_pair(name, c));
                stu[name].push_back(course_i); 
            }
            else {
                stu[name].push_back(course_i); 
            }
        }
    }
    // for (auto it = stu.begin(); it != stu.end(); it++) {
    //     cout << it->first << " ";
    //     for (int i = 0; i < it->second.size(); i++) {
    //         cout << it->second[i] << " ";
    //     }
    //     cout << endl;
    // }
    for (auto it = stu.begin(); it != stu.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> skipws;
        cout << name ;
        auto it = stu.find(name);
        if (it != stu.end()) {
            cout << " "  << it->second.size();
            for (int i = 0; i < it->second.size(); i++) {
                cout << " " << it->second[i];
            }
            cout << endl;
        }
        else {
            cout << " " << "0" << endl;
        }
    }

    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

int getid(char *name) {
    int id = 0;
    for (int i = 0; i < 3; i++) 
        id = 26 * id + (name[i] - 'A');
    id = id*10 +(name[3] - '0');
    return id;
}

const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn]; 

int main(int argc, char const *argv[]) {
    int n, k, no, num, id = 0;
    char name[5];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for (int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getid(name);
            v[id].push_back(no);
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        id = getid(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %lu", name, v[id].size());
        for (int j = 0; j < v[id].size(); j++)
            printf(" %d", v[id][j]);
        printf("\n");
    }
    return 0;
}