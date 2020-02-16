/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

struct node {
    int poptime, endtime;
    queue<int> q;
};

int main(int argc, char const *argv[])
{
    int n, m, k, q, index = 1;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    vector<int> time(k + 1), result(k + 1);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &time[i]);
    }
    vector<node> window(n + 1);
    vector<bool> sorry(k + 1, false);

    // 根据黄线内可以服务的人数m，依次添加到窗口中
    // 这里还有一个限制条件，不能操作实际的客户数目
    // 因为有的场景是客户数少于可服务的人数
    // 加上窗口数目n和在每个窗口黄线内等待的人数M
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) { // 总共有n个窗口
            if (index <= k) {
                window[j].q.push(time[index]); // 存入当前客户需要花费的时间
                if (window[j].endtime >= 540)  // 超过下班时间 
                    sorry[index] = true;
                window[j].endtime += time[index];
                if (i == 1)
                    window[j].poptime = window[j].endtime;
                result[index] = window[j].endtime;
                index ++;
            }
        }
    }
    while(index <= k) {
        // 找到最早服务完成的窗口
        int tempmin = window[1].poptime, tempwindow = 1;
        for (int i = 2; i <= n; i++) {
            if (window[i].poptime < tempmin) {
                tempwindow = i;
                tempmin = window[i].poptime;
            }
        }
        // 服务这个客户
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);
        // 取出下一个客户
        window[tempwindow].poptime += window[tempwindow].q.front();
        if (window[tempwindow].endtime >= 540)
            sorry[index] = true;
        window[tempwindow].endtime += time[index];
        result[index] = window[tempwindow].endtime;
        index ++;
    }
    for (int i = 1; i <= q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if (sorry[query] == true)
            printf("Sorry\n");
        else 
            printf("%02d:%02d\n", (minute + 480) / 60, (minute + 480) % 60);
    }
    return 0;
}