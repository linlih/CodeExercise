#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    char a, b;
    cin >> str >> a >> b;
    string out;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == a)
            out += b;
        else
            out += str[i];
    }
    cout << out << endl;
    return 0;
}