/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>

#define CLK_TCK_T 100

using namespace std;
int main(int argc, char const *argv[])
{
    long c1, c2;
    cin >> c1 >> c2;
    long s = (c2 - c1)/CLK_TCK_T;
    int hour = s/3600;
    int minute = (s-hour*3600)/60;
    int second = s-hour*3600 - minute * 60;
    cout << setw(2) <<setfill('0') << hour << ":" << setw(2) <<setfill('0') << minute << ":" <<  setw(2) <<setfill('0') <<second << endl;
    return 0;
}