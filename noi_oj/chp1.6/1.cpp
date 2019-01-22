#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int *arr = NULL;
    int n;
    int k;
    cin >> n;
    arr = new int[n];
    int tmp;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        arr[i] = tmp;
    }
    cin >> k;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == k)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}