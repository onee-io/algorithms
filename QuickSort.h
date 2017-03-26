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

// 三路快速排序处理 arr[l...r]
// 将arr[l...r]分为 <v ; ==v ; >v 三部分
// 之后对 <v 和 >v 的部分继续进行三路快速排序
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {

    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // partition
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int lt = l;     // arr[l+1...lt] < v
    int gt = r + 1; // arr[gt...r] > v
    int i = l + 1;  // arr[lt+1...i] == v
    while (i < gt) {
        if (arr[i] < v) {
            swap(arr[i], arr[lt+1]);
            lt ++;
            i ++;
        } else if (arr[i] > v) {
            swap(arr[i], arr[gt-1]);
            gt --;
        } else {
            i ++;
        }
    }
    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);
}

/**
 * 普通快速排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void quickSort(T arr[], int n) {

    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

/**
 * 三路快速排序
 * @tparam T
 * @param arr
 * @param n
 */
template <typename T>
void quickSort3Ways(T arr[], int n) {

    srand(time(NULL));
    __quickSort3Ways(arr, 0, n-1);
}

#endif //ALGORITHMS_QUICKSORT_H
