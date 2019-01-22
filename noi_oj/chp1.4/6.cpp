#include <iostream>

using namespace std;

#define TWO_NUM 10

int main(int argc, char const *argv[])
{
    int a;
    cin >> a;
    if (a/TWO_NUM > 0 && (a/TWO_NUM < 10))
        cout << "1";
    else 
        cout << "0";
    return 0;
}