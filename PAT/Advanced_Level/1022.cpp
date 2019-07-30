/*
   问题描述：
   解题思路： 
   注意点： 数据输入一定要用C语言的库，如何用c++的cin的话会有很多bug
 */
#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;

map<string ,set<int> > title, author, keyword, pub, year;

void query(map<string, set<int> > &m, string & str) {
    if (m.find(str) != m.end()) {
        for (auto it = m[str].begin(); it != m[str].end(); it++) {
            printf("%07d\n", *it); // 这里一定要写成07d，写成7d会答案错误
        }
    }
    else 
        cout << "Not Found\n";
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d\n", &n);
    int id;
    string ttitle, tauthor, tkeyword, tpub, tyear;
    for (int i = 0; i < n; i++) {
        scanf("%d\n", &id); // 这里的换行符非常重要！！！，一定要写进来
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while (cin >> tkeyword) {
            keyword[tkeyword].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    int m;
    int num;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if (num == 1) query(title, temp);
        else if (num == 2) query(author, temp);
        else if (num == 3) query(keyword, temp);
        else if (num == 4) query(pub, temp);
        else if (num == 5) query(year, temp);
    }
    return 0;
}