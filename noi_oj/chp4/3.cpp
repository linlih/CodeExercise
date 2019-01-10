#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    unsigned int n;
    cin >> n;
    if (n%2==0)
        cout << "even" << endl;
    else 
        cout << "odd" << endl;
    return 0;
}