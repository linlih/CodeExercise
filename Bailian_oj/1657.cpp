#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string a, b;
    int x1, y1, x2, y2;
    cin >> n;
    while (n > 0) {
        cin >> a >> b;
        x1 = a.at(0) - 'a' + 1;
        y1 = a.at(1) - '1' + 1;
        x2 = b.at(0) - 'a' + 1;
        y2 = b.at(1) - '1' + 1;
        cout << x1 << y1 << " " << x2 << y2 << endl;
        n--;
    }
    // string str("a1");
    // cout << str.at(0) << " " << str.at(1) <<endl;
    // int t = str.at(0) - 'a';
    // cout << t << endl;
    return 0;
}