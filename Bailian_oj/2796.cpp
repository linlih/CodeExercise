#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin >> skipws;
    int sum = 0;
    int temp;
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        if (temp < n)
            sum += temp;
    }
    cout << sum << endl;
    return 0;
}