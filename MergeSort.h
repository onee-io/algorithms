//
// Created by 王宇 on 26/03/2017.
//

#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

#include <istream>
#include "InsertionSort.h"

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r) {

    // 拷贝临时数组
    T aux[r - l + 1];
    for (int i = l; i <= r; i++)
        aux[i-l] = arr[i];

    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        // 先判断索引是否越界，再判断子数组值大小
        if (i > mid) {
            arr[k] = aux[j-l];
            j ++;
        } else if (j > r) {
            arr[k] = aux[i-l];
            i ++;
        } else if (aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i ++;
        } else {
            arr[k] = aux[j-l];
            j ++;
        }
    }
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r) {

    // 递归终止条件
//    if (l >= r)
//        return;

    // 当子数组数量级小于一定值，使用插入排序提高效率
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    // 对于近乎有序的数组，不需要进行归并
    if (arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

/**
 * 归并排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n-1);
}

#endif //ALGORITHMS_MERGESORT_H
