/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif
    string str;
    cin >> str;
    int sum = 0;
    char spell[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < str.size(); ++i) {
        sum += (str[i] - '0');
    }
    string out = to_string(sum);
    for (int i = 0; i < out.size(); ++i) {
        if (i == 0) cout << spell[out[i]-'0'];
        else cout << " " << spell[out[i]-'0'];
    }
    return 0;
}