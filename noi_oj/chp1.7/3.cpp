#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, length, s = 0;
    double f;
    cin >> f;
    char a[501], b[501];

    scanf("%s", a);
    scanf("%s", b);

    length = strlen(a);
    f *= length;

    for (i = 0; i < length; i++){
        if (a[i] == b[i])
            s++;
    }

    if (s >= f)
        cout << "yes";
    else
        cout << "no";

    return 0;
}