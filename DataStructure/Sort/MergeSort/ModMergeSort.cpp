#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

#define THRESHOLD 16

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

template <class Record>
void ModMerge(Record Array[], Record TempArray[], int left, int right, int middle) {
    int index1, index2;
    int i, j, k;
    for (i = left; i <= middle; i++)
        TempArray[i] = Array[i];
    for (j = 1; j <= right - middle; j++)
        TempArray[right - j + 1] = Array[j + middle];
    for (index1 = left, index2 = right, k = left; k <= right; k++)
        if (TempArray[index1] <= TempArray[index2])
            Array[k] = TempArray[index1++];
        else Array[k] = TempArray[index2--];
        
}

template <class Record>
void ModMergeSort(Record Array[], Record TempArray[], int left, int right) {
    if (right - left + 1 > THRESHOLD) {
        int middle = (left + right)/2;
        ModMergeSort(Array, TempArray, left, middle);
        ModMergeSort(Array, TempArray, middle + 1, right);
        ModMerge(Array, TempArray, left, right, middle);
    }
    else
        InsertSort(&Array[left], right - left + 1);
}

template <class Record>
void sort(Record* Array, int n) {
    static Record* temp = NULL;
    if (temp == NULL) temp = new Record[n]; 
    ModMergeSort(Array, temp, 0, n - 1);
}

#include "../SortMain.h"
