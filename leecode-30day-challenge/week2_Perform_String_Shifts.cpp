/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        // 将左移和右移抵消
        int left = 0;
        int right = 0;
        for (int i = 0; i < shift.size(); i++) {
            if (shift[i][0] == 0) left += shift[i][1];
            else if (shift[i][0] == 1) right += shift[i][1];
        }
        string res = s;
        cout << left << " " << right << endl;
        int step;
        if (left - right > 0) {
            step = (left - right) % s.size();
            reverse(res.begin() + (step), res.end());
            reverse(res.begin(), res.begin() + (step));
            reverse(res.begin(), res.end());
        }
        else if (right - left > 0) {
            step = (right - left) % s.size();
            reverse(res.begin(), res.end() - (step));
            reverse(res.end() - (step), res.end());
            reverse(res.begin(), res.end());
        }
        return res;
    }
};

// 这个方式不见得一定好，每次都要移动string，上面的实现方法相对更好一点，只需要最终旋转一次string即可
class Solution_Best {
public:
    string stringRotation(string s, vector<vector<int>>& rotation) {
        int n = s.length();
        for(auto & r : rotation) {
            int d = r[0], cnt = r[1] % n;
            if (d == 0) rotate(s.begin(), s.begin() + cnt, s.end());
            else rotate(s.begin(), s.begin() + n - cnt, s.end());
        }
        return s;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    // string s("abcdefg");
    // vector<vector<int>> shift;
    // vector<int> tmp;

    // tmp.push_back(1);
    // tmp.push_back(1);
    // shift.push_back(tmp);
    // tmp.clear();
    // tmp.push_back(1);
    // tmp.push_back(1);
    // shift.push_back(tmp);
    // tmp.clear();
    // tmp.push_back(0);
    // tmp.push_back(2);
    // shift.push_back(tmp);
    // tmp.clear();
    // tmp.push_back(1);
    // tmp.push_back(3);
    // shift.push_back(tmp);


//"yisxjwry"
//[[1,8],[1,4],[1,3],[1,6],[0,6],[1,4],[0,2],[0,1]]

    string s("yisxjwry");
    vector<vector<int>> shift;
    vector<int> tmp;

    tmp.push_back(1);
    tmp.push_back(8);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(4);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(3);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(6);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(6);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(4);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(2);
    shift.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(1);
    shift.push_back(tmp);

    cout << sol.stringShift(s, shift) << endl;

    return 0;
}