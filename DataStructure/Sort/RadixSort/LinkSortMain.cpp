#include "../sort.h"
#include "LinkRadixSort.h"

#define ARRAYSIZE 100
#define radix 16
#define DStep 4

int main(int argc, char const *argv[])
{
    Randomize();
    int listsize = ARRAYSIZE;
    Node *Array = new Node[ARRAYSIZE];
    int i;

    for (i=0; i<ARRAYSIZE; i++)
		Array[i].key = Random(ARRAYSIZE);
    
    Settime();
	for (i=0; i<ARRAYSIZE; i+=listsize)  {
		cout << "排序前:" << endl;
		PrintArray<Node>(&Array[i], i);
		RadixSort<Node>(&Array[i], listsize, DStep, radix);
		cout << "排序后:" << endl;
		PrintAddr<Node>(&Array[i], listsize);
	}

	cout << "Sort with list size " << listsize
	   << ", Array size " << ARRAYSIZE << " : " 
       << Gettime() << " seconds\n";

    return 0;
}
