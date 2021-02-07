#include <iostream>
#include "Graph.h"
#include "BinaryHeap.h"

using namespace std;

int const VC = 5;
int const BINARY_HEAP_CAPACITY = 3;

int main() {
    BinaryHeap<int> heap(BINARY_HEAP_CAPACITY);

    heap.Insert(10);
    heap.Insert(20);
    heap.Insert(15);
    heap.Insert(5);
    heap.PrintHeapArray();
    cout<< "------ min value is ------->" << heap.FindMinValue()  << endl;

    int deletedData = heap.DeleteMin();
    cout << "Deleted data " << deletedData << endl;

    heap.PrintHeapArray();

    return 0;
}
