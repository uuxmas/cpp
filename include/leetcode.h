#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "class.h"
#include "utils.h"
#include "sort.h"

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

/**
 * 两数之和，没有重复元素，返回满足要求的两个下标，但是，数组中同一个元素不能使用两遍。
 */
std::vector<int> twoSum_1(const std::vector<int> &vec, int target);

/**
 * 打印两个有序链表中相同的元素
 */
void orderedTwoListsSameElements();

/**
 * check palindrome， 判断链表是否为palindrome回文结构
 */
bool isPalindromeI(LinkList &myList);

bool isPalindromeII(LinkList &myList);

/**
 * Given a single link list and a pivot，adjust link list
 * in a way where 小于的放其左边，大于的放其右边，中间放pivot，runtime comoplexity = O(N)
 * 如果是笔试，则直接最简单的方式，让空间复杂度高一些，extra space = O(N)，
 * 这样直接定义一个vec，空间复杂度变成了O(N)，类似“两数和”的问题，通过哈希表求解
 */
void partitionList(LinkList &myList, int pivot);

/**
 * 要求extra space O(1)
 */
void partitionListII(LinkList &myList, int pivot);

/**
 * 给定一个链表，每个节点附带一个随机指向别的节点的指针，请拷贝一份一模一样的链表
 */
Node *copyListWithRandNode(LinkList &myList);

/**
 * 两个单链表，可能有环，也可能无环。实现一个函数，两个链表相交则返回相交的节点，不相交则返回空
 */
Node *intersectLists(LinkList &myList1, LinkList &myList2);

/**
 * 两个都没有成环，但是有可能相交，Y字型的情况
 */
Node *intersectListsNoLoop(LinkList &myList1, LinkList &myList2);

/**
 * 两个都成环，但是有可能相交，6字型的情况
 */
Node *intersectListsBothLoop(LinkList &myList1, Node *loop1, LinkList &myList2, Node *loop2);

/**
 * 如果一个链表有环，则返回开始入环的节点，没有则返回空，入环节点的内存地址
 * */
Node *getLoopPoint(LinkList &myList);

/**
 * 给定二叉树的根节点，以及二叉树上的两个节点node1， node2，
 * 求两个节点的最低位置的那个共同祖先
 */
TNode * lowestCommonAncestor(TNode *root, TNode *node1, TNode *node2);

/**
 * 所有节点的父节点都一一对应起来，放入哈希表
 */
void fatherMap(TNode *&node, std::unordered_map<TNode *, TNode *> &map);

/**
 * 一个比较复杂难懂的最低共同祖先的递归
 */
TNode *lowestCommonAncestorII(TNode *root, TNode *node1, TNode *node2);