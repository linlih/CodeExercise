#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

#define radix 15
#define DStep 4

template <class Record>
void RadixSort(Record* Array, int n, int d, int r) {
    Record *TempArray = new Record[n];
    int* count = new int[r];
    int i, j, k;
    int Radix = 1;
    for (i = 0; i < d; i++) {
        for (j = 0; j < r; j++) 
            count[j] = 0;
        for (j = 0; j < n; j++) {
            k = (Array[j] / Radix) % r;
            count[k]++;
        }
        for (j = 1; j < r; j++)
            count[j] = count[j - 1] + count[j];
        for (j = n - 1; j >= 0; j--) {
            k = (Array[j] / Radix) % r;
            count[k]--;
            TempArray[count[k]] = Array[j];
        }
        for (j = 0; j < n; j++)
            Array[j] = TempArray[j];
        Radix *= r;
    }
}

template <class Record>
void sort(Record* Array, int n) {
    RadixSort(Array, n, DStep, radix);
}

#include "../SortMain.h"
