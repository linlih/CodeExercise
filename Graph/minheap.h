// 堆的代码实现
#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#define FALSE 0
#define TRUE  1;


template <class T>
class MinHeap {
private:
    T *heapArray;
    int CurrentSize;
    int MaxSize;
    void swap(int pos_x, int pox_y);
    void BuildHeap();
public:
    MinHeap(const int n);
    virtual ~MinHeap(){delete []heapArray;};
    bool isLeaf(int pos) const;
    int leftchild(int pos) const;
    int rightchild(int pos) const;
    int parent(int pos) const;
    bool Remove(int pos, T &node);
    T& RemoveMin();
    bool Insert(const T &newnode);
    void SiftUp(int position);
    void SiftDown(int left);
    bool isEmpty() {
        return ((CurrentSize)?false:true);
    }
};

template<class T>
MinHeap<T>::MinHeap(const int n) {
    if (n < 0)
        return;
    
    CurrentSize = 0;
    MaxSize     = n;
    heapArray   = new T[MaxSize];

    BuildHeap();
}

template<class T>
bool MinHeap<T>::isLeaf(int pos) const {
    return (pos>=CurrentSize/2) && (pos < CurrentSize);
}

template<class T>
void MinHeap<T>::BuildHeap() {
    for (int i = CurrentSize/2 - 1; i >= 0; i--){
        SiftDown(i);
    }
}

template<class T>
int MinHeap<T>::leftchild(int pos) const {
    return 2 * pos + 1;
}

template<class T>
int MinHeap<T>::rightchild(int pos) const {
    return 2 * pos + 2;
}

template<class T>
int MinHeap<T>::parent(int pos) const {
    return (pos - 1) / 2;
}

template<class T>
bool MinHeap<T>::Insert(const T &newNode) {
    if (CurrentSize == MaxSize)
        return FALSE;
    heapArray[CurrentSize] = newNode;
    SiftUp(CurrentSize);
    CurrentSize ++;
    return TRUE;
}

template<class T>
void MinHeap<T>::SiftUp(int position) {
    int temppos = position;
    T temp = heapArray[temppos];

    while((temppos > 0) && (heapArray[parent(temppos)] > temp)) {
        heapArray[temppos] = heapArray[parent(temppos)];
        temppos = parent(temppos);
    }
    heapArray[temppos] = temp;
}

template<class T>
void MinHeap<T>::swap(int pos_x, int pos_y) {
    T temp = heapArray[pos_x];
    heapArray[pos_x] = heapArray[pos_y];
    heapArray[pos_y] = temp;
}

template<class T>
T& MinHeap<T>::RemoveMin() {
    if (CurrentSize == 0) {
        cout << "Can't Delete";
    }
    else {
        swap(0, --CurrentSize);
        if (CurrentSize > 1) 
            SiftDown(0);
        return heapArray[CurrentSize];
    }
}

template<class T>
bool MinHeap<T>::Remove(int pos, T& node) {
    if ( (pos < 0) || pos >= CurrentSize)
        return false;
    node = heapArray[pos];
    heapArray[pos] = heapArray[--CurrentSize];
    if (heapArray[parent(pos)] > heapArray[pos]) 
        SiftUp(pos);
    else 
        SiftDown(pos);
    return true;
}

template<class T>
void MinHeap<T>::SiftDown(int left) {
    int i = left;
    int j = leftchild(i);
    T temp = heapArray[i];

    while(j < CurrentSize) {
        if ((j < CurrentSize - 1) && (heapArray[j] > heapArray[j + 1]))
            j ++;
        if (temp > heapArray[j]) {
            heapArray[i] = heapArray[i];
            i = j;
            j = leftchild(j);
        }
        else break;
    }
    heapArray[i] = temp;
}

#endif
