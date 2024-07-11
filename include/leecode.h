#pragma once
#include <vector>

/**
 * @brief Given a non-empty array of integers nums, every element appears twice except for one.
 * Find that single one.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 *
 * @param vec The vector of integers to be solved.
 */
int singleNumber_136(std::vector<int> &vec);

/**
 * @brief Given an integer array nums where every element appears
 * three times except for one, which appears exactly once.
 * Find the single element and return it.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 *
 * @param vec The vector of integers to be solved.
 */
int singleNumberII_137(std::vector<int> &vec);

/**
 * Given an integer arrays nums where every element appears even times
 * except for two, which appear exactly one.
 * Find these two elements and return them.
 */
std::vector<int> twoNumbers(std::vector<int> &vec);

/**
 * Given an array of positive integer nums and a positive integer target,
 * return the minimal length of a consecutive subarray whose sum is greater than or equal to target.
 * If there is no such subarray, return 0 instead.
 */
int minimumSizeSubarraySum(std::vector<int> &nums, int target);