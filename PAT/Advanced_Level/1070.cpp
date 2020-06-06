/*
   问题描述：
   解题思路： 有一个测试用例答案错误。错误的原因在于ton变量也要是float才可以
 */
#include <bits/stdc++.h>

using namespace std;

struct product {
    float ton;
    float price;
    float s_price;
};

bool cmp(product &p1, product &p2) {
    return p1.s_price > p2.s_price;
}
int main(int argc, char const *argv[]) {
    int n, d;
    map<int, int> inventory;
    cin >> n >> d;
    product *pro = new product[n];
    for (int i = 0; i < n; ++i) {
        scanf("%f", &pro[i].ton);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%f", &pro[i].price);
    }
    for (int i = 0; i < n; ++i) {
        pro[i].s_price = pro[i].price/pro[i].ton;
    }
    sort(pro, pro+n, cmp);
    float total = 0;

    for (int i = 0; i < n; ++i) {
        if (d > pro[i].ton) {
            total += pro[i].price;
            d -= pro[i].ton;
        }
        else {
            total += (pro[i].s_price*d);
            break;
        }
    }
    printf("%.2f\n", total);
    return 0;
}



// /*
//    问题描述：
//    解题思路： 
//  */
// #include <bits/stdc++.h>

// using namespace std;
// struct mooncake {
//     float mount, price, unit;
// };

// int cmp(mooncake a, mooncake b) {
//     return a.unit > b.unit;
// }

// int main(int argc, char const *argv[]) {
//     int n, need;
//     cin >> n >> need;
//     vector<mooncake> a(n);
//     for (int i = 0; i < n; ++i) scanf("%f", &a[i].mount);
//     for (int i = 0; i < n; ++i) scanf("%f", &a[i].price);
//     for (int i = 0; i < n; ++i) a[i].unit = a[i].price / a[i].mount;
//     sort(a.begin(), a.end(), cmp);
//     float result = 0.0;
//     for (int i = 0; i < n; ++i) {
//         if (a[i].mount <= need) {
//             result += a[i].price;
//         }
//         else {
//             result += a[i].unit * need;
//             break;
//         }
//         need -= a[i].mount;
//     }
//     printf("%.2f", result);
//     return 0;
// }