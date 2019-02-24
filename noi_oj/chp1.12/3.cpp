#include <iostream>
#include <memory.h>
using namespace std;
int main(int argc, char const *argv[])
{
    char name[10] = {0};
    float tmp;
    int cough;
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> name >> tmp >> cough;
        if (tmp >= 37.5 && cough == 1) {
            cout << name << endl;
            total += 1;
        }
        memset(name, 0, 10);
    }
    cout << total << endl;
    return 0;
}