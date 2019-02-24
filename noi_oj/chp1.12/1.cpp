#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    char action;
    cin >> a >> action >> b;
    int res;
    switch (action)
    {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        case '%':
            res = a % b;
            break;

        default:
            break;
    }
    cout << res << endl;
    return 0;
}