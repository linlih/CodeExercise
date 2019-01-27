#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin >> skipws;
    int tmp = 0, tmp1 = 0;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 0;
    }
    cin >> tmp;
    cin >> skipws;
    int flag = 0;
    for (int i = 0; i < (n - 1); ++i) {
        cin >> tmp1;
        cin >> skipws;
        arr[abs(tmp1 - tmp)] += 1;
        tmp = tmp1;
    }
    for (int j = 1; j < n; ++j) {
        if (arr[j] != 1){
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Not jolly" << endl;
    else 
        cout << "Jolly" << endl;
    return 0;
}