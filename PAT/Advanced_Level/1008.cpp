/*
   问题描述：
   解题思路： 
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