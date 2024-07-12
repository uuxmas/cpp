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

void selectSort(std::vector<int> &vec)
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
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

/* 归并排序，本质是递归+merge，左边排好序，右边排好序，整体再合并，利用master公式计算时间复杂度(runtime complexity)*/
// master公式
// T(N) = a*T(N/b) + O(N^d)
// 1) log(b,a) > d 复杂度为O(N^log(b,a))
// 2) log(b,a) = d 复杂度为O(N^d * logN)
// 3) log(b,a) < d 复杂度为O(N^d)

// 归并排序，a=2，b=2，d=1，O(N*logN)
void mergeSort_merge(std::vector<int> &vec, int l, int m, int r) // merge的时间复杂度O(N) ---> d = 1
{
    //  ----------------------------------
    //  ^               ^^               ^
    //  |               ||               |
    //  l              m m+1             r
    //  left            right

    int left = l;
    int right = m + 1;
    std::vector<int> helpVector;

    while (left <= m && right <= r)
    {
        if (vec[left] <= vec[right]) // 一定是<=，因为合并排序算法是稳定的，有相同元素，前面的放前面，小和算法中，这里是只有<没有=
        {
            helpVector.push_back(vec[left++]);
        }
        else
        {
            helpVector.push_back(vec[right++]);
        }
    }
    while (left <= m)
    {
        helpVector.push_back(vec[left++]);
    }
    while (right <= r)
    {
        helpVector.push_back(vec[right++]);
    }

    // 右边的也单独需要排序，所以需要vec.begin()+l，而不是vec.begin()
    std::copy(helpVector.begin(), helpVector.end(), vec.begin() + l);
}

void mergeSort_process(std::vector<int> &vec, int l, int r)
{
    // 判定边界
    if (l == r)
        return;

    // 分半，等号右边的括号需要加上
    int m = l + ((r - l) >> 1);

    // 左边排序
    mergeSort_process(vec, l, m);

    // 右边排序
    mergeSort_process(vec, m + 1, r);

    // 合并
    mergeSort_merge(vec, l, m, r);
}

void mergeSort(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
    {
        return;
    }
    mergeSort_process(vec, 0, n - 1);
}

// 系统自带的排序法
void systemSort(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end(), std::less<int>());
}

// master公式
// T(N) = a*T(N/b) + O(N^d)
// 1) log(b,a) > d 复杂度为O(N^log(b,a))
// 2) log(b,a) = d 复杂度为O(N^d * logN)----归并排序，a=2，b=2，d=1，O(N*logN)
// 3) log(b,a) < d 复杂度为O(N^d)

// 经典快排和随机快排，差在一句话上： 准备partition的时候，是否会先随机挑选vector中的一个数作为参考数
// O(NlogN)---随机快排
// O(N^2)-----经典快排最差情况是O(N^2),因为参考值选的太偏(而好的参考值是数组中值的大小是中间的值),每次只搞定一个数字,比如有序的数组,每次选择最后一个数作为参考数,那么一轮下来只搞定这一个数
// 下一轮,还是选最右边的数,也是只搞定一个数,循环下去是个等差数列,所以是经典快速排序的最差情况就是O(N^2)
// 所以需要改进为随机快速排序,每次不是选择最后一个,而是整个数组中随机找一个,再进行partition的过程,从数学角度来看,随机找的整个参考值是个概率,有可能好,有可能坏
// 但平均值就是O(N*logN)
std::vector<int> quickSort_partition(std::vector<int> &vec, int l, int r)
{
    int cur = l;
    int less = l - 1;
    int more = r;

    while (cur < more)
    {
        if (vec[cur] < vec[r]) // vec[r]作为参考数对vector进行调整
        {
            std::swap(vec[cur], vec[++less]);
            cur++;
        }
        else if (vec[cur] > vec[r]) // vec[r]作为参考数一直没有动过，一直存放在more区域里的最后一个位置
        {
            std::swap(vec[cur], vec[--more]);
        }
        else
        {
            cur++;
        }
    }

    // 最后处理参考数，将其放在合适的位置（more的第一个元素），
    // 此轮调整结束时，参考数的整体位置确定了: 小于参考数的所有数都在参考数的左边，大于参考数的所有数都在参考数的右边
    std::swap(vec[more], vec[r]);

    std::vector<int> boundryVec{less, more + 1}; // 返回此次调整完毕后的less和more的边界，以便进行下一轮的partition

    return boundryVec;
}

void quickSort_process(std::vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int randNum = randomInt() % (r - l + 1); // 随机快排，体现在这两句话
        std::swap(vec[l + randNum], vec[r]);     // 随机快排，体现在这两句话

        std::vector<int> v = quickSort_partition(vec, l, r); // 经典快排从这里开始,中间的值已经排好,所以继续递归左边的整体和右边的整体
        quickSort_process(vec, l, v[0]);
        quickSort_process(vec, v[1], r);
    }
}

void quickSort(std::vector<int> &vec)
{
    int n = vec.size();
    if (n <= 1)
    {
        return;
    }
    quickSort_process(vec, 0, n - 1);
}

// vector中的最大数包含有几位数，如最大数是1324，包含有四位数，如果最大数是29，包含有二位数
int maxBit(std::vector<int> &vec)
{
    int max = maxRecursive(vec, 0, vec.size() - 1);
    int bit = 0;
    while (max != 0)
    {
        max = max / 10;
        bit++;
    }
    return bit;
}

// 获得一个整数的个位，十位，百位，千位等每位上的数字，0表示个位，1表示十位，2表示百位，3表示千位
int getDigit(int num, int bit)
{
    return num / powerRaise(10, bit) % 10;
}

// 基数排序
// 根据键值的每位数字来分配桶；
void radixSort(std::vector<int> &vec)
{
    int d = maxBit(vec);
    int len = vec.size();
    int *p = new int[len];

    for (int i = 0; i < d; i++) // 有几位数字，就需要出入几次bucket，个位，百位，千位等分别进行比较
    {
        int count[10] = {0};

        for (auto &item : vec) // 先统计vec中所有元素的个位数字所对应的数量
        {
            int k = getDigit(item, i);
            count[k]++;
        }

        for (int j = 1; j < 10; j++) // 关键的一步，用来计算未来入桶的位置
        {
            count[j] = count[j - 1] + count[j];
        }

        for (auto item = vec.rbegin(); item < vec.rend(); item++) // 逆序遍历，然后入桶p，入桶的过程就是排序的过程
        {
            int k = getDigit(*item, i);
            *(p + count[k] - 1) = *item;
            count[k]--;
        }
        vec.clear();//清空，不然push的时候是追加了
        for (int m = 0; m < len; m++)
        {
            vec.push_back(*(p+m)); // 出桶，进行下一轮的十位数的排序
        }
    }

    delete [] p;
    p = nullptr;
}