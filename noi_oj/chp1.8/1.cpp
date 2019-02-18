#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int arr[5][5];
    for (int i = 0; i < 5; ++i)  {
        for (int j = 0; j < 5; ++j) 
            cin >> arr[i][j];
        cin >> skipws;
    }

    int m, n;
    cin >> m >> n;
    m -= 1;
    n -= 1;
    int tmp = 0;

    for (int i = 0; i < 5; ++i)  {
        tmp = arr[m][i];
        arr[m][i] = arr[n][i];
        arr[n][i] = tmp;
    }

    for (int i = 0; i < 5; ++i)  {
        for (int j = 0; j < 5; ++j) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}