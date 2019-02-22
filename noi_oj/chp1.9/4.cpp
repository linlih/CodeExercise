#include <iostream>
#include <memory.h>

using namespace std;

typedef struct info {
    int final_s;
    int class_s;
    int paper;
    char name[21];
    char stu_c[1];
    char west[1];
}info;

int count_money(info* stu) {
    int money = 0;
    if (stu->final_s > 80 && stu->paper >= 1)
        money += 8000;
    if (stu->final_s > 85 && stu->class_s > 80)
        money += 4000;
    if (stu->final_s > 90)
        money += 2000;
    if ((char)(*stu->west) == (char)('Y') && stu->final_s > 85)
        money += 1000;
    if ((char)(*stu->stu_c) == (char)('Y') && stu->class_s > 80)
        money += 850;
    return money;
}

int main(int argc, char const *argv[])
{
    int n;
    info stu;
    memset(&stu, 0, sizeof(info));
    int total = 0;
    cin >> n;
    cin >> stu.name >> stu.final_s >> stu.class_s >> stu.stu_c >> stu.west >> stu.paper;
    int money = count_money(&stu);
    info tmp;
    int tmp_money;
    total += money;
    for (int i = 1; i < n; ++i) {
        cin >> tmp.name >> tmp.final_s >> tmp.class_s >> tmp.stu_c >> tmp.west >> tmp.paper;
        tmp_money = count_money(&tmp);
        if (money < tmp_money) {
            money = tmp_money;
            // 只要拷贝名字就可以了
            memset(stu.name, 0, 21);
            memcpy(stu.name, tmp.name, 21);
        }
        total += tmp_money;
        memset(&tmp, 0, sizeof(info));
    }
    
    cout << stu.name << endl;
    cout << money << endl;
    cout << total << endl;
    return 0;
}