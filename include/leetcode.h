#pragma once
#include <vector>
#include <queue>

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
int minimumSizeSubarraySum_209(std::vector<int> &vec, int target);

/**
 * 给定一个数组，每一个元素左边比该元素小的所有元素之和，这些和的总和就是该数组的小和。
 */
int smallSum_main(std::vector<int> &vec);

/**
 * 给定一个数组，左边大于右边的元素，算作一个逆序对，求出所有的逆序对的数量。
 */
int reversePair_main(std::vector<int> &vec);

/**
 * 给定一个数组， 一个目标数，要求将小于目标数的放在左边，等于目标数的在中间，大于目标数的放在右边。
 */
void dutchFlagI(std::vector<int> &vec, int l, int r, int target);

// 给定一个数组，基本有序，无序的元素与有序的位置上的差值不大于k个
// 如何使用最快的方式对该数组进行排序，k远小于数组的长度
void sortArrDistanceLessK(std::vector<int> &vec, int k);