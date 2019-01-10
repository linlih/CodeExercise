#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    long a;
    int mark = 0;
    cin >> a;
    if (a%3 == 0) {
        cout << "3 ";
        mark = 1;
    }
    if (a%5 == 0){
        cout << "5 ";
        mark = 1;
    }
    if (a%7 == 0){
        cout << "7";
        mark = 1;
    }
    if (mark == 0)
        cout << "n" << endl;
    else
        cout << endl;
    return 0;
}