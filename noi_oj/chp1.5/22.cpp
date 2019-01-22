#include <iostream>

using namespace std;

#define MOM_OFFER 300
int main(int argc, char const *argv[])
{
    int temp_budget = 0;
    int remain = 0;
    int keep = 0;
    int first_budget = 0;
    cin >> first_budget; // 读入第一个月的预算
    remain = MOM_OFFER - first_budget;
    int i;
    if (remain >= 0) {
        for (i = 0; i < 11; i++) {
            cin >> temp_budget;
            remain = remain + MOM_OFFER - temp_budget; // 
            if (remain >= 100) {
                keep += ((int)(remain/100))*100;
                remain = remain - ((int)(remain/100))*100;
            }
            else if (remain < 0)
                break;
        }
        if (i == 11)
            cout << keep*1.2 + remain << endl;
        else 
            cout << "-" << i+2 << endl; 
    }
    else {
        cout << "1" <<endl;
    }
    return 0;
}