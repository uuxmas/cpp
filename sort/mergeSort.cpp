#include "mergeSort.h"

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