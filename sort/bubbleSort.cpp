#include "bubbleSort.h"
// 简单排序之选择排序，不稳定
// 简单排序之插入排序，样本小且基本有序时效率高

// 简单排序之冒泡排序，太慢
void bubbleSort(std::vector<int> &vec)
{
    int n = vec.size();
    
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}