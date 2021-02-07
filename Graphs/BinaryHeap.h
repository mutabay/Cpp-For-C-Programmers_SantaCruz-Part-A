//
// Created by tyyp- on 3.10.2020.
//

#ifndef GRAPHS_BINARYHEAP_H
#define GRAPHS_BINARYHEAP_H

#include <iostream>

//TODO use vectors instead of array
// Heap array starts 0 index.
template <typename AnyType>
class BinaryHeap {
private:
    const int DEFAULT_CAPACITY = 10;
    const int START_INDEX = 0;

    int currentSize;
    int arrayCapacity;
    AnyType * heapArray;

    //Simple Functions
    int parentIndex(int i){ return (i - 1 ) / 2; } //
    int leftChildIndex(int i){ return (2 * i) + 1 ;}
    int rightChildIndex(int i){ return (2 * i) + 2 ;}
    void swap(AnyType& item1, AnyType& item2);
    void EnlargeArray( int newCapacity);

    //Helper Functions
    void PercolateUp(int value);
    void PercolateDown( int holeIndex);
    void BuildHeap();

public:
    //Constructors
    BinaryHeap(): currentSize(0), arrayCapacity(DEFAULT_CAPACITY){ heapArray = new AnyType[DEFAULT_CAPACITY];}
    BinaryHeap(int capacity): currentSize(0), arrayCapacity(capacity) { heapArray = new AnyType[capacity]; }
    BinaryHeap(int capacity, AnyType items[], int itemsSize): currentSize(0), arrayCapacity(capacity)
    {
        //Capacity must bi greater than itemSize.
        while ( itemsSize > capacity)
            capacity *= 1.5;

        heapArray = new AnyType[capacity];

        for (int i = 0; i < itemsSize; ++i)
            heapArray[i] = items[i];
    }

    // destructor
    ~BinaryHeap(){ delete [] heapArray;}

    //Basic heap operations
    void Insert (AnyType value );
    AnyType FindMinValue( );
    AnyType DeleteMin( );
    bool IsEmpty( );
    void MakeEmpty();

    void PrintHeapArray();



};

// Standard swapping method (PASS BY REFERENCE)
template<typename AnyType>
void BinaryHeap<AnyType>::swap(AnyType& item1, AnyType& item2) {
    AnyType temp = item1;
    item1 = item2;
    item2 = temp;
}

// Extends the capacity of heap array.
template<typename AnyType>
void BinaryHeap<AnyType>::EnlargeArray(int newCapacity) {
    AnyType * newHeapArray =new  AnyType[newCapacity];

    for (int i = 0; i < currentSize; ++i)
        newHeapArray[i] = heapArray[i];
    heapArray = newHeapArray;
    arrayCapacity = newCapacity;
}

// Returns true if heap is empty.
template<typename AnyType>
bool BinaryHeap<AnyType>::IsEmpty() {
    return (currentSize == 0);
}

//Prints heap using iostream.
template<typename AnyType>
void BinaryHeap<AnyType>::PrintHeapArray() {
    for (int i = 0; i < currentSize; ++i) {
        std::cout << " [" << heapArray[i] << "] ";
    }
    std::cout << std::endl;
}


// Bubble up to the hole.
template<typename AnyType>
void BinaryHeap<AnyType>::PercolateUp(int index) {
    if (0 == index )
        return ;

    if (heapArray[parentIndex(index)] > heapArray[index] )
    {
        swap(heapArray[parentIndex(index)], heapArray[index]);
        PercolateUp(parentIndex(index));
    }
}

// Standard inserting method for inserting on a data type.
template<typename AnyType>
void BinaryHeap<AnyType>::Insert(AnyType value) {
    //Checking array size.
    if (currentSize +1 == arrayCapacity )
            EnlargeArray(arrayCapacity * 2 );

    heapArray[currentSize] = value;
    currentSize++;
    PercolateUp(currentSize -1);
}

// Finding min value ( high priority in min value)
template<typename AnyType>
AnyType BinaryHeap<AnyType>::FindMinValue() {
    return heapArray[0];
}

// Bubble down to hole .
template<typename AnyType>
void BinaryHeap<AnyType>::PercolateDown(int holeIndex) {
    // Index-Hole is a leaf node.
    if (leftChildIndex(holeIndex) >= currentSize)
        return;

    // For comparison.
    int minIndex = holeIndex;

    if (heapArray[ leftChildIndex(holeIndex) ] < heapArray[holeIndex])
        minIndex = leftChildIndex(holeIndex);

    if (heapArray[ rightChildIndex(holeIndex) ] < heapArray[minIndex] &&
        heapArray [ rightChildIndex(holeIndex) ] < currentSize)
        minIndex = rightChildIndex(holeIndex);

    if (minIndex != holeIndex)
    {
        swap(heapArray[holeIndex],heapArray[minIndex]);
        PercolateDown(minIndex);
    }

}

// Deleting and returning min value (priority).
template<typename AnyType>
AnyType BinaryHeap<AnyType>::DeleteMin() {

    if( IsEmpty() )
        throw "Underflow Exception";

    AnyType minItem = FindMinValue();
    // Decreasing current size and gathering hole on the root.
    heapArray[0] = heapArray[--currentSize];

    PercolateDown(START_INDEX);

    return minItem;
}

// Fills with 0 and make currentSize 0
template<typename AnyType>
void BinaryHeap<AnyType>::MakeEmpty() {
    for (int i = 0; i < currentSize; ++i) {
        heapArray[i] = 0;
    }
    currentSize = 0;
}

// Establish heap order property from an arbitrary arrangement
//of items. Runs in linear time.
template<typename AnyType>
void BinaryHeap<AnyType>::BuildHeap() {
    for (int i = parentIndex(currentSize - 1); i > 0; i--)
        PercolateDown(i);
}


#endif //GRAPHS_BINARYHEAP_H
