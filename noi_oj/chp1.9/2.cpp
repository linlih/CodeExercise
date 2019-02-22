#include <iostream>
#include <memory.h>
using namespace std;

typedef struct stu {
    int s;
    char n[21];
}stu;

int main(int argc, char const *argv[])
{
    stu s;
    int n;
    cin >> n;
    cin >> s.s >> s.n;
    stu tmp;
    for (int i = 1; i < n; ++i) {
        cin >> tmp.s >> tmp.n;
        if (tmp.s > s.s) {
            s.s = tmp.s;
            memset(&s.n, 0, 21);
            memcpy(&s.n, &tmp.n, 21);
        }
        memset(&tmp, 0, sizeof(stu));
    }
    cout << s.n << endl;
    return 0;
}