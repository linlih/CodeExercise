#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    if (str[0] >= '0' && str[0] <= '9')
        cout << "no" << endl;
    else {
        int i = 0;
        for (i = 0; i < str.length(); ++i) {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] == '_'))
                continue;
            else 
                break;
        }
        if (i == str.length())
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
    }
    return 0;
}