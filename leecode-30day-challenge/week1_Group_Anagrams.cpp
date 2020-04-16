/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// 这个方法会超时，最后一个test case超时
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;
//         string tmp1, tmp2;
//         int index = 0;
//         int i, j, k;

//         for (i = 0; i < strs.size(); i++) {
//             tmp1 = strs[i];
//             sort(tmp1.begin(), tmp1.end());
//             bool found = false;
//             for (j = 0; j < res.size(); j++) {
//                 for (k = 0; k < res[j].size(); k++) {
//                     tmp2 = res[j][k];
//                     sort(tmp2.begin(), tmp2.end());
//                     if (tmp1 == tmp2) {
//                         found = true;
//                         break;
//                     }
//                 }
//                 if (found) break;
//             }
//             if (found)
//                 res[j].push_back(strs[i]);
//             else {
//                 res.push_back(vector<string>());
//                 res[index].push_back(strs[i]);
//                 index ++;
//             }
//         }
      
//         for (auto it = res.begin(); it != res.end(); it++) {
//             sort(it->begin(), it->end());
//         }
//         return res;
//     }
// };

// 修改过后可以通过101个测试样例，但是还是超时
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        string tmp1, tmp2;
        int index = 0;
        int i, j;
        //int k;
        vector<string> ordered;
        for (i = 0; i < strs.size(); i++) {
            tmp1 = strs[i];
            sort(tmp1.begin(), tmp1.end());
            bool found = false;
            for (j = 0; j < ordered.size(); j++) {
                // for (k = 0; k < res[j].size(); k++) {
                //     tmp2 = res[j][k];
                //     sort(tmp2.begin(), tmp2.end());
                //     if (tmp1 == tmp2) {
                //         found = true;
                //         break;
                //     }
                // }
                tmp2 = ordered[j];
                if (tmp1 == tmp2) {
                    found = true;
                    break;
                }
                //if (found) break;
            }
            if (found)
                res[j].push_back(strs[i]);
            else {
                res.push_back(vector<string>());
                res[index].push_back(strs[i]);
                tmp2 = strs[i];
                sort(tmp2.begin(), tmp2.end());
                ordered.push_back(tmp2);
                index ++;
            }
        }
      
        for (auto it = res.begin(); it != res.end(); it++) {
            sort(it->begin(), it->end());
        }
        return res;
    }
};

// 这个实现方法运行时间为：52ms
class Solution_2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m; // 创建一个map信息，这个map不排序
        int count = -1;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            if (m.count(t)) {
                res[m[t]].push_back(str);
            } else {
                //m[t] = res.size(); // 0 1 2 3 这样的顺序
                m[t] = ++count; // 0 1 2 3 这样的顺序
                //res.push_back({});
                res.push_back({str});
            }
        }
        return res;
    }
};

// 最优解和上面的Solution_2的实现方法是一样的，但是这个实现只有：20ms
// 导致几十毫秒的差距的原因：和评测环境有关，将最优解直接提交，测试结果也要60ms
class Solution_Best {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> anagramMap;
        vector<vector<string>> result;
        int count = -1;
        for (auto str: strs) {
            string sig = str;
            sort(sig.begin(), sig.end());
            if (anagramMap.count(sig)) {
                result[anagramMap[sig]].push_back(str);
            } else {
                result.push_back({str});
                anagramMap[sig] = ++ count;
            }
        }
        return result;
    }
}
// 唯独多了一个这个代码
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    vector<vector<string>> res;

    res = sol.groupAnagrams(strs);

    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto j = it->begin(); j != it->end(); j++) cout << *j << " " ;
        cout << endl;
    }

    return 0;
}