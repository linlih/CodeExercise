#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    long x, y;
    char op;
    cin >> x >> y >> op;
    
    switch (op)
    {
        case '+':
            cout << x + y << endl;
            break;

        case '-':
            cout << x - y << endl;
            break;

        case '/':
            if (y == 0)
                cout << "Divided by zero!" << endl;
            else
                cout << x / y << endl;
            break;
        
        case '*':
            cout << x * y << endl;
            break;
    
        default:
            cout << "Invalid operator!" << endl;
            break;
    }
    return 0;
}