#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    int L, M;
    cin >> L >> M;
    vector<int> *area;
    area = new vector<int>(L+1);
    int temp_s, temp_d;
    int left = 0;

    for (int i = 0; i < M; i++) {
        cin >> temp_s >> temp_d;
        for (int j = temp_s; j <= temp_d; j++) {
            if (area->at(j) != 1) {
                area->at(j) = 1;
            }
        }   
    }

    for (int k = 0; k < area->size(); k++) {
        if (area->at(k) == 1)
            left++;
    }

    cout << (L + 1 - left) << endl;
    return 0;
}