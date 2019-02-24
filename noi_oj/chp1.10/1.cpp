#include <iostream>
#include <memory.h>

using namespace std;

class stu {
public:
    char n[16];
    float s;
public:
    bool operator <(const stu& s) {
        if (this->s < s.s)
            return true;
        else
            return false;
    }
};

void SWAP(stu* s,int i,int j) {
    float tmp = s[i].s;
    s[i].s = s[j].s;
    s[j].s = tmp;
    char tmp_n[16] = {0};
    memcpy(tmp_n, s[i].n, 16);
    memcpy(s[i].n, s[j].n, 16);
    memcpy(s[j].n, tmp_n, 16);
}

template <class Record>
void SelectSort(Record Array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i+1; j < n; j++) {
            if (Array[j] < Array[smallest])
                smallest = j;
        }
        SWAP(Array, i, smallest);
    }
}

template <class Record>
void sort(Record* Array, int n) {
    SelectSort(Array, n);
}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    stu *arr = new stu[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].n >> arr[i].s;    
    }

    // 排序，从小到大
    sort(arr, n);

    // cout << "================" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << arr[i].n << " " << arr[i].s << endl;    
    // }
    // cout << "================" << endl;

    // 因为是从小到大排序，所有要注意下标的转换
    cout << arr[n-k].n << " " << arr[n-k].s << endl;

    return 0;   
}