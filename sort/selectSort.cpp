#include "selectSort.h"
// 简单排序之冒泡排序，太慢
// 简单排序之插入排序，样本小且基本有序时效率高

// 简单排序之选择排序，不稳定
int *selectSort(int *p, int len)
{
    if (p == nullptr)
    {
        return p;
    }

    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            minIndex = *(p + minIndex) > *(p + j) ? j : minIndex;
        }
        // 一轮比较完毕后交换值
        if (i != minIndex)
        { // 如果相等，说明顺序正常，不需要更换，不加判断的话，则异或为0了
            swapNums(*(p + i), *(p + minIndex));
        }
    }

    return p;
}