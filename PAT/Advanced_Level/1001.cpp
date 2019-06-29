/*
 * 运行数据： 3 ms  KB
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[])
{
    long a, b;
    cin >> a >> b;
    long c = a + b;
    char res[100] = {0};
    //itoa(c, res, 10);
    snprintf(res, sizeof(res), "%d", c);
    int cnt = 0;
    stack<char> s;
    for (int i = strlen(res) - 1; i >= 0; --i) {
        if (cnt%3==0 && cnt > 0  && res[i] != '-') {
            s.push(',');
            //cout << "cnt" << cnt << endl;
        }
        cnt ++;
        s.push(res[i]);
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}