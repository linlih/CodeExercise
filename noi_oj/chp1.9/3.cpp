#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    int max = 0;
    int max_t = 0;
    for (int i = 1; i <= 7; ++i) {
        cin >> a >> b;
        if (a+b > 8 && a+b >max_t) {
            max = i;
            max_t = a + b;
        }
    }
    cout << max << endl;
    return 0;
}