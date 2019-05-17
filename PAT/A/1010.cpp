/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef struct data  {
    int store;
    int total_price;
    double price;
}data;

bool myCompare(data& d1, data& d2) {
    return d1.price > d2.price;
}

int main(int argc, char const *argv[])
{
    int num, total;
    double sell = 0;
    cin >> num >> total;
    data *in = new data[num];
    for (int i = 0; i < num; i++) {
        cin >> in[i].store;
        cin >> skipws;
    }
    for (int i = 0; i < num; i++) {
        cin >> in[i].total_price;
        in[i].price = (in[i].total_price *1.0) / in[i].store;
        cin >> skipws;
    }
    sort(in, in+num, myCompare);
    // for (int i = 0; i < num; i++ ){
    //     cout << in[i].store << " " << in[i].price << endl;
    // }
    int i = 0;
    while (total != 0) {
        if (total >= in[i].store) {
            total -= in[i].store;
            sell += in[i].total_price;
        }
        else { 
            sell += (in[i].price * total);
            total = 0;
        }
        i++;
    }
    cout << setprecision(2) << fixed << sell << endl;
    return 0;
}