#include "utils.h"

void randomVector(int maxSize, int maxValue, std::vector<int> &vec)
{
    std::srand(std::time(0));

    int myRandom = std::rand() % maxSize + 1;

    for (int i = 0; i < myRandom; i++)
    {
        vec.push_back(std::rand() % maxValue);
    }
}

int randomInt()
{
    std::srand(std::time(0));

    return std::rand();
}

int rightOne(int &num)
{
    return num & (~num + 1);
}

// recursive算法，master公式的使用
// T(N) = a*T(N/b) + O(N^d)
// 1) log(b,a) > d 复杂度为O(N^log(b,a))
// 2) log(b,a) = d 复杂度为O(N^d * logN)
// 3) log(b,a) < d 复杂度为O(N^d)

// 以下递归求最大的算法，为a=2，b=2，d=0，runtime complexity = O(N)
int maxRecursive(std::vector<int> &vec, int l, int r)
{
    if (l == r)
    {
        return vec[l];
    }

    int m = (l + r) / 2;
    int left = maxRecursive(vec, l, m);      // T(N/2) --> b = 2
    int right = maxRecursive(vec, m + 1, r); // T(N/2) --> b = 2，两个各是一半规模，所以a=2

    return left > right ? left : right; // runtime complexity = O(1) ----> d = 0;
}

int powerRaise(int base, int exponent)
{
    return (int)(std::pow(base,exponent)+0.5);
}