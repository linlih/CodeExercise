/*
   问题描述：
   解题思路： 
   两个测试样例错误
 */
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> lot;
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        auto it = lot.find(tmp);
        if (it == lot.end()) 
            lot.insert(make_pair(tmp, 1));
        else 
            lot[tmp] += 1;
    }
    //reverse(lot.begin(), lot.end());
    int res = -1;
    for (auto i = lot.begin(); i != lot.end(); i++) {
        if (i->second == 1) {
            res = i->first;
        }
        // cout << i->first << " " << i->second << endl;
    }
    if (res == -1)
        cout << "None";
    else
        cout << res;
    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

int a[100001], m[100001];
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (m[a[i]] == 1) {
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}