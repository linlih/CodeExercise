#include <iostream>
#include <stdlib.h>

using namespace std;
#include "sort.h"

template <class Record>
void BucketSort(Record Array[], int n, int max) {
    int* TempArray = new Record[n];
    int* count = new int[max];
    int i;

    for (i = 0; i < n; i++)
        TempArray[i] = Array[i];
    for (i = 0; i < max; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[Array[i]]++;
    for (i = 1; i < max; i++)
        count[i] = count[i - 1] + count[i];
    for (i = n - 1; i >= 0; i--)
        Array[--count[TempArray[i]]] = TempArray[i];
}

template <class Record>
void sort(Record *Array, int n) {
    BucketSort(Array, n, 100);
}

#include "SortMain.h"