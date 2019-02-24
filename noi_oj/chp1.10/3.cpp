#include <iostream>
#include <memory.h>
#include <string.h>

using namespace std;

class stu {
public:
    char n[16];
    float s;
public:
    stu(){}
    stu(char n[], float s):s(s) {
        memset(this->n, 0, 16);
        memcpy(this->n, n, 16);
    }

    bool operator <(const stu& s) {
        if (this->s != s.s) {
            if (this->s < s.s)
                return true;
            else
                return false;
            }
        else {
            // 分数相同，则按照字符排序，为什么是大于0???
            if (strcmp(this->n, s.n) > 0)
                return true;
            else 
                return false;
        }
    }
    stu& operator =(const stu& s) {
        if (this != &s) {
            this->s = s.s;
            memset(this->n, 0, 16);
            memcpy(&this->n, &s.n, 16);
        }
        return *this;
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
void InsertSort(Record Array[], int n) {
    Record TempRecord;
    for (int i = 1; i < n; ++i) {
        TempRecord = Array[i];
        int j = i - 1;
        while(j >= 0 && TempRecord < Array[j]) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }

        Array[j + 1] = TempRecord;
    }
}

template <class Record>
void sort(Record* Array, int n) {
    InsertSort(Array, n);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    stu *arr = new stu[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].n >> arr[i].s;    
    }

    // 排序
    sort(arr, n);

    for (int i = n-1; i >=0; --i) {
        cout << arr[i].n << " " << arr[i].s << endl;    
    }

    return 0;   
}