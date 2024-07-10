#include "swapNums.h"
// 系统有现成的，这里的不再使用
void swapNums(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 内存读写三次，并不高效
// void swapNums(int &a, int &b)
// {
//     a = a ^ b;
//     b = a ^ b;
//     a = a ^ b; // a此时还是第一行的值
// }