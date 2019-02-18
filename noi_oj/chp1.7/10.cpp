#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    string   plain("VWXYZABCDEFGHIJKLMNOPQRSTU");
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = plain[str[i] - 'A'];
    }
    cout << str << endl;
    return 0;
}