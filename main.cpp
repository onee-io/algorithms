#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
    int n = 1000000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
//    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
//    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete(arr);
    delete(arr2);

    return 0;
}