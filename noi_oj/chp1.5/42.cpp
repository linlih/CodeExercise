#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int h, w;
    char cartoon;
    int flag;
    cin >> h >> w >> cartoon >> flag;
    for (int i = 0; i < w; ++i) 
        cout << cartoon;
    cout << endl;
    for (int i = 1; i < (h - 1); ++i) {
        cout << cartoon;
        for (int j = 1; j < (w-1); ++j) {
            if (flag == 0)
                cout << " ";
            else if (flag == 1)
                cout << cartoon;
        }
        cout << cartoon;
        cout << endl;
    }
    for (int i = 0; i < w; ++i) 
        cout << cartoon;
    cout << endl;
    return 0;
}