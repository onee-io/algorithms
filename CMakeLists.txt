cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h SelectionSort.h InsertionSort.h BubbleSort.h ShellSort.h MergeSort.h QuickSort.h)
add_executable(Algorithms ${SOURCE_FILES})