/*******************************************************************
  > File Name    : 5.cpp
  > Author       : linlh
  > Created  Time: 2021.03.30 22:58
  > Modified Time: 2021.03.30 23:11
 *******************************************************************/

#include "bits/stdc++.h"
using namespace std;
int main()
{
    char word[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", 
                         "nine"};
    string str;
    cin >> str;
    int res = 0;
    for (auto it:str) {
        res += (it - '0');
    }
    string result = to_string(res);
    for (auto it = result.begin(); it != result.end(); it++) {
        if (it == result.begin()) cout << word[*it - '0'];
        else  cout << " " << word[*it - '0'];  
    }
    return 0;
}
