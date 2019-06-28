/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>

using namespace std;

class myCompare {
public:
	// 重载小括号 ()
	bool operator()(char v1, char v2) {
		return true;
	}
};

int main(int argc, char const *argv[])
{
    string s_true;
    string s_false;
    cin >> s_true;
    cin >> s_false;
    //set<char, myCompare> s;
    string diff;
    //diff.resize(s_true.size());
    int i = 0;
    int j = 0;
    char tmp;
    for (int i = 0; i < s_true.length(); ++i) {
        if (s_true[i] == s_false[j])
            j++;
        else {
            //s.insert(s_true[i]);
            tmp = char(toupper(s_true[i]));
            if (diff.find(tmp) == -1)
                diff+=tmp;
        }
    }
    //cout << s.size() << endl;
    // for (set<char>::iterator i = s.begin(); i != s.end(); ++i) {
    //     cout << char(toupper(*i));
    // }
    cout << diff <<endl;
    return 0;
}