/*
 * 运行数据： ms  KB
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    long sum = 0;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        sum += (long)(str[i] - '0');
    }
    char spell[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string output = to_string(sum);
    cout << spell[output[0] - '0'];
    for (int i = 1; i < output.length(); ++i) {
        cout << " " << spell[output[i] - '0'];
    } 
    return 0;
}