#include "randomArray.h"

std::pair<int *, int> randomArray(int maxSize, int maxValue)
{

    std::srand(std::time(0));

    int myRandom = rand() % maxSize + 1;

    std::cout << "random value:" << myRandom << std::endl;

    int *arr = new int[myRandom]; // 创建一个 myRandom个元素的数组

    for (int i = 0; i < myRandom; i++)
    {
        arr[i] = rand() % maxValue;
        std::cout << "random arr:" << arr[i] << std::endl;
    }

    return std::make_pair(arr, myRandom);
}