#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

template <class T>
class MaxHeap {
private:
    T* heapArray;
    int CurrentSize;
    int MaxSize;
public:
    MaxHeap(T* array, int num, int max);
    virtual ~MaxHeap(){};
    void BuildHeap();
    bool isLeaf(int pos) const;
    int leftChild(int pos) const;
    int rightChild(int pos) const;
    int parent(int pos) const;
    bool Remove(int pos, T& node);
    void SiftDown(int left);
    void SiftUp(int pos);
    bool Insert(const T& newNode);
    void MoveMax();
    T& RemoveMax();
};

template <class T>
MaxHeap<T>::MaxHeap(T* array, int num, int max) {
    heapArray = array;
    CurrentSize = num;
    MaxSize = max;
    BuildHeap();
}

template <class T>
void MaxHeap<T>::BuildHeap() {
    for (int i = CurrentSize/2 - 1; i >= 0; i--)
        SiftDown(i);
}

template <class T>
bool MaxHeap<T>::isLeaf(int pos) const {
    return (pos >= CurrentSize/2) && (pos < CurrentSize);
}

template <class T>
int MaxHeap<T>::leftChild(int pos) const {
    return 2*pos + 1;
}

template <class T>
int MaxHeap<T>::rightChild(int pos) const {
    return 2*pos + 2;
}

template <class T>
int MaxHeap<T>::parent(int pos) const {
    return (pos - 1)/2;
}

template <class T>
void MaxHeap<T>::SiftDown(int left) {
    int i = left;
    int j = 2*i + 1;
    T temp = heapArray[i];

    while(j < CurrentSize - 1) {
        if ((j < CurrentSize) && (heapArray[j] < heapArray[j+1]))
            j++;
        if (temp < heapArray[j]) {
            heapArray[i] = heapArray[j];
            i = j;
            j = 2*j + 1;
        }
        else 
            break;
    }
    heapArray[i] = temp;
}

template <class T>
void MaxHeap<T>::SiftUp(int pos) {
    int temppos = pos;
    int parentpos = 0;
    T temp = heapArray[temppos];

    if (temppos > 0)
        parentpos = parent(temppos);
    while((temppos > 0) && (heapArray[parentpos] < temp)) {
        heapArray[temppos] = heapArray[parentpos];
        temppos = parentpos;
        parentpos = parent(temppos);
    }
    heapArray[temppos] = temp;
}

template <class T>
bool MaxHeap<T>::Insert(const T& newNode) {
    if (CurrentSize == MaxSize)
        return false;
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize);
    CurrentSize++;
}

template <class T>
T& MaxHeap<T>::RemoveMax() {
    if (CurrentSize == 0) {

    }
    else {
        T temp = heapArray[0];
        heapArray[0] = heapArray[CurrentSize - 1];
        CurrentSize --;
        SiftDown(0);
        return temp;
    }
}

template <class T>
void MaxHeap<T>::MoveMax() {
    if (CurrentSize == 0)
        return;
    else {
        T temp = heapArray[0];
        heapArray[0] = heapArray[CurrentSize - 1];
        CurrentSize--;
        SiftDown(0);
        heapArray[CurrentSize] = temp;
    }
    return;
}

template <class T>
bool MaxHeap<T>::Remove(int pos, T& node) {
    if ((pos < 0) || (pos > CurrentSize))
        return false;
    heapArray[pos] = heapArray[--CurrentSize];
    SiftUp(pos);
    SiftDown(pos);
    node = heapArray[CurrentSize];
    return true;
}

#endif

