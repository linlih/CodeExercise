#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int s;
    float bike_time = 0;
    float walk_time = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        bike_time = (s*1.0)/3.0 + 50; 
        walk_time = (s*1.0)/1.2;

        if (bike_time > walk_time)
            cout << "Walk" << endl;
        else if (walk_time > bike_time)
            cout << "Bike" << endl;
        else
            cout << "All" << endl;
    }
    return 0;
}