#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    char encrypt[26] = {'V', 'W', 'X', 'Y','Z', 'A', 'B', 'C', 'D', 'E', 'F','G' ,'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};

    string str;
    getline(cin, str);
    
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            cout << encrypt[str[i] - 'A'];
        else 
            cout << str[i];
    } 
    cout << endl;
    return 0;
}