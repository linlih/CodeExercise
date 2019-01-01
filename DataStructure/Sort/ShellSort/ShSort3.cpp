#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"


template <class Record>
void ModInsSort(Record* Array, int n, int delta) {
    Record TempRecord;
    for (int i = delta; i < n; i+=delta) {
        TempRecord = Array[i];
        int j = i - delta;
        while (j >= 0 && TempRecord < Array[j]) {
            Array[j + delta] = Array[j];
            j = j - delta;
        }
        Array[j + delta] = TempRecord;
    }
}

template <class Record>
void ShellSort(Record Array[], int n) {
    for (int delta = n / 3; delta >= 3; delta /= 3)
        for (int j = 0; j < delta; j++)
            ModInsSort(&Array[j], n - j, delta);
    ModInsSort(Array, n, 1);
}

template <class Record>
void sort(Record* Array, int n) {
    ShellSort(Array, n);
}

#include "../SortMain.h"
