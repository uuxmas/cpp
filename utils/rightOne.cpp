#include "rightOne.h"

int rightOne(int num)
{
    return num & (~num + 1);
}