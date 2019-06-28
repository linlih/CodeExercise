/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct person {
    char name[10];
    int year;
    int month;
    int day;
    int valid;
}person;

int to_num(char *c) {
    int l = strlen(c);
    int base = 1;
    int num = 0;
    for (int i = (l - 1); i >= 0; i--) {
        num += (int)(c[i] - '0')*base;
        base *= 10;
    }
    return num;
}

bool my_compare(person& p1, person& p2) {
    if (p1.year > p2.year) 
        return true;
    else if (p1.year == p2.year) {
        if (p1.month > p2.month)
            return true;
        else if (p1.month == p2.month) {
            if (p1.day > p2.day)
                return true;
            else 
                return false;
        }
        else 
            return false;
    }
    else 
        return false;
}

bool valid_birth(person &p) {
    if (((2014 - p.year) > 200) || (p.year > 2014)) {
        return false;
    }
    if ((2014 - p.year) == 200) {
        if (p.month < 9)
            return false;
        else if (p.month == 9) {
            if (p.day < 6) 
                return false;
        }
        return true;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    person *persons = new person[n];
    for (int i = 0; i < n; ++i) {
        char tmp_birth[20];
        cin >> persons[i].name >> tmp_birth;
        char tmp_year[5] = {0};
        char tmp_month[3] = {0};
        char tmp_day[3] = {0};
        for (int j = 0; j < 4; j++) {
            tmp_year[j] = tmp_birth[j];
        }
        for (int j = 0; j < 2; j++) {
            tmp_month[j] = tmp_birth[j+5];
        }
        for (int j = 0; j < 2; j++) {
            tmp_day[j] = tmp_birth[j+8];
        }
        //cout << tmp_year << " " << tmp_month << " " << tmp_day << endl;
        persons[i].year = to_num(tmp_year);
        persons[i].month = to_num(tmp_month);
        persons[i].day = to_num(tmp_day);
        persons[i].valid = 0;
    }

    sort(persons, persons + n, my_compare);
    
    int valid_cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (valid_birth(persons[i])) {
            valid_cnt++;
            persons[i].valid = 1;
            //cout << "valid:" << persons[i].name <<endl;
        }
    }

    cout << valid_cnt << " ";
    int i = 0;
    while (persons[i].valid == 0)
        i ++;
    cout << persons[i+valid_cnt-1].name << " ";
    cout << persons[i].name << endl;
    return 0;
}