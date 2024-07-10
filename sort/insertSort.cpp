#include "insertSort.h"
// 简单排序之选择排序，不稳定
// 简单排序之冒泡排序，太慢

// 简单排序之插入排序，样本小且基本有序时效率高
// 扑克牌的插入
void insertSort(std::vector<int> &vec)
{
    int n = vec.size();
    
    if (n <= 1)
    {
        return;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (vec[j] > vec[j+1])
            {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}