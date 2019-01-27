// #include <iostream>
// #include <vector>

// using namespace std;
// int main(int argc, char const *argv[])
// {
//     int L, M;
//     cin >> L >> M;
//     // int start = 0, end = 0;
//     vector<int> start, end;
//     int temp_s, temp_e;
//     int sum = 0;
//     // int area_id = 0;
//     for (int i = 0; i < M; i++) {
//         cin >> temp_s >> temp_e;
//         if (start.size() == 0) {
//             start.push_back(temp_s);
//             end.push_back(temp_e);
//             sum += (temp_e - temp_s + 1);
//             //cout << sum << endl;
//         }
//         else if (start.size() > 2) {
//             for ()
//         }
//         for (int j = 0; j < start.size(); j++) {
//             // cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             // cout << "=====" << start[j] << " " << end[j] << endl;
//             // cout << "=====" << temp_s << " " << temp_e << endl;
//             if (temp_s > start[j] && (temp_e < end[j]))
//                 continue;
//             else if (temp_s == start[j] && (temp_e == end[j]))
//                 continue;
//             else if (temp_s > start[j] && (temp_s < end[j]) && (temp_e > end[j])) {
//                 sum += (temp_e - end[j]);
//                 end[j] = temp_e;
//                 //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             }
//             else if (temp_s < start[j] && (temp_e > start[j]) &&(temp_e < end[j])) {
//                 sum += (start[j] - temp_s);
//                 start[j] = temp_s;
//                 //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             }
//             else if (temp_e == start[j]) {
//                 sum += (temp_e - temp_s);
//                 start[j] = temp_s;
//                 //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             }
//             else if (temp_s == end[j]) {
//                 sum += (temp_e - temp_s);
//                 end[j] = temp_e;
//                 //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             }
//             else if (temp_e < start[j]) {
//                 sum += (temp_e - temp_s + 1);
//                 start.push_back(temp_s);
//                 end.push_back(temp_e);
//                 //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             }
//             else if (temp_s > end[j]) {
//                 sum += (temp_e - temp_s + 1);
//                 start.push_back(temp_s);
//                 end.push_back(temp_e);
//                 //cout << __FUNCTION__ << ":" << __LINE__ << endl;
//             }
//             //cout << "sum: " << sum << endl;
//         }
//     }
//     cout << (L + 1 - sum) << endl;
//     return 0;
// }

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