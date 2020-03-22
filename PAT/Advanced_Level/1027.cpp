/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string out;
    out.push_back('#');

    int a;1
    string tmp;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &a);
        while(a != 0) {
            if (a % 13 < 10)
                tmp.push_back(a % 13 + '0');
            else 
                tmp.push_back(a % 13 + 'A' - 10);
            a = a / 13;
        }
        if (tmp.size() == 1)
            out += '0';
        if (tmp.size() == 0)
            out += "00";
        out.append(tmp.rbegin(), tmp.rend());
        
        tmp.clear();
    }

    cout << out << endl;
    
    return 0;
}