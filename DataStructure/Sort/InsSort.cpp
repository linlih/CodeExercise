#include <iostream>
#include <stdlib.h>
#include "sort.h"
using namespace std;

template <class Record>
void InsertSort(Record Array[], int n) {
    Record TempRecord;
    for (int i = 1; i < n; i++) {
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

#include "SortMain.h"