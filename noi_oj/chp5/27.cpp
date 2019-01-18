#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    double sum = 1;
    cin >> k;
    int i = 1;
    while (sum <= k) {
        i++;
        sum += ((1.0)/i);
    } 
    cout << i << endl;
    return 0;
}