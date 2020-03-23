/*
   问题描述：
   解题思路： 
   没看懂题目，什么意思，要走遍八个城市吗，还是怎样？
 */
#include <bits/stdc++.h>

using namespace std;

const int inf = 99999999;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}

int main(int argc, char const *argv[]) {
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n+1);
    sta[0] = {0.0, d};
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double now_dis = 0.0, max_dis = 0.0, now_price = 0.0, total_price = 0.0, left_dis = 0.0;
    if (sta[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else {
        now_price = sta[0].price;
    }
    while(now_dis < d) {
        max_dis = now_dis + cmax*davg;
        double min_price_dis = 0, min_price = inf;
        int flag = 0;
        for (int i = 1; i <= n && sta[i].dis <= max_dis; i++) {
            if (sta[i].dis <= now_dis) continue;
            if (sta[i].price < now_price) {
                total_price += (sta[i].dis - now_dis - left_dis) * now_price / davg;
                left_dis = 0.0;
                now_price = sta[i].price;
                now_dis = sta[i].dis;
                flag = 1;
                break;
            }
            if (sta[i].price < min_price) {
                min_price = sta[i].price;
                min_price_dis = sta[i].dis;
            }
        }
        if (flag == 0 && min_price != inf) {
            total_price += (now_price * (cmax - left_dis / davg));
            left_dis = cmax * davg - (min_price_dis - now_dis);
            now_price = min_price;
            now_dis = min_price_dis;
        }
        if (flag == 0 && min_price == inf) {
            now_dis += cmax * davg;
            printf("The maximum travel distance = %.2f", now_dis);
            return 0;
        }
    }
    
    printf("%.2f", total_price);
    return 0;
}