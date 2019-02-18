#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string p1, p2;
    for (int i = 0; i < n; ++i) {
        cin >> p1 >> p2;
        if (p1 == p2) {
            cout << "Tie" << endl;
        }
        else if (p1 == "Rock" ) {
            if (p2 == "Scissors")
                cout << "Player1" << endl;
            else 
                cout << "Player2" << endl;
        }
        else if (p1 == "Scissors") {
            if (p2 == "Paper")
                cout << "Player1" << endl;
            else 
                cout << "Player2" << endl;
        }
        else if (p1 == "Paper") {
            if (p2 == "Rock")
                cout << "Player1" << endl;
            else 
                cout << "Player2" << endl;
        }
        p1.clear();
        p2.clear();
    }

    
    return 0;
}