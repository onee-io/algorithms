//
// Created by 王宇 on 15/08/2017.
//

#ifndef HEAPIFY_MAXHEAP_H
#define HEAPIFY_MAXHEAP_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

/**
 * 最大堆
 * parent(i) = i / 2
 * left = 2 * i
 * right = 2 * i + 1
 * @tparam T
 */
template<typename T>
class MaxHeap {

private:
    T *data;
    int count;
    int capacity;

    /**
     * 入队
     * @param k
     */
    void shiftUp(int k) {
        while (k > 1 && data[k / 2] < data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    /**
     * 出队
     * @param k
     */
    void shiftDown(int k) {
        // 有左孩子才循环
        while (2 * k <= count) {
            int j = 2 * k;  // 用于k交换的索引
            // 和较大的子节点进行交换
            if (j + 1 <= count && data[j] < data[j + 1]) {
                j = 2 * k + 1;
            }
            if (data[k] >= data[j]) {
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MaxHeap(int capacity) {
        data = new T[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    MaxHeap(T arr[], int n) {
        data = new T[n + 1];
        capacity = n;
        for (int i = 0; i < n; ++i) {
            data[i + 1] = arr[i];
        }
        count = n;
        for (int j = n/2; j >= 1; --j) {
            shiftDown(j);
        }
    }

    ~MaxHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool inEmpty() {
        return count == 0;
    }

    void insert(T item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        count++;
        shiftUp(count);
    }

    T extractMax() {
        assert(count > 0);
        T ret = data[1];
        swap(data[1], data[count]);
        count --;
        shiftDown(1);
        return ret;
    }

    void print() {
        for (int i = 1; i <= count; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }

};

#endif //HEAPIFY_MAXHEAP_H
