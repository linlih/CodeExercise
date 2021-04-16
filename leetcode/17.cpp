/*******************************************************************
  > File Name    : 17.cpp
  > Author       : linlh
  > Created  Time: 2021.04.01 17:23
  > Modified Time: 2021.04.01 22:42
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    map<int, string> numStr;

    vector<string> res;
    string tmp;
    vector<string> letterCombinations(string digits) {
        numStr[2] = "abc";
        numStr[3] = "def";
        numStr[4] = "ghi";
        numStr[5] = "jkl";
        numStr[6] = "mno";
        numStr[7] = "pqrs";
        numStr[8] = "tuv";
        numStr[9] = "wxyz";
        digit(0, digits, "");
        if (res.size() == 1 && res[0] == "") {
            vector<string> tmp;
            return tmp;
        }
        return res;
    }
    void digit(int i, string& digits, string tmp) {
        if (i == digits.size()) {
            res.push_back(tmp);
            return;
        }
        char c = digits[i];
        string letters = numStr[c-'0'];
        for (auto it : letters) {
            digit(i+1, digits, tmp + it);
        }
    }
};

int main()
{
    string digits("23");
    for (auto it:Solution().letterCombinations(digits)) {
        cout << it << " "; 
    }
    cout << endl;
    return 0;
}
