#ifndef __SORT_H__
#define __SORT_H__

#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int THRESHOLD = 29;


inline void Randomize() {
    srand(1);
}

inline int Random(int n) {
    return rand() % (n);
}

template <class Record>
inline void swap(Record A[], int i, int j) {
    Record temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <class Record>
inline void sway(Record& e1, Record& e2) {
    Record temp = e1;
    e1 = e2;
    e2 = temp;
}

template <class Record>
void Print(Record *array, int listsize) {
    for (int i = 0; i < listsize; i++)
        cout << array[i] << " ";
    cout << endl;
}

clock_t tstart = 0;

void Settime() {
    tstart = clock();
}

double Gettime() {
    return (double)((double)clock() - (double)tstart) /
           (double)CLOCKS_PER_SEC;
}

class Int {
private:
    int val;
public:
    Int(int input = 0) {val = input;};
    int key() const {return val;};
    Int operator = (int input) {val = input;};
};

ostream& operator << (ostream& s, const Int& i) {
    return s << i.key();
}

ostream& operator << (ostream& s, const Int* i) {
    return s << i->key();
}

#endif
