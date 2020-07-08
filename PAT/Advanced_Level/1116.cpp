/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, k;
    cin >> n;
    map<int, string> m;
    vector<bool> checked(10002);
    fill(checked.begin(), checked.end(), false);
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (i == 0) m[temp] = "Mystery Award";
        else if (isPrime(i+1)) m[temp] = "Minion";
        else m[temp] = "Chocolate";
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> temp;
        if (m.find(temp) != m.end())
            if (checked[temp] == false) {
                printf("%04d: %s\n", temp, m[temp].c_str());
                checked[temp] = true;
            }
            else
                printf("%04d: Checked\n", temp);
        else 
            printf("%04d: Are you kidding?\n", temp);
    }
    return 0;
}