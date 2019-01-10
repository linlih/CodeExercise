#include <iostream>

using namespace std;

#define SCORE 60

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    if (((a/SCORE > 0) && (b/SCORE == 0)) || ((b/SCORE > 0) && (a/SCORE == 0)))
        cout << "1" << endl;
    else
        cout << "0" << endl;
    return 0;
}