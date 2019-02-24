#include <iostream>
#include <stdlib.h>

#include "sort.h"

template <class Record>
void SelectSort(Record Array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i+1; j < n; j++) {
            if (Array[j] < Array[smallest])
                smallest = j;
        }
        swap(Array, i, smallest);
    }
}

template <class Record>
void sort(Record* Array, int n) {
    SelectSort(Array, n);
}

#include "SortMain.h"