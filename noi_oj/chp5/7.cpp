#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int g = 0, s = 0, b = 0;
    int temp1, temp2, temp3;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2 >> temp3;
        g += temp1;
        s += temp2;
        b += temp3;
    }
    cout << g << " " << s << " " << b << " " << (g+s+b) << endl;
    return 0;
}