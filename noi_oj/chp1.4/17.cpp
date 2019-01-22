#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int y;
    cin >> y;
    if (y%4 == 0) {
        if (y%100 == 0 && (y%400 != 0))
            cout << "N" << endl;            
        else if (y%3200 == 0)
            cout << "N" << endl;            
        else 
            cout << "Y" << endl;
    }
    else
        cout << "N" << endl;
    return 0;
}


