#include "bubbleSort.h"
// 简单排序之选择排序，不稳定
// 简单排序之插入排序，样本小且基本有序时效率高

// 简单排序之冒泡排序，太慢
int *bubbleSort(int *p, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (*(p+j)>*(p+j+1))
            {
                swapNums(*(p+j),*(p+j+1));
            }
            
        }
    }

    return p;
}