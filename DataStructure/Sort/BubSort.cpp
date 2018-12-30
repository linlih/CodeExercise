#include <iostream>
#include <stdlib.h>
#include "sort.h"

using namespace std;

template <class Record>
void BubbleSort(Record Array[], int n) {
    bool NoSwap;
    for (int i = 0; i < n - 1; i++) {
        NoSwap = true;
        for (int j = n - 1; j > i; j--)
            if (Array[j] < Array[j - 1]) {
                swap(Array, j, j - 1);
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

#include "SortMain.h"