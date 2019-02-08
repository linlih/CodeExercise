#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    int cnt = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (((int)str[i] >= '0') && ((int)str[i] <= '9'))
            cnt ++;
    }
    cout << cnt << endl;
    return 0;
}