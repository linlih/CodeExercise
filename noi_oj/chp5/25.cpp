#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stack>

using namespace std;

char* my_itoa(int value, char* string, int base) {
    int va = value;
    int tmp = 1;
    char *str = string;
    if (va == 0) {
        *str++ = 0;
        *str = '\0';
        return string;
    }
    if (base < 2 || base > 32) {
        *str = '\0';
        return string;
    }

    stack<char> cmd;
    while (tmp) {
        tmp = va / base;
        int a = va % base;
        if (a < 10) { // 小于10的话直接用数值表示
            cmd.push(a + '0');
        }
        else {
            cmd.push(a - 10 + 'a');
        }
        va = tmp;
    }
    while (!cmd.empty()) {
        *str++ = cmd.top();
        cmd.pop();
    }
    *str = '\0';
    return string;
}

int main(int argc, char const *argv[])
{
    char nine[100] = {'\0'};
    char seven[100] = {'\0'};
    // 数值的取值范围是从九进制的100(81)~7进制777(399)
    for (int i = 81; i < 400; ++i) {
        my_itoa(i, nine, 9);
        my_itoa(i, seven, 7);
        if (seven[2] == nine[0] && seven[1] == nine[1] && seven[0] == nine[2]) {
            cout << i << endl;
            cout << seven << endl;
            cout << nine << endl;
        }
    }
    
    return 0;
}