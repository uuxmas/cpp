#include "bubbleSort.h"

int *bubbleSort(int *p, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (*(p+j)>*(p+j+1))
            {
                swapNums(*(p+j),*(p+j+1));
            }
            
        }
    }

    return p;
}