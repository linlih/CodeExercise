#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    long long temp = n;
    while (temp != 1) {
        if (temp%2==0) {
            cout << temp << "/2=" << temp/2 << endl;
            temp = temp/2;
        }
        else {
            cout << temp << "*3+1=" << temp*3+1 << endl;
            temp = temp*3 + 1;
        }
    }
    cout << "End" << endl;

    return 0;
}