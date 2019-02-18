#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (str[i] == 'z')
                str[i] = 'a';
            else if (str[i] == 'Z')
                str[i] = 'A';
            else {
                str[i] += 1;
            }
        }
    }
    cout << str << endl;
    return 0;
}