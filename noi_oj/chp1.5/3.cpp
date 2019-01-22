#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    float sum = 0;
    float temp;
    cin >> n;
    do {
        cin >> temp;
        cin >> skipws;
        sum += temp;
    }while(cin.get() != '\n');

    cout<< setprecision(4) << fixed << sum/(float)n << endl;
    return 0;
}