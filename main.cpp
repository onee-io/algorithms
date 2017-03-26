#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

int main() {
    int n = 1000000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::copyIntArray(arr, n);

//    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
//    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);

    delete(arr);
    delete(arr2);
    delete(arr3);

    return 0;
}