#ifndef __LINKSORT_H__
#define __LINKSORT_H__

#pragma once  // 保证头文件只被编译一次
#include "../sort.h"

template <class Record>
void PrintAddr(Record* Array, int n) {
    cout << "Array contents are : " << endl;
    for (int i = 0; i < n; i++)
        cout << Array[i].key << " ";
    cout << endl;
    cout << "Link contents are : " << endl;
    for (int j = 0; j < n; j++)
        cout << Array[j].next << " ";
    cout << endl;
}

template <class Record>
void PrintArray(Record* Array, int first) {
    int tmp;
    tmp = first;
    while (tmp != -1) {
        cout << Array[tmp].key << " ";
        tmp =  Array[tmp].next;
    }
    cout << endl;
}


#endif
