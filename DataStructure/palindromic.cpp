#include "bits/stdc++.h"

using namespace std;


// 参考自：有什么浅显易懂的Manacher Algorithm讲解？ - windliang的回答 - 知乎
// https://www.zhihu.com/question/37289584/answer/465656849

string preProcessing(string s) {
    int n = s.size();
    if (n == 0) return "^$";
    string ret = "^";
    for (int i = 0; i < n; ++i) {
        ret += "#";
        ret += s[i];
    }
    ret += "#$";
    return ret;
}

string longestPalindromic(string s) {
    string T = preProcessing(s);
    int n = T.size();
    int P[n];
    int C = 0, R = 0;

    int startIndex = 0;
    int maxLength = 0;

    for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2 * C - i;
        if (R > i) {
            P[i] = min(P[i_mirror], R - i);
        } else {
            P[i] = 0;
        }
        while(T[i + 1 + P[i]] ==  T[i - 1 - P[i]])
            P[i]++;
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        if (maxLength < P[i]) {
            startIndex = i;
            maxLength = P[i];
        }
    }
    return string(s, (startIndex - maxLength)/2, maxLength);
}


int main() {

    cout << longestPalindromic("cbcbcbde") << endl;
    return 0;
}