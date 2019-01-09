#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string a, b;
    int x1, y1, x2, y2;
    int king = 0, queen = 0, car = 0, elep = 0; // 定义最短距离

    cin >> n;
    while (n > 0) {
        cin >> a >> b;
        if  (a == b)
            cout << "0 0 0 0" << endl;
        else {
            x1 = a.at(0) - 'a' + 1;
            y1 = a.at(1) - '1' + 1;
            x2 = b.at(0) - 'a' + 1;
            y2 = b.at(1) - '1' + 1;
            //cout << x1 << y1 << " " << x2 << y2 << endl;
            if (abs(x2-x1) > abs(y2-y1))
                king = abs(x2-x1);
            else 
                king = abs(y2-y1);
            if ((abs(x2-x1) == abs(y2-y1)) || ((x1 == x2) || (y1 == y2)))        
                queen = 1;
            else 
                queen = 2;
            if ((x1 == x2) || (y1 == y2))
                car = 1;
            else
                car = 2;
            cout << king << " " << queen << " " << car << " " ;// << (abs(x1-x2) == abs(y1-y2))?"1":"Inf" << endl; 
            if (abs(x1-x2) == abs(y1-y2))
                cout << "1" << endl;
            else if ((abs(x1-x2)+abs(y1-y2))%2 == 0)
                cout << "2" << endl;
            else
                cout << "Inf" << endl;
        }
        n--;
    }
    

    return 0;
}