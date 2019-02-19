#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int **arr;
    arr = new int*[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new int[n];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) 
            cin >> arr[i][j];
    }

    int sum = 0;
    // 计算第一行和最后一行的和
    for (int i = 0; i < n; ++i) {
        if (m > 1) {
            sum+=arr[0][i];
            sum+=arr[m-1][i];
        }
        else 
            sum+=arr[0][i];
    }
    // 计算两侧的和
    for (int i = 1; i < (m-1); ++i) {
        if (n > 1) {
            sum+=arr[i][0];
            sum+=arr[i][n-1];
        }
        else 
            sum+=arr[i][0];
    }

    cout << sum << endl;

    return 0;
}