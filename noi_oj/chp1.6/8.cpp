#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n, na, nb;
    cin >> n >> na >> nb;
    int *a = new int[na];
    int *b = new int[nb];
    for (int i = 0; i < na; ++i) {
        cin >> a[i];
        cin >> skipws;
    }
    for (int i = 0; i < nb; ++i) {
        cin >> b[i];
        cin >> skipws;
    }

    int *o_a = new int[n];
    int *o_b = new int[n];
    int tmp_i = 0;
    for (int i = 0; i < n; ++i) {
        o_a[i] = a[tmp_i];
        tmp_i++;
        if (tmp_i == na)
            tmp_i = 0;
    }
    tmp_i = 0;
    for (int i = 0; i < n; ++i) {
        o_b[i] = b[tmp_i];
        tmp_i++;
        if (tmp_i == nb)
            tmp_i = 0;
    }

    int cnt_a = 0;
    int cnt_b = 0;
    for (int i = 0; i < n; ++i) {
        if (o_a[i] == 0) {
            if (o_b[i] == 2)
                cnt_a++;
            else if (o_b[i] == 5)
                cnt_b++;
        }
        else if (o_a[i] == 2) {
            if (o_b[i] == 0)
                cnt_b++;
            else if (o_b[i] == 5)
                cnt_a++;
        }
        else if (o_a[i] == 5) {
            if (o_b[i] == 0)
                cnt_a++;
            else if (o_b[i] == 2)
                cnt_b++;
        }
    }

    if (cnt_a > cnt_b)
        cout << "A" << endl;
    else if (cnt_a < cnt_b)
        cout << "B" << endl;
    else
        cout << "draw" << endl;

    return 0;
}