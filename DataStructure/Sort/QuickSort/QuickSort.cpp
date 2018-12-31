#include <iostream>
#include <stdlib.h>

using namespace std;
#include "../sort.h"

int SelectPivot(int left, int right) {
    return (left + right)/2;
}

template <class Record>
int Partition(Record Array[], int left, int right) {
    int l = left;
    int r = right;
    Record TempRecord = Array[r];
    while (l != r) {
        while (Array[l] <= TempRecord &&  r > l) 
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
void QuickSort(Record Array[], int left, int right) {
    if (right <= left) return;
    int pivot = SelectPivot(left, right);
    pivot = Partition(Array, left, right);
    QuickSort(Array, left, pivot - 1);
    QuickSort(Array, pivot + 1, right);
}


template <class Record>
void sort(Record* Array, int n) {
    QuickSort(Array, 0, n - 1);
}

#include "../SortMain.h"