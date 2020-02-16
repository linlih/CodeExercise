/ 正确的代码 牛客网：https://www.nowcoder.com/pat/1/problem/3992
// #include<cstdio>
// #include <iostream>
// #include<cstring>
// #include<string>
// #include<map>
// using namespace std;
// map<string, int> mp;
// int a[2000][4], have[102];
// char c[4] = { 'A','C','M','E' };
// int main() {
//     int n, m;
//     char s[10];
//     scanf("%d%d", &n, &m);
//     for (int i = 0; i < n; i++) {
//         scanf("%s%d%d%d", s, &a[i][1], &a[i][2], &a[i][3]);
//         a[i][0] = (a[i][1] + a[i][2] + a[i][3]) / 3;
//         mp[s] = i;
//     }
//     for (int i = 0; i < 4; i++) {
//         memset(have, 0, sizeof(have));
//         // 利用数组计算排名
//         for (int j = 0; j < n; j++) {
//             have[a[j][i]]++;
//             //cout << "add : " << a[j][i] << " " << have[a[j][i]] << endl;
//         }
//         for (int j = 100; j >= 0; j--) {
//             have[j] += have[j + 1]; 
//         }
//         // a[j][i] = 90
//         for (int j = 0; j < n; j++) {
//             //cout << "test: " << a[j][i] << " " << have[a[j][i]] << endl;
//             a[j][i] = have[a[j][i] + 1] + 1; // ？
//         }
//         break;
//     }
//     for (int i = 0; i < m; i++) {
//         scanf("%s", s);
//         auto it = mp.find(s);
//         if(it==mp.end()){
//             printf("N/A\n");
//         }
//         else {
//             int t = 0;
//             for (int j = 1; j < 4; j++) {
//                 if (a[it->second][j] < a[it->second][t]) {
//                     t = j;
//                 }
//             }
//             printf("%d %c\n", a[it->second][t], c[t]);
//         }
//     }
//     return 0;
// }