#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int m, n;
    int a[100][100];
    int r, s;
    int b[100][100];

    int start_point = 0;
    
    cin >> m >> n;
    for (int i = 0; i < m; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    cin >> r >> s;
    for (int i = 0; i < r; ++i) 
        for (int j = 0; j < s; ++j)
            cin >> b[i][j];

    int abs_value = 10000000;
    int tmp = 0;
    int start_x = 0;
    int start_y = 0;
    int s_x;
    int s_y;
    for (start_x = 0; start_x + r <= m; ++start_x) 
        for (start_y = 0; start_y + s <= n; ++start_y) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < s; ++j) {
                    tmp += abs(a[start_x + i][start_y + j] - b[i][j]);
                }
            }
            if (tmp < abs_value) {
                abs_value = tmp;
                s_x = start_x;
                s_y = start_y;
            }
            tmp = 0; 
        }   

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << a[s_x + i][s_y + j] << " ";
        }
        cout << endl;
    }
    return 0;
}