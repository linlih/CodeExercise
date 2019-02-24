#include <iostream>
#include <memory.h>
#include <string.h>

using namespace std;

class stu {
public:
    int index;
    int chinese;
    int math;
    int english;
public:
    stu(){}

    bool operator <(const stu& s) {
        int total = chinese + math + english;
        int total_s = s.chinese + s.math + s.english;

        if (total == total_s) {
            if (chinese == s.chinese) {
                if (index > s.index)
                    return true;
                else 
                    return false;
            }
            else {
                if (chinese < s.chinese)
                    return true;
                else 
                    return false;
            }
        }
        else {
            if (total < total_s)
                return true;
            else 
                return false;
        }
    }
};

void SWAP(stu* s, int i, int j) {
    int tmp;
    tmp = s[i].chinese;
    s[i].chinese = s[j].chinese;
    s[j].chinese = tmp;

    tmp = s[i].math;
    s[i].math = s[j].math;
    s[j].math = tmp;

    tmp = s[i].english;
    s[i].english = s[j].english;
    s[j].english = tmp;

    tmp = s[i].index;
    s[i].index = s[j].index;
    s[j].index = tmp;
}

template <class Record>
void BubbleSort(Record Array[], int n) {
    bool NoSwap;
    for (int i = 0; i < n - 1; ++i) {
        NoSwap = true;
        for (int j = n - 1; j > i; --j)
            if (Array[j] < Array[j - 1]) {
                SWAP(Array, j, j - 1);
                NoSwap = false;
            }
        if (NoSwap)
            return;
    }
}

template <class Record>
void sort(Record* Array, int n) {
    BubbleSort(Array, n);
}

/* 验证：
总分相同, 语文成绩从高到低
7
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
80 87 98

总分相同，语文成绩相同
7
90 67 80
87 66 91
78 89 91
88 99 77
67 89 64
78 89 98
78 89 98
*/
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    stu *arr = new stu[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].chinese >> arr[i].math >> arr[i].english;  
        arr[i].index = i+1;  
    }

    // 排序
    sort(arr, n);

    for (int i = n-1; i >= n - 5; --i) {
        //cout << arr[i].index << " " << arr[i].chinese + arr[i].math + arr[i].english << " " << arr[i].chinese << " " <<  arr[i].math << " " << arr[i].english << endl;    
        cout << arr[i].index << " " << arr[i].chinese + arr[i].math + arr[i].english << endl;   
    }

    return 0;   
}