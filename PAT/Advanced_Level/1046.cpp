/*
   问题描述：
   解题思路： 
   有一个测试样例超时了
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int *arr = new int[n+1];
    int total = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
    }
    int m;
    scanf("%d", &m);
    int s, e;
    int tmp;
    int res1 = 0, res2 = 0, res;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        if (s > e) {
            tmp = s;
            s = e;
            e = tmp;
        }
        for (int j = s; j < e; j++) 
            res1 += arr[j];
        // for (int k = e; k != s; k = (k+1)%n)
        //     res2 += arr[k];
        // res = res1<res2?res1:res2;
        res = min(res1, total - res1);
        cout << res << endl;
        res1 = res2 = 0;
    }
    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    vector<int> dis(n+1);
    int sum = 0, left, right, cnt;
    for (int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        sum += temp;
        dis[i] = sum;
    }
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &left, &right);
        if (left > right)
            swap(left, right);
        int temp = dis[right - 1] - dis[left - 1];
        printf("%d\n", min(temp, sum - temp));
    }
    return 0;
}