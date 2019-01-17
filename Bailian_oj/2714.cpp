#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    int sum = 0;
    int n;
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        sum += temp; 
    }
    cout << setprecision(2) << fixed <<  sum/(n*1.0) << endl;
    return 0;
}