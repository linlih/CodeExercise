/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    string num;
    int k;
    cin >> num >> k;
    string res, num_reverse;
    int i;
    int index = 0;
    for (i = 0; i < k; i++) {
        index ++;
        for (auto it = num.rbegin(); it != num.rend(); it++) {
            num_reverse += *it;
        }
        int flag = 0;
        //cout << "No." << i << " " << num << " " << num_reverse << endl;
        for (int i = 0; i < num.length(); i++) {
            int a = int(num[i] - '0');
            int b = int(num_reverse[i] - '0');
            //cout << a + b << endl;
            if (a + b > 10) {
                res.insert(0, 1, a + b - 10 + '0' + flag);
                flag = 1;
            }
            else {
                res.insert(0, 1, a + b + '0' + flag);
                flag = 0;
            }
        }
        if (flag == 1) res.insert(0, 1, '1');
        //cout << res << endl;
        num.clear();
        num_reverse.clear();
        num = res;
        res.clear();
        int k = 0; 
        int j = num.length() - 1;
        while (k < j) {
            if (num[k] == num[j]) {
                k++;
                j--;
            }
            else 
                break;
        }
        if (k == j) {
            break;
        }     
    }
    cout << num << endl;
    cout << index << endl;
    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

string s;
void add(string t) {
    int len = s.length(), carry = 0;
    for (int i = 0; i < len; i++) {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if (s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if (carry) s += '1';
    reverse(s.begin(), s.end());
}
int main(int argc, char const *argv[]) {
    int cnt, i;
    cin >> s >> cnt;
    for (i = 0; i <= cnt; i++) {
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t || i == cnt) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}