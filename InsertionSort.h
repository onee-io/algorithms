//
// Created by 王宇 on 13/02/2017.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <iostream>

using namespace std;

/**
 * 插入排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void insertionSort(T arr[], int n) {

    for (int i = 1; i < n; i++) {

        T e = arr[i];
        int j;
        for (j = i; j > 0; j--) {
            if (arr[j - 1] > e) {
                arr[j] = arr[j - 1];
            } else {
                break;
            }
        }
        arr[j] = e;
    }
}

/**
 * 对arr[l...r]范围内的数组进行插入排序
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template <typename T>
void insertionSort(T arr[], int l, int r) {

    for (int i = l+1; i <= r; i++) {
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }

    return;
}

#endif //ALGORITHMS_INSERTIONSORT_H
