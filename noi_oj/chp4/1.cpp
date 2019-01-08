#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    long n;
    cin >> n;
    // if (n == 0)
    //     cout << "zero" << endl;
    // else if (n == abs(n))
    //     cout << "positive" << endl;
    // else 
    //     cout << "negative" << endl;
    if (n == 0)
        cout << "zero" << endl;
    else if (n > 0)
        cout << "positive" << endl;
    else 
        cout << "negative" << endl;
    return 0;
}