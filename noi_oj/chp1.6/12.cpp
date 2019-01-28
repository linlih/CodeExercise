#include <iostream>

using namespace std;

void str2arr(string &str, int *arr) {
    for (int i = 0; i < str.length(); ++i) {
        arr[str.length() - i - 1] = (str[i] - '0');
    }
}

int* big_add(int *a, int *b, int *res) {
    int tmp;

    for (int i = 0; i < 210; ++i) {
        tmp = res[i] + a[i] + b[i];
        if (tmp >= 10) {
            res[i] = tmp%10;
            res[i+1] = tmp/10;
        }
        else {
            res[i] = tmp;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[210] = {0};
    int res[220] = {0};
    a[0] = 1;
    int k = 1;

    for (int i = 0; i < n; ++i) {
        big_add(a, a, res);
        for (int j = 0; j < 200; j++) {
            a[j] = res[j];
            res[j] = 0;
        }
    }

    for (int j = 0; j < 200; j++) {
        res[j] = a[j];
    }

    int j = 219;
    while(res[j]==0) {
        j--;
        if (j < 0)
            break;
    }
    if (j == -1)
        cout << "0" << endl;
    else {
        for (int i = j; i >= 0; --i) {
            cout << res[i];
        }
        cout << endl;
    }

    return 0;
}