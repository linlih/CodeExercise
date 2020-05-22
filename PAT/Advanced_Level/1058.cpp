/*
   问题描述：
   解题思路： 一个测试样例没过，没有测试样例，找不到原因
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int g1, s1, k1;
    int g2, s2, k2;
    string a, b;
    cin >> a >> b;
    char tmp[10];
    int index = 0;
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            if (cnt == 0) g1 = atoi(tmp);
            if (cnt == 1) s1 = atoi(tmp);
            memset(tmp, 0, 10);
            cnt++;
            index = 0;
            continue;
        }
        tmp[index] = a[i];
        index ++;
        if (i == (a.size() - 1)) k1 = atoi(tmp);
    }
    index = 0;
    cnt = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == '.') {
            if (cnt == 0) g2 = atoi(tmp);
            if (cnt == 1) s2 = atoi(tmp);
            memset(tmp, 0, 10);
            cnt++;
            index = 0;
            continue;
        }
        tmp[index] = b[i];
        index ++;
        if (i == (b.size() - 1)) k2 = atoi(tmp);
    }

    int g3, s3, k3;
    // 17 s  1 g
    // 29 k  1 s
    k3 = k1 + k2;
    int ku = k3 / 29;
    k3 = k3 % 29;
    s3 = ku + s1 + s2;
    int su = s3 / 17;
    s3 = s3 % 17;
    g3 = su + g1 + g2;
    
    cout << g3 << "." << s3 << "." << k3 << endl;
    return 0;
}

/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
    int a1, b1, c1, a2, b2, c2, a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    c = c1 + c2;
    b = b1 + b2 + c / 29; c = c % 29;
    a = a1 + a2 + b / 17; b = b % 17;
    printf("%d.%d.%d", a, b, c);
    return 0;
}