#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Record>
inline void swap(Record A[], int i, int j) {
    Record temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <class Record>
void SelectSort(Record Array[], int n) {
    for (int i = 0; i < (n-1); ++i) {
        int smallest = i;
        for (int j = i + 1; j < n; ++j) {
            if (Array[smallest] > Array[j])
                smallest = j;
        }
        swap(Array, i, smallest);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    // 排序
    SelectSort(arr, n);

    int j = 0;
    while(1) {
        if (arr[j] % 2 != 0)
            break;
        j++;
    }

    cout << arr[j];
    for (int i = j + 1; i < n; ++i) {
        if (arr[i] % 2 != 0)
            cout << "," << arr[i];
    }
    cout << endl;

    return 0;
}