#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

#define THRESHOLD 28

template <class Record>
void InsertSort(Record Array[], int n) {
    Record TempRecord;
    for (int i = 1; i < n; i++) {
        TempRecord = Array[i];
        int j = i - 1;
        while (j >= 0 && TempRecord < Array[j]) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = TempRecord;
    }
}

int SelectPivot(int left, int right) {
    return (left + right)/2;
}

template <class Record>
int Partition(Record Array[], int left, int right) {
    int l = left;
    int r = right;
    Record TempRecord = Array[r];
    while (l != r) {
        while (Array[l] <= TempRecord && r > l)
            l++;
        if (l < r) {
            Array[r] = Array[l];
            r--;
        }
        while (Array[r] > TempRecord && r > l)
            r--;
        if (l < r) {
            Array[l] = Array[r];
            l++;
        }
    }
    Array[l] = TempRecord;
    return l;
}

template <class Record>
void ModQuickSort(Record Array[], int left, int right) {
    if (right <= left) return ;
    if (right - left + 1 > THRESHOLD) {
        int pivot = SelectPivot(left, right);
        swap(Array, pivot, right);
        pivot = Partition(Array, left, right);
        ModQuickSort(Array, left, pivot - 1);
        ModQuickSort(Array, pivot + 1, right);
    }
}


template <class Record>
void sort(Record* Array, int n) {
    ModQuickSort(Array, 0, n-1);
    InsertSort(Array, n);
}

#include "../SortMain.h"