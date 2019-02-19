#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int **arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    
    // 判断行
    int row_sum = 0;  // 行和
    int row_flag = 0; // 记录行标志，是否超过两行为奇数
    int row_num = 0;  // 记录行为奇数的行号
    int i,j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            row_sum += arr[i][j];
        }
        if (row_sum%2 != 0) {
            row_flag ++;
            row_num = i;
        }
        row_sum = 0;
    }

    // 判断列
    int col_sum = 0;
    int col_flag = 0;
    int col_num = 0;
    for (j = 0; j < n; ++j) {
        for (i = 0; i < n; ++i) {
            col_sum += arr[i][j];
        }
        if (col_sum%2 != 0) {
            col_flag ++;
            col_num = j;
        }
        col_sum = 0;
    }

    if (col_flag == 0 && row_flag == 0)
        cout << "OK" << endl;
    else if (col_flag >= 2 || row_flag >= 2)
        cout << "Corrupt" << endl;
    else if (col_flag == 1 && row_flag == 1)
        cout << row_num + 1 << " " << col_num + 1 << endl;
    return 0;
}