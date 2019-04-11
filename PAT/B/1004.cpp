/*
 * 运行数据： 4 ms  488 KB
 */

#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    char c[26] = {0};
    int i, j, week_i, hour_i;
    int index = 0;

    for (i = 0; i < s1.length(); i++)
        for (j = 0; j < s2.length(); j++)
            if (s1[i] == s2[j] && (s1[i] >= 'A' && s1[i] <= 'Z')) {
                week_i = (int)(s1[i] - 'A');
                //cout << i <<" xx "<< week_i << endl;
                goto next;
            }
next:
    i++;
    int k = j++;
    for (; i < s1.length(); i++)
        for (k = j++; k < s2.length(); k++)
            if (s1[i] == s2[k]) {
                if ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'Z')) {
                    if (s1[i] >= '0' && s1[i] <= '9')
                        hour_i = (int)(s1[i] - '0');
                    else
                        hour_i = (int)(s1[i] - 'A') + 10;
                    goto next1;
                }
            }
next1:
    s1.clear();
    s2.clear();
    cin >> s1;
    cin >> s2;
    int min_j = 0;

    int l = (s1.length() < s2.length()?s1.length():s2.length());
    for (i = 0; i < l; ++i) {
        if (s1[i] == s2[i] && s1[i] >= 'a' && s1[i] <= 'z') {
            min_j = i;
            goto end;
        }
    }

end:
    if (hour_i > 10 && min_j > 10)
        cout << week[week_i] << " " << hour_i << ":" << min_j << endl;
    else if (hour_i < 10 && min_j > 10)
        cout << week[week_i] << " 0" << hour_i << ":" << min_j << endl;
    else if (hour_i > 10&& min_j < 10)
        cout << week[week_i] << " " << hour_i << ":0" << min_j << endl;
    else 
        cout << week[week_i] << " 0" << hour_i << ":0" << min_j << endl;

    return 0;
}