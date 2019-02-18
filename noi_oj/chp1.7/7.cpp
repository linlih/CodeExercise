#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    string out;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'A')
            out += 'T';
        else if (str[i] == 'T')
            out += 'A';
        else if (str[i] == 'C')
            out += 'G';
        else if (str[i] == 'G')
            out += 'C';
    }
    cout << out << endl;
    return 0;
}