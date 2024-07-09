#include "randomArray.h"

int main()
{
    std::pair<int *, int> myArray = randomArray(10, 100);
    
    for (int i = 0; i < myArray.second; i++)
    {
        std::cout << myArray.first[i] << std::endl;
    }
    return 0;
}
