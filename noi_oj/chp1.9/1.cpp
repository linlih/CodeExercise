#include <iostream>

using namespace std;

void display_matirx(int **arr, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int **arr = NULL;
    arr = new int*[n]; // 如果是C语言，换成：arr = (int *)malloc(sizeof(int)*m)
    for (int i = 0; i < n; ++i)
        arr[i] = new int[n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    
    cout << arr[1][1] << endl;

    while (n > 1) {
        // 行处理
        for (int i = 0; i < n; ++i) {
            // 找到行最小
            int row_min = arr[i][0];
            for (int j = 1; j < n; ++j) {
                if (row_min > arr[i][j])
                    row_min = arr[i][j];
            }

            for (int j = 0; j < n; ++j)
                arr[i][j] -= row_min;
        }
        //display_matirx(arr, n, n);
        // 列处理
        for (int j = 0; j < n; ++j) {
            // 找到列最小
            int col_min = arr[0][j];
            for (int i = 1; i < n; ++i) {
                if (col_min > arr[i][j])
                    col_min = arr[i][j];
            }

            for (int i = 0; i < n; ++i)
                arr[i][j] -= col_min;
        }

        cout << arr[1][1] << endl;

        //display_matirx(arr, n, n);

        // 消减后、
        //cout << "reduce:" << endl;

        // 消减第二列
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < (n-1); ++j)
                arr[i][j] = arr[i][j+1];
            //arr[i][j] = 0;
        }
        //display_matirx(arr, n, n);

        
        // 消减第二行
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < (n-1); ++i)
                arr[i][j] = arr[i+1][j];
            //arr[i][j] = 0;
        }
        //display_matirx(arr, n, n);
        n--;
    }
    return 0;
}