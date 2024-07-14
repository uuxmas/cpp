#pragma once
#include <iostream>
#include <vector>    //for std::vector
#include <algorithm> //for std::copy, std::sort
#include "utils.h"

/**
 * @brief Sorts a vector of integers using bubble sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void bubbleSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using select sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void selectSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using insert sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void insertSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using merge sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void mergeSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using c++ native sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void systemSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using random quick sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void quickSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using radix algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void radixSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using big root heap algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void bigRootHeapSort(std::vector<int> &vec);

/**
 * @brief Sorts a vector of integers using small root heap algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void smallRootHeapSort(std::vector<int> &vec);

/**
 * @brief Heapify a given vector of integers.
 *
 * @param vec The vector of integers to be heapified.
 * @param flag 0, small root heapified, 1, big root heapified.
 */
void rootHeapify(std::vector<int> &vec, bool flag);