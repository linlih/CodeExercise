#include <iostream>
#include <stack>

using namespace std;
int main(int argc, char const *argv[])
{
    long a;
    cin >> a;
    while (a!=0) {
        cout << a%10 <<  ' ';
        a = a / 10;
    }
    cout << endl;
    return 0;
}