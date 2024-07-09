#include "insertSort.h"
// 简单排序之选择排序，不稳定
// 简单排序之冒泡排序，太慢

// 简单排序之插入排序，样本小且基本有序时效率高
// 扑克牌的插入
int *insertSort(int *p, int len)
{
    if (p == nullptr)
    {
        return p;
    }

    for (int i = 1; i < len; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (*(p + j) > *(p + j + 1))
            {
                swapNums(*(p + j), *(p + j + 1));
            }
        }
    }

    return p;
}