#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int arr[5][5];
    for (int i = 0; i < 5; ++i) 
        for (int j = 0; j < 5; ++j)
            cin >> arr[i][j];
    
    int col_i = 0;
    int row_i = 0;
    int flag = 0;
    for (int i = 0; i < 5; ++i) {
        row_i = i;
        // 找行的最大值，记录列下标
        int row_max = arr[i][0];
        for (int j = 1; j < 5; ++j) {
            if (row_max < arr[i][j]) {
                col_i = j;
                row_max = arr[i][j];
            }
        }
        // 判断是否为列的最小值
        int k;
        for (k = 0; k < 5; ++k) {
            if (arr[row_i][col_i] > arr[k][col_i])
                break;
        }
        if (k == 5) {
            cout << row_i + 1 << " " << col_i + 1 << " " << arr[row_i][col_i] << endl;
            flag = 1;
        }
        col_i = 0;
    }
    if (flag == 0)
        cout << "not found" << endl;
    return 0;
}