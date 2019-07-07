/*
   问题描述：计算电梯上下行的时间，属于简单题
   解题思路：根据电梯层数差值的正负判断电梯运行方向，乘以相应的时间即可
 */
#include <bits/stdc++.h>

using namespace std;

#define STOP 5
#define UP   6
#define DOWN 4  

int main(int argc, char const *argv[])
{
    int m;
    int temp;
    int current_floor = 0;
    int total_time = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &temp);
        if (temp - current_floor > 0) {
            total_time += (temp - current_floor)*UP;
        }
        else {
            total_time += (current_floor - temp)*DOWN;
        }
        current_floor = temp;
    }   
    cout << total_time + STOP*m;
    return 0;
}