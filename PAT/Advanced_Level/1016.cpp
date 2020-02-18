/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    string name;
    int status, month, time, day, hour, minute;
};

// 按照题目要求的，名字不同的按照字母的顺序
bool cmp(node a, node b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}

// 从第0小时开始计算价格
double billFromZero(node call, int *rate) {
    // rate[0] ~ rate[23]中存了0~23的24小时每个小时费用，rate[24]是24个小时费用的加和
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
    for (int i = 0; i < call.hour; i++) {
        total += rate[i] * 60;
    }
    return total / 100.0;
}

int main(int argc, char const *argv[])
{
    int rate[25] = {0}, n;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i]; // rate[24]用来存储一天的费用cent/minute
    }
    scanf("%d", &n);
    vector<node> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? 1:0;
        // 遇到时间的问题，一般都要转化成分或者秒的形式
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node> > custom;
    for (int i = 1; i < n; i++) {
        if (data[i].name == data[i - 1].name && data[i-1].status == 1 && data[i].status == 0) {
            custom[data[i - 1].name].push_back(data[i - 1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    for (auto it : custom) {
        vector<node> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].month);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}


