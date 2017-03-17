//
// Created by 王宇 on 13/02/2017.
//

#ifndef ALGORITHMS_SELECTIONSORT_H
#define ALGORITHMS_SELECTIONSORT_H

#include <iostream>

using namespace std;

/**
 * 选择排序
 * @tparam T
 * @param arr
 * @param n
 */
template  <typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {

        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

}

#endif //ALGORITHMS_SELECTIONSORT_H
