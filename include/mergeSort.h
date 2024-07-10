#pragma once
#include <vector>
#include <algorithm> //for std::copy
/**
 * @brief Sorts a vector of integers using merge sort algorithm.
 *
 * @param vec The vector of integers to be sorted.
 * l,m,r The index of vector
 */
void mergeSort(std::vector<int>& vec);
void mergeSort(std::vector<int>& vec, int l, int r);
void mergeSort(std::vector<int>& vec, int l, int m, int r);