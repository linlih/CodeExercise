#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int h[10];
    for (int i = 0; i < 10; ++i) {
        cin >> h[i];
        cin >> skipws;
    }
    int reach;
    cin >> reach;
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        //cout << h[i] << " ";
        if (h[i] <= (reach + 30))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}