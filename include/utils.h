#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <chrono>

/**
 * @brief Generate a vector of integers using random numbers.
 *
 * @param vec The vector of integers to store random numbers.
 * 
 * @param maxSize Maximum size of the vector.
 * 
 * @param maxValue Maximum value of the vector.
 */
void randomVector(int maxSize, int maxValue, std::vector<int> &vec);

/**
 * @brief Generate an integer using random numbers.
 * @return int Random integer.
 */
int randomInt();

/**
 * @brief Most right one of the given number.
 *
 * @param num The integer number to be solved.
 * @return int Right one result.
 */
int rightOne(int &num);

/**
 * @brief Find out the maximum integer by using recursive way.
 *
 * @param vec The integer vector to be found in.
 * @param l Left index of vector.
 * @param r Right index of vector.
 * 
 * @return int The maximum value of the vector.
 */
int maxRecursive(std::vector<int> &vec, int l, int r);

/**
 * @brief Base is raised to the power of exponent.
 * @param base The first argument of powerRaise .
 * @param exponent The second argument of powerRaise.
 * @return int result.
 */
int powerRaise(int base, int exponent);