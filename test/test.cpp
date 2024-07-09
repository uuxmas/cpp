#include "randomArray.h"
#include "rightOne.h"
#include "bubbleSort.h"

int main()
{
    std::pair<int *, int> myArray = randomArray(10, 100);

    for (int i = 0; i < myArray.second; i++)
    {
        std::cout << myArray.first[i] << " ";
    }
    std::cout << std::endl
              << "=============" << std::endl;

    std::cout << rightOne(5) << " ";
    std::cout << rightOne(8) << " ";
    std::cout << rightOne(10) << " ";
    std::cout << rightOne(7) << " ";
    std::cout << std::endl;

    std::cout << std::endl
              << "=============" << std::endl;

    bubbleSort(myArray.first, myArray.second);
    for (int i = 0; i < myArray.second; i++)
    {
        std::cout << myArray.first[i] << " ";
    }

    std::cout << std::endl
              << "=============" << std::endl;
    
    delete[] myArray.first;

    return 0;
}
