// /*
//    问题描述：
//    解题思路： 这道题是大数加法
//  */
// #include <bits/stdc++.h>

// using namespace std;

// long long tonum(string s) {
//     long long res = 0;
//     long index = 1;s
//     for (int i = s.size() - 1; i >= 0; --i) {
//         res += (index * (s[i]-'0'));
//         index*=10;
//     }
//     return res;
// }

// bool judge(string s) {
//     for (int i = 0; i < s.size()/2; ++i)
//         if (s[i] != s[s.size() - 1 - i])
//             return false;
//     return true;
// }

// int main(int argc, char const *argv[]) {
//     freopen("input.txt","r",stdin);
//     long long n;
//     cin >> n;
//     for (int i = 0; i < 10; ++i) {
//         string num = to_string(n);
//         reverse(num.begin(), num.end());
//         long long re_n = tonum(num);
//         long long res = n + re_n;
//         cout << n << " + " << num << " = " << res << endl;
//         if (judge(to_string(res))) {
//             cout << res << " is a palindromic number." << endl;
//             return 0;
//         }
//         n = res;
//     }
//     cout << "Not found in 10 iterations." << endl;
//     return 0;
// }

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct bign {
    int d[1010];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(string s) {
    bign a;
    for (int i = 0; i < s.size(); ++i) {
        a.d[i] = (s[i] - '0');
        a.len++;
    }
    return a;
}

bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; ++i) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp%10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bool judge(bign a) {
    for (int i =0; i <a.len/2; ++i) {
        if (a.d[i] != a.d[a.len - 1 - i])
            return false;
    }
    return true;
}

void print_big(bign a) {
    for (int i = a.len - 1; i >= 0; --i)
        cout << a.d[i];
}

string tostr(bign a) {
    string res;
    for (int i = 0; i < a.len; ++i) {
        res.push_back(a.d[i] + '0');
    }
    return res;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    for (int i = 0; i < 10; ++i) {
        bign a = change(s);
        // 这里非常重要，因为输入的这个数可能就已经是回文数了
        // 这里的判断包含了三个测试点
        if (i == 0) {
            if (judge(a)) {
                print_big(a);
                cout << " is a palindromic number." << endl;
                return 0;
            }
        }
        reverse(s.begin(), s.end());
        bign b = change(s);
        bign c = add(a, b);
        if (i == 0) {
            print_big(b);
            cout << " + ";
            print_big(a);
            cout << " = ";
        }
        else {
            print_big(a);
            cout << " + ";
            print_big(b);
            cout << " = ";
        }
        print_big(c);
        cout << endl;
        if (judge(c)) {
            print_big(c);
            cout << " is a palindromic number." << endl;
            return 0;
        }
        s = tostr(c);
    }
    cout << "Not found in 10 iterations." << endl;
    return 0;
}