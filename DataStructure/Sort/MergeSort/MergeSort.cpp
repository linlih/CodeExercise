#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

template <class Record>
void Merge(Record Array[], Record TempArray[], int left, int right, int middle) {
    for (int j = left; j <= right; j++)
        TempArray[j] = Array[j];
    int index1 = left;
    int index2 = middle + 1;
    int i = left;
    while (index1 <= middle && index2 <= right) {
        if (TempArray[index1] <= TempArray[index2])
            Array[i++] = TempArray[index1++];
        else 
            Array[i++] = TempArray[index2++];
    }
    while (index1 <= middle)
        Array[i++] = TempArray[index1++];
    while (index2 <= right)
        Array[i++] = TempArray[index2++];
}

template <class Record>
void MergeSort(Record Array[], Record TempArray[], int left, int right) {
    if (left < right) {
        int middle = (left + right)/2;
        MergeSort(Array, TempArray, left, middle);
        MergeSort(Array, TempArray, middle + 1, right);
        Merge(Array, TempArray, left, right, middle);
    }
}

template <class Record>
void sort(Record* Array, int n) {
    static Record* temp = NULL;
    if (temp == NULL)
        temp = new Record[n];
    MergeSort(Array, temp, 0, n - 1);
}

#include "../SortMain.h"

