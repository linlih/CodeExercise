#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int a, b;
    cin >> n;
    int cnt = 0;
    int max = 0;
    int i;
    for (i = 0; i < n; i++){
        cin >> a >> b;
        if (a >= 90 && (a <= 140) && (b >= 60) && (b <= 90)) {
            cnt++;
            if (max <= cnt)
                max = cnt;
        }
        else {
            cnt = 0;
        }
    }
    
    cout << max << endl;
    return 0;
}