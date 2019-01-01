#ifndef __LINKRADIXSORT_H__
#define __LINKRADIXSORT_H__ 

#define Elem int
class Node {
public:
    Elem key;
    int next;
};

class StaticQueue {
public:
    int head;
    int tail;
};

template <class Record>
void Distribute(Record* Array, int first, int i, int r, StaticQueue* queue) {
    for (int j = 0; j < r; j++)
        queue[j].head = -1;
    while (first != -1) {
        int k = Array[first].key;
        for (int a = 0; a < i; a++)
            k = k / r;
        if (queue[k].head == -1)
            queue[k].head = first;
        else 
            Array[queue[k].tail].next = first;
        queue[k].tail = first;
        first = Array[first].next;
    }
}

template <class Record>
void Collect(Record Array, int& first, int r, StaticQueue* queue) {
    int last, k = 0;
    while (queue[k].head == -1)
        k++;
    first = queue[k].head;
    last = queue[k].tail;
    while (k < r - 1) {
        k++;
        while (k < r-1 && queue[k].head == -1)
            k++;
        if (queue[k].head != -1) {
            Array[last].next = queue[k].head;
            last = queue[k].tail;
        }
    }
    Array[last].next = -1;
}

template <class Record>
void AddrSort(Record* Array, int n, int first) {
    int i, j;
    j = first;
    Record TempRec;
    for (i = 0; i < n - 1; i++) {
        TempRec = Array[j];
        Array[j] = Array[i];
        Array[i] = TempRec;
        Array[i].next = j;
        j = TempRec.next;
        while (j <= i)
            j = Array[j].next;
    }
}

template <class Record>
void RadixSort(Record* Array, int n, int d, int r) {
    int first = 0;
    StaticQueue* queue;
    queue = new StaticQueue[r];
    for (int i = 0; i < n - 1; i++)
        Array[i].next = i + 1;
    Array[n - 1].next = -1;
    int i;
    for (i = 0; i < d; i++) {
        Distribute(Array, first, i, r, queue);
        Collect(Array, first, r, queue);
    }
    delete [] queue;
    AddrSort (Array, n, first);
}


#endif
