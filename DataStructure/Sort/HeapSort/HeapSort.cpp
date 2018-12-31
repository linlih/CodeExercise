#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"
#include "Maxheap.h"

template <class Record>
void sort(Record Array[], int n) {
    MaxHeap<Record> max_heap = MaxHeap<Record>(Array, n, n);
    for (int i = 0; i < n; i++)
        max_heap.MoveMax();
}

#include "../SortMain.h"