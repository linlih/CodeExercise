#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long a, b, c;
    cin >> n;
    for (int i = 1; i < n+1; ++i) {
        cin >> a >> b >> c;
        if ((a+b) > c)
           cout << "Case #" << i << ": true" << endl;
        else
           cout << "Case #" << i << ": false" << endl;
    }
    return 0;
}