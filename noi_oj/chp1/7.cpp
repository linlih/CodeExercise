#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[])
{
    double a;
    cin >> a;
    //cout << setprecision(6) << fixed << a << endl;   
    printf("%f\n", a);
    cout << setprecision(5) << fixed << a << endl;   
    cout << scientific << setprecision(6) <<  a << endl;
    printf("%g\n", a);

    //cout << a << endl;
    return 0; 
}