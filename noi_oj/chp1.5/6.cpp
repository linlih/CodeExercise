#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int temp;
    int big = 0;
    int small = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> skipws;
        if (i == 0){
            big = temp;
            small = temp;
        }
        else {
            if (temp > big)
                big = temp;
            if (temp < small)
                small = temp;              
        }
        
    }

    cout << (big - small) << endl;
    return 0;
}