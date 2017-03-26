//
// Created by 王宇 on 26/03/2017.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <iostream>

using namespace std;

// 双路快速排序
// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition2(T arr[], int l, int r) {

    // 随机抽取一个元素与第一个元素交换
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    // arr[l+1...i) <= v ; arr(j...r] >= v
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l + 1 && arr[j] > v) j--;
        // 循环终止条件
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);

    return j;
}

// 对 arr[l...r] 部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {

    // 随机抽取一个元素与第一个元素交换
    swap(arr[l], arr[rand()%(r-l+1)+l]);
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
//    if (l >= r)
//        return;

    // 当子数组数量级小于一定值，使用插入排序提高效率
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // 普通随机快排
//    int p = __partition(arr, l, r);
    // 双路快排
    int p = __partition2(arr, l, r);
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

    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

#endif //ALGORITHMS_QUICKSORT_H
