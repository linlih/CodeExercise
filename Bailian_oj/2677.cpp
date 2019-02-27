#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int i, j;
    int length = 0;
    int area = 0;
    int **a; // 数组指针
    a = (int**)malloc(sizeof(int*)*n);  
    for(i = 0;i < n;i++)  
        a[i] = (int*)malloc(sizeof(int)*n);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] <= 50) {
                area++;
                a[i][j] = -1;
                if (i == 0 || j == 0 || i == n-1 || j == n-1)
                    length++;
            }
        }
    }

    for (i = 1; i < n - 1; ++i) {
        for (j = 1; j < n - 1; ++j) {
            if ((a[i][j] == -1) && (a[i+1][j] != -1 || a[i][j+1] != -1 || a[i-1][j] != -1 || a[i][j-1] != -1))
                length++;
        }
    }

    cout << area << " " <<  length << endl;
    return 0;
}

