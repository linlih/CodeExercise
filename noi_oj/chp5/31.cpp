#include <iostream>
#include <memory.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int N;
    int M;
    cin >> N;
    cin >> skipws;
    cin >> M;
    bool *light = new bool[N+1];
    memset(light, false, sizeof(bool)*N);
    int first = 1;
    if (M == 1) {
        for (int i = 1; i <= N; ++i)
            cout << i << endl;
    }
    else if (M == 2) {
        for (int i = 1; i <= N; ++i) {
            if (i%2!=0)
                cout << i << endl;
        }
    }
    else {
        for (int i = 1; i <= N; ++i) {
            if (i%2==0)
                light[i] = true;
        }
        for (int i = 3;i <= M; ++i) {
            for (int j = 1; j <= N; j++) {
                if (j%i==0)
                    light[j] = !light[j];
                //cout << light[j] << " ";
            }
        }
        for (int j = 1; j <= N; j++) {
            if (light[j] == false) {
                if (first == 1) {
                    cout << j;
                    first = 0;
                }
                else 
                    cout << ',' << j;
            }
        }
        cout << endl;
    }
    return 0;
}