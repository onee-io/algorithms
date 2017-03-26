//
// Created by 王宇 on 26/03/2017.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <iostream>

using namespace std;

// 对 arr[l...r] 部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {

    T v = arr[l];

    // arr[l+1...j] < v ; arr[j+1...i) > v
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            swap(arr[j+1], arr[i]);
            j ++;
        }
    }
    swap(arr[l], arr[j]);

    return j;
}

// 递归对 arr[l...r] 部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {

    // 递归终止条件
    if (l >= r)
        return;

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

/**
 * 快速排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void quickSort(T arr[], int n) {

    __quickSort(arr, 0, n - 1);
}

#endif //ALGORITHMS_QUICKSORT_H
