#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a;
    cin >> a;
    char res[20] = {0};
    int i = 0;
    while (a != 0) {
        res[i] = (char)(a%8 + '0');
        a = a / 8;
        i++;
    }
    i = 19;
    while(res[i] == 0)
        --i;
    for (int j = i; j >= 0; --j)
        cout << res[j];
    cout << endl;
    return 0;
}