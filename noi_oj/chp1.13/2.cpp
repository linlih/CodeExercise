#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int date;
    cin >> date;

    for (int i = 0; i < 12; ++i) {
        // 判断day 13是不是星期 5
        if ((date - 2) == 5)
            cout << i+1 << endl;
        // 计算下个月第一天是星期几
        date = (day[i]%7 + date);
        if (date > 7)
            date %= 7;
        cout << "date:" << date << endl;
    }
    return 0;
}