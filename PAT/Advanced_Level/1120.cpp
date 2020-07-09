/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    string s;
    int sum;
    int temp;
    set<int> out;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        s = to_string(temp);
        sum = 0;
        for (int j = 0; j < s.size(); ++j) {
            sum += (s[j] - '0');
        }
        out.insert(sum);
    }
    cout << out.size() << endl;
    int i = 0;
    for (auto it:out) {
        if (i == 0) {
            cout << it; i++;
        }
        else cout << " " << it;
    }
    return 0;
}