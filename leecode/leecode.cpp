#include "leecode.h"

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

    int tmp1 = 0;
    int tmp2 = 0;
    int num1 = 0;
    int num2 = 0;

    // 两个所求数字的exclusive值，而出现偶数次的数字exclusive为0
    for (auto &item : vec)
    {
        tmp1 ^= item;
    }

    // 上述结果的数字中为1的位置，都是两个所求数字的不同的地方，得到最右边第一个1，以此来作为两个所求数字的区分
    tmp2 = tmp1 & (~tmp1 + 1);

    // 等于区分数的，在一边，不等于的在另外一边
    for (auto &item : vec)
    {
        if ((item & tmp2) == tmp2)
        {
            num1 ^= item;
        }
    }

    // 异或的结合律
    num2 = tmp1 ^ num1;

    return std::vector<int>{num1, num2};
}

int minimumSizeSubarraySum(std::vector<int> &nums, int target)
{
    int min = __INT_MAX__;
    int size = nums.size();
    int sum = 0;
    int start = 0;
    int end = 0;

    while (end < size)
    {
        sum += nums[end++];
        while (sum >= target)
        {
            min = (end - start) < min ? (end - start) : min;
            sum -= nums[start++];
        }
    }
    return (min == __INT_MAX__) ? 0 : min;
}