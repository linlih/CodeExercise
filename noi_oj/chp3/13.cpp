#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        cout << a[a.length() - i - 1];
    }
    cout << endl;
    return 0;
}