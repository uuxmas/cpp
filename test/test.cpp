#include "randomVector.h"
#include "rightOne.h"
#include "bubbleSort.h"
#include "insertSort.h"
#include "selectSort.h"
#include "mergeSort.h"
#include "systemSort.h"

#define TESTTIME 10000 // 500000
#define MAXSIZE 1000
#define MAXVALUE 100

int main()
{
    int testTime = TESTTIME;
    bool success = true;

    while (testTime--)
    {
        std::vector<int> v;
        randomVector(MAXSIZE, MAXVALUE, v);

        std::vector<int> testVector1 = v;
        std::vector<int> testVector2 = v;
        std::vector<int> testVector3 = v;
        std::vector<int> testVector4 = v;
        std::vector<int> testVector5 = v;

        bubbleSort(testVector1);
        insertSort(testVector2);
        selectSort(testVector3);
        mergeSort(testVector4);
        systemSort(testVector5);

        if (testVector1 == testVector2 &&
            testVector2 == testVector3 &&
            testVector3 == testVector4 &&
            testVector4 == testVector5
            )
        {
#ifdef DEBUG
            std::cout << "Time " << TESTTIME - testTime << " OK" << std::endl;
#endif
        }
        else
        {
            std::cout << "Time " << TESTTIME - testTime << " NG" << std::endl;
            success = false;
            break;
        }
    }
    std::cout << "=================================" << std::endl;
    std::cout << TESTTIME - testTime - 1 <<"/"<< TESTTIME << " rounds sort test complete" << std::endl;
    std::cout << (success ? "Everything is Okay" : "Opps,NG") << std::endl;
    std::cout << "=================================" << std::endl;
    return 0;
}
