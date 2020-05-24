/*
   问题描述：
   解题思路： 几个测试样例过不了。原因：题意理解错了，两个字符串的字符相等还要保证位置是相同的。
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    char date[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string s1, s2;
    int c[26] = {0};
    cin >> s1;
    cin >> s2;
    int i;
    for (i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            c[s1[i] - 'A']++;
    }
    int cnt = 0;
    for (i = 0; i < s2.size(); i++) {
        if (s2[i] >= 'A' && s2[i] <= 'Z')
            if (c[s2[i] - 'A'] != 0) {
                if (cnt == 0)
                    cout << date[s2[i] - 'A'];
                if (cnt == 1) {
                    if (s2[i] >= '0' &&  s2[i]  <= '9')
                        printf(" %2s:", s2[i]);
                    else
                        printf(" %d:", s2[i] - 'A' + 10);
                }
                cnt ++;
            }
    }
    cin >> s1;
    cin >> s2;
    char c1[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'a' && s1[i] <= 'z' && s2[i] >= 'a' && s2[i] <= 'z')
            if (s1[i] == s2[i]) {
                printf("%02d", i);
                break;
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
int main(int argc, char const *argv[]) {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    char t[2];
    int pos, i = 0, j = 0;
    while(i < a.length() && i < b.length()) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            break;
        }
        i++;
    }
    i = i + 1;
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length()) {
        if (c[j] == d[j] && isalpha(c[j])) {
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    cout << week[t[0]- 'A'];
    printf(" %02d:%02d", m, pos);
    return 0;
}