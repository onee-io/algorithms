#include <iostream>
#include <algorithm>
#include "MaxHeap.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void __shiftDown(T arr[], int n, int k) {
    // 有左孩子才循环
    while (2 * k + 1 < n) {
        int j = 2 * k + 1;  // 用于k交换的索引
        // 和较大的子节点进行交换
        if (j + 1 < n && arr[j] < arr[j + 1]) {
            j += 1;
        }
        if (arr[k] >= arr[j]) {
            break;
        }
        swap(arr[k], arr[j]);
        k = j;
    }
}

template<typename T>
void heapSort1(T arr[], int n) {
    MaxHeap<int> maxHeap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.insert(arr[i + 1]);
    }
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.extractMax();
    }
}

template<typename T>
void heapSort2(T arr[], int n) {
    MaxHeap<int> maxHeap = MaxHeap<T>(arr, n);
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.extractMax();
    }
}

template<typename T>
void heapSort3(T arr[], int n) {
    // heapify
    for (int i = (n - 1) / 2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }

    for (int j = n - 1; j > 0; --j) {
        swap(arr[j], arr[0]);
        __shiftDown(arr, j, 0);
    }
}

int main() {

    int n = 1000000;

    // 一般性排序测试
    cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr3, n);
    delete (arr1);
    delete (arr2);
    delete (arr3);
    cout << endl;

    // 几乎有序的数组排序测试
    int swapTimes = 100;
    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort3, arr3, n);
    delete (arr1);
    delete (arr2);
    delete (arr3);
    cout << endl;

    // 包含大量重复元素的数组排序测试
    cout << "Test for Random Array, size = " << n << ", random range [0, 10]" << endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Heap Sort 1", heapSort1, arr1, n);
    SortTestHelper::testSort("Heap Sort 2", heapSort2, arr2, n);
    SortTestHelper::testSort("Heap Sort 3", heapSort3, arr3, n);
    delete (arr1);
    delete (arr2);
    delete (arr3);
    cout << endl;

    return 0;
}