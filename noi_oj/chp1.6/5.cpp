#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[4] = {0};
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        cin >> skipws;
        if (tmp >=0 && tmp <=18)
            a[0]++;
        else if (tmp >=19 && tmp <=35)
            a[1]++;
        else if (tmp >=36 && tmp <=60)
            a[2]++;
        else if (tmp >=61)
            a[3]++;        
    }

    cout << setprecision(2) << fixed << (a[0]*100.0)/n << "%"<< endl;
    cout << setprecision(2) << fixed << (a[1]*100.0)/n << "%"<< endl;
    cout << setprecision(2) << fixed << (a[2]*100.0)/n << "%"<< endl;
    cout << setprecision(2) << fixed << (a[3]*100.0)/n << "%"<< endl;
    return 0;
}