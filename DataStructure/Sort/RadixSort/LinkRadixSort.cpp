#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "LinkSort.h"
#include "LinkRadixSort.h"
using namespace std;

// 十六进制， 4趟
#define radix 16
#define Dstep 4

template <class Record>
void sort(Record* Array, int n) {
    RadixSort(Array, n, Dstep, radix);
}

#include "LinkSortMain.cpp"


/***************************************************
 * 这个代码有误，待调试
 * ************************************************/