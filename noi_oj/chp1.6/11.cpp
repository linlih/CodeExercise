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
    int neg_flag = 0;

    if (y.length() > x.length()) {
        str2arr(x, b);
        str2arr(y, a);
        neg_flag = 1;    
    }
    else if (x.length() > y.length()) {
        str2arr(x, a);
        str2arr(y, b);
    }
    else {
        int n = 0;
        while(x[n] == y[n]) {
            n++;
            if (n == x.length()) {
                cout << "0" << endl;
                return 0;
            }
        }
        if (x[n] > y[n]) {
            str2arr(x, a);
            str2arr(y, b);
        }
        else {
            neg_flag = 1;
            str2arr(x, b);
            str2arr(y, a);
        }
    }

    int res[220] = {0};
    int tmp;
    for (int i = 0; i < 210; ++i) {
        if ((res[i] + a[i]) < b[i]) { // 接上res[i]是为了解决这种情况：987-87 结果为：9-19
            res[i] = res[i] + a[i] + 10 - b[i];
            res[i+1] = res[i+1] - 1;
        }
        else {
            res[i] = res[i] + a[i] - b[i];
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
        if (neg_flag == 1)
            cout << "-";
        for (int i = j; i >= 0; --i) {
            cout << res[i];
        }
        cout << endl;
    }

    return 0;
}