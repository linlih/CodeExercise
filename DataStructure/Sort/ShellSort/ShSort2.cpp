#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

template <class Record>
void ModInsSort(Record* Array, int n, int delta) {
    for (int i = delta; i < n; i+= delta)
        for (int j = i; j >= delta; j-=delta) {
            if (Array[j] < Array[j - delta])
                swap(Array, j, j - delta);
            else
                break;    
        }

}

template <class Record>
void ShellSort(Record Array[], int n) {
    for (int delta =n / 2; delta >0; delta /= 2)
        for (int i = 0; i < delta; i++) 
            ModInsSort(&Array[i], n - i, delta);
}

template <class Record>
void sort(Record* Array, int n) {
    ShellSort(Array, n);
}

#include "../SortMain.h"