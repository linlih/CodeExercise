#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int **pic1;
    pic1 = new int*[m];
    int **pic2;
    pic2 = new int*[m];
    for (int i = 0; i < m; ++i) {
        pic1[i] = new int[n];
        pic2[i] = new int[n];
    }

    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> pic1[i][j];
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> pic2[i][j];

    int cnt = 0;
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j)
            if (pic1[i][j] == pic2[i][j])
                cnt ++;
    
    cout << setprecision(2) << fixed << (cnt*100.0)/(m*n) << endl;
    return 0;
}