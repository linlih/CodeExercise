/*
   问题描述：
   解题思路： ref: https://blog.csdn.net/Exupery_/article/details/100698664
 */
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2, sqr = sqrt(x); i <= sqr; ++i) {
        if (x %  i == 0) return false;
    } 
    return true;
}

int gcd(int a, int b) {
    return (b == 0)?abs(a):gcd(b, a % b);
}

int digitSum(int x) {
    int sum = 0;
    string s = to_string(x);
    for (int i = 0; i < s.length(); ++i) {
        sum += (s[i] - '0');
    }
    return sum;
}

struct record{
    int sum, val;
    record(int v, int n):val(v), sum(n) {}
    bool operator<(record &x) {
        if (sum != x.sum) return sum > x.sum;
        else return val < x.val;
    }
};

vector<record> r;
// 核心
// sum是每个数值位的和，val是实际的数值
void dfs(int sum, int val, int left, int target) {
    if (left == 0 && sum == target) {
        int n = digitSum(val + 1), g = gcd(sum, n);
        if (g > 2 && isPrime(g)) r.push_back(record(val, n));
    }
    else if (left > 0)  {
        for (int i = 0; i <= 9; ++i) {
            // 新加入的数值位得到的新数值的每一位求和要小于target
            // 余下的所有位数的最大值都取9，要大于target才行
            if (sum + i + (left - 1)*9 >= target && sum + i <= target) // 剪枝条件
                dfs(sum + i, val * 10 + i, left - 1, target);
        }
    }
}

int main(int argc, char const *argv[]) {
    freopen("input.txt","r",stdin);
    int n, k, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        r.clear();
        cin >> k >> m;
        cout << "Case "<< i << endl;

        // method 1 start
        //for (int j = 1; j <= 9; ++j) dfs(j, j, k - 1, m);
        // method 1 end

        // method 2 start 
        // ref: https://blog.csdn.net/allisonshing/article/details/104236658
        int a = (int)pow(10, k-3);
        int b = a * 10;
        int c = 0, d = 0;
        for (int x = a; x < b; ++x) {
            c = x*100+99;
            d = digitSum(c + 1);
            if (digitSum(c) == m &&isPrime(gcd(d, m))) {
                r.push_back(record(c, d));
            }
        }
        // method 2 end

        if (r.empty()) cout << "No Solution"  << endl;
        else {
            sort(r.begin(), r.end());
            for (int j = 0; j < r.size(); ++j)
                cout << r[j].sum << " " << r[j].val << endl;
        }
    }
    return 0;
}