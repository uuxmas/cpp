#include "utils.h"

void randomVector(int maxSize, int maxValue, std::vector<int> &vec)
{
    std::srand(std::time(0));

    int myRandom = rand() % maxSize + 1;

    for (int i = 0; i < myRandom; i++)
    {
        vec.push_back(rand() % maxValue);
    }
}

int rightOne(int &num)
{
    return num & (~num + 1);
}