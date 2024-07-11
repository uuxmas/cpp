#pragma once
#include <iostream>
#include <vector>    //for std::vector
#include <algorithm> //for std::copy, std::sort

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
void mergeSort(std::vector<int> &vec, int l, int r);
void mergeSort(std::vector<int> &vec, int l, int m, int r);

/**
 * @brief Sorts a vector of integers using c++ native sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 */
void systemSort(std::vector<int> &vec);