#include "leetcode.h"

int singleNumber_136(std::vector<int> &vec)
{
    int result = 0;
    for (auto &item : vec)
    {
        result ^= item;
    }
    return result;
}

int singleNumberII_137(std::vector<int> &vec)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int single_sum = 0;
        for (auto &item : vec)
        {
            single_sum += item >> i & 1;
        }
        result += single_sum % 3 << i;
    }
    return result;
}

std::vector<int> twoNumbers(std::vector<int> &vec)
{
    int eor = 0;
    int rightOne = 0;
    int num1 = 0;
    int num2 = 0;

    // 两个所求数字的exclusive值，而出现偶数次的数字exclusive为0
    for (auto &item : vec)
    {
        eor ^= item;
    }

    // 上述结果的数字中为1的位置，都是两个所求数字的不同的地方，得到最右边第一个1，以此来作为两个所求数字的区分
    rightOne = eor & (~eor + 1);

    // 等于区分数的，在一边，不等于的在另外一边
    for (auto &item : vec)
    {
        if ((item & rightOne) == rightOne)
        {
            num1 ^= item;
        }
    }

    // 异或的结合律
    num2 = eor ^ num1;

    return std::vector<int>{num1, num2};
}

/**
 * 用双指针 start 和 end 表示一个滑动窗口。
 * 1. end 向右移增大窗口，直到窗口内的数字和大于等于 target，进行第 2 步。
 * 2. 记录此时的长度，start 向右移动，开始减少长度，每减少一次，就更新最小长度。直到当前窗口内的数字和小于 target，回到第 1 步。
 */
int minimumSizeSubarraySum_209(std::vector<int> &vec, int target)
{
    int min = __INT_MAX__;
    int size = vec.size();
    int sum = 0;
    int start = 0;
    int end = 0;
    // 子数组中连续元素之和大于等于target值时，满足要求的子数组中的数组元素个数最少是多少
    while (end < size)
    {
        sum += vec[end++]; // 尾指针逐渐后移，满足要求时停止
        while (sum >= target)
        {
            min = (end - start) < min ? (end - start) : min;
            sum -= vec[start++]; // 满足要求后头指针逐渐后移
        }
    }
    return (min == __INT_MAX__) ? 0 : min;
}

// 计算小数和，归并排序的衍生
// 在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和
//  ----------------------------------
//  ^               ^^               ^
//  |               ||               |
//  l              m m+1             r
//  left            right
int smallSum_merge(std::vector<int> &vec, int l, int m, int r)
{
    int left = l;
    int right = m + 1;
    int sumMerge = 0;
    std::vector<int> helpVector;

    while (left <= m && right <= r)
    {
        sumMerge += vec[left] < vec[right] ? vec[left] * (r - right + 1) : 0;      // 大于或者等于时，不产生小和，当前右边有多少个数比vec[left]大
        helpVector.push_back(vec[left] < vec[right] ? vec[left++] : vec[right++]); // 一定是<，与merge排序最不一样的地方，没有等号=这里，也就是出现相等时，必须先拷贝右边的数据，也就是让右边的指针移动，而且不产生小和
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
    return sumMerge;
}

int smallSum_process(std::vector<int> &vec, int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    // 分半，等号右边的括号需要加上
    int m = l + ((r - l) >> 1);
    // 左边排序
    int sumL = smallSum_process(vec, l, m);
    // 右边排序
    int sumR = smallSum_process(vec, m + 1, r);
    // 合并
    int sumM = smallSum_merge(vec, l, m, r);

    return sumL + sumR + sumM;
}

int smallSum_main(std::vector<int> &vec)
{
    int n = vec.size();
    int smallSum = 0;

    if (n <= 1)
    {
        return 0;
    }

    smallSum = smallSum_process(vec, 0, n - 1);

    return smallSum;
}

// 在一个数组中，左边的数如果比右边的大，则这两个数构成一个逆序对，请打印所有逆序对
// 计算逆序对的数量，reverse pair，归并排序的衍生
//  ----------------------------------
//  ^               ^^               ^
//  |               ||               |
//  l              m m+1             r
//              left                right
int reversePair_merge(std::vector<int> &vec, int l, int m, int r)
{
    int left = m;
    int right = r;
    int reversePair = 0;
    std::vector<int> helpVector;

    while (left >= l && right >= m + 1)
    {
        reversePair += vec[left] > vec[right] ? (right - (m + 1) + 1) : 0;                            // 大的数字，要离开，队列有序才能O(1)的时间复杂度立刻算出来有多少个逆序对
        helpVector.insert(helpVector.begin(), (vec[left] > vec[right] ? vec[left--] : vec[right--])); // 大的数字进入队列时，还是需要升序排列，才能快速算出逆序对的数量,所以使用头插法
    }
    while (left >= l)
    {
        helpVector.insert(helpVector.begin(), vec[left--]);
    }
    while (right >= m + 1)
    {
        helpVector.insert(helpVector.begin(), vec[right--]);
    }
    // 右边的也单独需要排序，所以需要vec.begin()+l，而不是vec.begin()
    std::copy(helpVector.begin(), helpVector.end(), vec.begin() + l);
    return reversePair;
}

int reversePair_process(std::vector<int> &vec, int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    // 分半，等号右边的括号需要加上
    int m = l + ((r - l) >> 1);
    // 左边排序
    int reverseL = reversePair_process(vec, l, m);
    // 右边排序
    int reverseR = reversePair_process(vec, m + 1, r);
    // 合并
    int reverseM = reversePair_merge(vec, l, m, r);

    return reverseL + reverseR + reverseM;
}

int reversePair_main(std::vector<int> &vec)
{
    int n = vec.size();
    int reversePair = 0;

    if (n <= 1)
    {
        return 0;
    }

    reversePair = reversePair_process(vec, 0, n - 1);

    return reversePair;
}

// 荷兰国旗问题（三色球分类问题）
void dutchFlagI(std::vector<int> &vec, int l, int r, int target)
{
    int cur = l;
    int less = l - 1;
    int more = r + 1;

    while (cur < more)
    {
        if (vec[cur] < target)
        {
            // 该值与less的下一个互换，less区域右扩，cur右移
            std::swap(vec[cur], vec[++less]);
            cur++;
        }
        else if (vec[cur] > target)
        {
            // 该值与more的上一个互换，more区域左扩，cur不动，因为要继续比较新换过来的
            std::swap(vec[cur], vec[--more]);
        }
        else
        { // 相等，则cur右移
            cur++;
        }
    }
}

// 给定一个数组，基本有序，无序的元素与有序的差值不大于k个
// 如何使用最快的方式对该数组进行排序，k远小于数组的长度
void sortArrDistanceLessK(std::vector<int> &vec, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> q; // 小根堆，默认是大根堆
    // std::priority_queue<int, std::vector<int>, std::less<int>> q; // 大根堆

    int n = vec.size();
    std::vector<int> v;

    int i = 0;
    for (; i <= k; i++)
    {
        q.push(vec[i]);
    }
    for (; i < n; i++)
    {
        v.push_back(q.top());
        q.pop();
        q.push(vec[i]);
    }
    while (!q.empty())
    {
        v.push_back(q.top());
        q.pop();
    }
    
    vec = v;
}
