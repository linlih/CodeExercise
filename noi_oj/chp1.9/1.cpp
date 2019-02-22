#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int tmp;
    cin >> tmp;
    for (int j = 0; j < n; ++j) {
        if (arr[j] == tmp) {
            cout << j + 1 << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}