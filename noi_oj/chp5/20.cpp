#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    double h;
    cin >> h;
    double dis;
    dis = h;
    double temp; 
    temp = h / 2;
    for (int i = 0; i < 9; i ++) {
        dis = dis + temp * 2; 
        temp = temp / 2;
    }
    cout << dis << endl; 
    cout << temp << endl;

    return 0;
}

// #include<iostream>
// using namespace std;
// int main()
// {
//     double s, h;
//     int i = 9;
//     cin >> h;
//     s = h;
//     h = h / 2;
//     while (i != 0)
//     {
//         i--;
//         s = s + 2 * h;
//         h = h / 2;
//     }
//     cout << s << endl;
//     cout << h << endl;
//     return 0;
// }