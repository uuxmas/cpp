#include "selectSort.h"
// 简单排序之冒泡排序，太慢
// 简单排序之插入排序，样本小且基本有序时效率高

// 简单排序之选择排序，不稳定
void selectSort(std::vector<int>& vec)
{
    int n = vec.size();

    if (n <= 1)
    {
        return;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            minIndex = vec[minIndex] > vec[j] ? j : minIndex;
        }
        if (i != minIndex)
        {
            std::swap(vec[i], vec[minIndex]);
        }
    }
}