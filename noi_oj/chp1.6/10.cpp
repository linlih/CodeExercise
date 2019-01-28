#include <iostream>

using namespace std;

void str2arr(string &str, int *arr) {
    for (int i = 0; i < str.length(); ++i) {
        arr[str.length() - i - 1] = (str[i] - '0');
    }
}

int main(int argc, char const *argv[])
{
    string x;
    string y;
    cin >> x;
    cin >> y;
    int a[210] = {0};
    int b[210] = {0};
    str2arr(x, a);
    str2arr(y, b);

    int res[220] = {0};
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