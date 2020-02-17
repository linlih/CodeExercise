/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

// 定义客户节点，包含客户到达时间和要求服务时间
struct node {
    int come, time;
}tempcustomer;

// 按照客户来的时间，从小到大排序
bool cmp1(node a, node b) {
    return a.come < b.come;
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> custom;
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int cometime = hh * 3600 + mm * 60 + ss;
        if (cometime > 61200) continue;
        tempcustomer = {cometime, time*60};
        custom.push_back(tempcustomer);
    }
    // 按照客户来的时间排序
    sort(custom.begin(), custom.end(), cmp1);
    vector<int> window(k, 28800);
    double result = 0.0;
    // 遍历处理所有用户
    for (int i = 0; i< custom.size(); i++) {
        int tempindex = 0, minfinish = window[0];
        for (int j = 1; j < k; j++) {
            if (minfinish > window[j]) {
                minfinish = window[j];
                tempindex = j;
            }
        }
        // 如果客户比当前窗口的空闲时间来得晚, 则直接是以客户来的时间加上服务时间
        if (window[tempindex] <= custom[i].come) {
            window[tempindex] = custom[i].come + custom[i].time;
        }
        // 如果客户比窗口来的早，那需要等待时间
        else {
            result += (window[tempindex] - custom[i].come);
            window[tempindex] += custom[i].time;
        }
    }
    if (custom.size() == 0)
        printf("0.0");
    else 
        printf("%.1f", result / 60.0 / custom.size());
    return 0;
}