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
 * @param l,m,r The index of vector
 */
void mergeSort(std::vector<int> &vec);
void mergeSort_process(std::vector<int> &vec, int l, int r);
void mergeSort_merge(std::vector<int> &vec, int l, int m, int r);

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
 * @param l The left index of vector.
 * @param r The right index of vector.
 */
std::vector<int> quickSort_partition(std::vector<int> &vec, int l, int r);
void quickSort_process(std::vector<int> &vec, int l, int r);
void quickSort(std::vector<int> &vec);


/**
 * @brief Sorts a vector of integers using radix algorithm.
 *
 * @param vec The vector of integers to be sorted.
 * @param bit The quantity of digits, 123 has 3, 1876 has 4.
 * @param maxBit function of max in vector.
 */
int maxBit(std::vector<int> &vec);
int getDigit(int num, int bit);
void radixSort(std::vector<int> &vec);