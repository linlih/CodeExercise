#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    char gender[8] = {0};
    float wbc, rbc, hgb, hct, plt;

    bool normal = true;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        cin >> gender >> wbc >> rbc >> hgb >> hct >> plt;
        if (wbc < 4.0 || wbc > 10.0) {
            normal = false;
            index += 1;
        }
        if (rbc < 3.5 || rbc > 5.5) {
            normal = false;
            index += 1;
        }
        if (strcmp(gender, "male") == 0) {
            if (hgb < 120 || hgb > 160) {
                normal = false;
                index += 1;
            }
            if (hct < 42 || hct > 48) {
                normal = false;
                index += 1;
            }
        }
        else {
            if (hgb < 110 || hgb > 150) {
                normal = false;
                index += 1;
            }
            if (hct < 36 || hct > 40) {
                normal = false;
                index += 1;
            }
        }
        if (plt < 100 || plt > 300) {
            normal = false;
            index += 1;
        }

        if (normal) {
            cout << "normal" << endl;
        }
        else {
            cout << index << endl;
        }
        normal = true;
        index = 0;
    }   
    return 0;
}