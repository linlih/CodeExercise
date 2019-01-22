#include <iostream>

using namespace std;

#define PREP_BIKE 27
#define LOCK_BIKE 23
#define SPEED_BIKE 3.0
#define SPEED_WALK 1.2

int main(int argc, char const *argv[])
{
    int s;
    cin >> s;
    float bike_t;
    float walk_t;
    bike_t = s/SPEED_BIKE + PREP_BIKE + LOCK_BIKE;
    walk_t = s/SPEED_WALK;
    if (bike_t > walk_t)
        cout << "Walk" << endl;
    else if (bike_t < walk_t)
        cout << "Bike" << endl;
    else
        cout << "All" << endl;
    return 0;
}