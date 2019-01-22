#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int a;
    int b;
    cin >> a >> b;
    cout << setprecision(3) << fixed << ((float)b * 100/a) << "%" << endl;
    return 0;
}