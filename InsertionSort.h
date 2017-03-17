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

#endif //ALGORITHMS_INSERTIONSORT_H
