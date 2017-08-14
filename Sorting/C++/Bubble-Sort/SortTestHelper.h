//
// Created by 王宇 on 13/02/2017.
//

#ifndef ALGORITHMS_SORTHELPER_H
#define ALGORITHMS_SORTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    /**
     * 生成包含n个元素的随机数据，范围[rangeL, rangeR]
     * @param n
     * @param rangeL
     * @param rangeR
     * @return
     */
    int* generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);   // 断言

        int *arr = new int[n];
        srand(time(NULL));  // 设置随机数种子
        for (int i = 0; i < n; i ++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }

    /**
     * 生成一个近乎排序的数组
     * @param n
     * @param swapTimes
     * @return
     */
    int* generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posX = rand() % n;
            int posY = rand() % n;
            swap(arr[posX], arr[posY]);
        }

        return arr;
    }

    /**
     * 打印数组
     * @tparam T
     * @param arr
     * @param n
     */
    template <typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    /**
     * 测试数据是否已排序
     * @tparam T
     * @param arr
     * @param n
     * @return
     */
    template <typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            };
        }

        return true;
    }

    /**
     * 测试算法性能
     * @tparam T
     * @param sortName
     * @param sort
     * @param arr
     * @param n
     */
    template <typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));

        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }

    /**
     * 拷贝一个新的数组
     * @param a
     * @param n
     * @return
     */
    int* copyIntArray(int a[], int n) {

        int *arr = new int[n];
        copy(a, a + n, arr);    // 源数组头指针，源数组尾指针，目标数组头指针

        return arr;
    }

}

#endif //ALGORITHMS_SORTHELPER_H
