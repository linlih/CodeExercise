#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    char trans[26] = {'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' };
    string plain;
    while(1) {
        //getline(cin, plain);
        cin >> plain;
        cin.clear();
        cin.sync();
        if (plain == "START") {
            getline(cin, plain);
            for (int i = 0; i < plain.length(); ++i) {
                if (plain[i] >= 'A' && plain[i] <= 'Z') 
                    cout << trans[plain[i] - 'A'];
                else 
                    cout << plain[i];
            }
            cout << endl;
        }
        else if (plain == "ENDOFINPUT"){
            break;
        }
        getline(cin, plain);
    }
    return 0;
}