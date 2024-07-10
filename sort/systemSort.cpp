#include "systemSort.h"

void systemSort(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end(), std::less<int>());
}