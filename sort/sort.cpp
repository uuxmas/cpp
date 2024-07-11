#include "sort.h"

// 简单排序之冒泡排序，太慢
// 简单排序之选择排序，不稳定
// 简单排序之插入排序，样本小且基本有序时效率高，类似扑克牌的插入

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

// 已经排序好了的两个数组，进行合并
// 合并排序
void mergeSort(std::vector<int> &vec, int l, int m, int r)
{

    //  ----------------------------------
    //  ^               ^^               ^
    //  |               ||               |
    //  l               nm               r
    //  i                j

    int i = l;
    int n = m - 1;
    int j = m;
    std::vector<int> helpVector;

    while (i <= n && j <= r)
    {
        if (vec[i] <= vec[j])// <=，一定是<=，因为合并排序算法是稳定的，有相同元素，前面的放前面
        {
            helpVector.push_back(vec[i]);
            i++;
        }
        else
        {
            helpVector.push_back(vec[j]);
            j++;
        }
    }
    while (i <= n)
    {
        helpVector.push_back(vec[i]);
        i++;
    }
    while (j <= r)
    {
        helpVector.push_back(vec[j]);
        j++;
    }

    // 右边的也单独需要排序，所以需要vec.begin()+l，而不是vec.begin()
    std::copy(helpVector.begin(),helpVector.end(),vec.begin()+l);
}

void mergeSort(std::vector<int>& v, int l, int r)
{
    // 判定边界
    if (l == r)
        return;

    // 分半
    int m = l + ((r - l) >> 1);

    // 左边排序
    mergeSort(v, l, m);

    // 右边排序
    mergeSort(v, m + 1, r);

    // 合并
    mergeSort(v, l, m + 1, r);
}

void mergeSort(std::vector<int> & v)
{
    int n = v.size();

    if (n <= 1)
    {
        return;
    }
    mergeSort(v, 0, n - 1);
}

void systemSort(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end(), std::less<int>());
}