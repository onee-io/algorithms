#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);

    delete(arr);
    delete(arr2);

    return 0;
}