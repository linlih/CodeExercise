/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> cnt(50010, 0);
bool cmp(pair<int, int> &n1, pair<int, int> &n2) {
    if (n1.second != n2.second)
        return n1.second >= n2.second;
    else 
        return n1.first < n2.first;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, k;
    cin >> n >> k;
    int temp;
    scanf("%d", &temp);
    cnt[temp]++;
    vector<pair<int, int> > out;// first item, second cnt
    out.push_back({temp, cnt[temp]});
    for (int i = 1; i < n; ++i) {
        scanf("%d", &temp);

        cout << temp << ":";
        for (auto it: out) {
           cout << " " << it.first;
        }
        cout << endl;

        cnt[temp]++;
        //cout << "cnt: " << temp << " " << cnt[temp] << endl;
        bool found = false;
        // for (auto it : out) {
        //     if (it.first == temp) {
        //         it.second = cnt[temp];
        //         cout << "it "<< it.first << ":" << it.second << endl;
        //         found = true;
        //     }
        //     //it.second = cnt[it.first];
        // }
        for (int i = 0; i < k; ++i) {
            if (out[i].first == temp) {
                out[i].second = cnt[temp];
                found = true;
            }
        }
        if (!found) {
            if (out.size() < k)
                out.push_back({temp, cnt[temp]});
            else {
                if (cnt[temp] != out[k-1].second ){
                    if (cnt[temp] > out[k-1].second)
                        out[k-1] = {temp, cnt[temp]};
                }
                else {
                    if (temp < out[k-1].first)
                        out[k-1] = {temp, cnt[temp]};
                }
            }
        }
        // cout << "after found";
        // for (auto it: out) {
        //    cout << " " << it.first <<":" << it.second;
        // }
        // cout << endl;
        sort(out.begin(), out.end(), cmp);
    }
    return 0;
}