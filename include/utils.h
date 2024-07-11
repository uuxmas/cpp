#pragma once
#include <iostream>
#include <vector>
#include <ctime>

/**
 * @brief Generate a vector of integers using random numbers.
 *
 * @param vec The vector of integers to store random numbers.
 * maxSize, maxValue, maximum size of vector, maximum values of vector
 */
void randomVector(int maxSize, int maxValue, std::vector<int> &vec);

/**
 * @brief Most right one of the given number.
 *
 * @param num The integer number to be solved.
 */
int rightOne(int &num);