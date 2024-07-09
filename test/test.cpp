#include "randomArray.h"
#include "rightOne.h"
#include "bubbleSort.h"
#include "insertSort.h"
#include "selectSort.h"

int main()
{

    std::cout << std::endl
              << "======rightOne=======" << std::endl;
    std::cout << rightOne(5) << " ";
    std::cout << rightOne(8) << " ";
    std::cout << rightOne(10) << " ";
    std::cout << rightOne(7) << " ";

    std::pair<int *, int> myArray1 = randomArray(10, 100);

    std::cout << std::endl
              << "======bubble sort(before)=======" << std::endl;
    for (int i = 0; i < myArray1.second; i++)
    {
        std::cout << myArray1.first[i] << " ";
    }

    myArray1.first = bubbleSort(myArray1.first, myArray1.second);

    std::cout << std::endl
              << "======bubble sort(after)=======" << std::endl;
    for (int i = 0; i < myArray1.second; i++)
    {
        std::cout << myArray1.first[i] << " ";
    }

    delete[] myArray1.first;

    std::pair<int *, int> myArray2 = randomArray(50, 100);

    std::cout << std::endl
              << "======insert sort(before)=======" << std::endl;
    for (int i = 0; i < myArray2.second; i++)
    {
        std::cout << myArray2.first[i] << " ";
    }
    
    myArray2.first = insertSort(myArray2.first, myArray2.second);
    
    std::cout << std::endl
              << "======insert sort(after)=======" << std::endl;
    for (int i = 0; i < myArray2.second; i++)
    {
        std::cout << myArray2.first[i] << " ";
    }

    delete[] myArray2.first;

    std::pair<int *, int> myArray3 = randomArray(30, 100);

    std::cout << std::endl
              << "======select sort(before)=======" << std::endl;
    for (int i = 0; i < myArray3.second; i++)
    {
        std::cout << myArray3.first[i] << " ";
    }
    
    myArray3.first = selectSort(myArray3.first, myArray3.second);
    
    std::cout << std::endl
              << "======select sort(after)=======" << std::endl;
    for (int i = 0; i < myArray3.second; i++)
    {
        std::cout << myArray3.first[i] << " ";
    }

    delete[] myArray3.first;

    std::cout << std::endl
              << "=============" << std::endl;

    return 0;
}
