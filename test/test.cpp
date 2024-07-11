#include "utils.h"
#include "sort.h"
#include "leecode.h"

// #define TESTTIME 10000 // 500000
// #define MAXSIZE 1000
// #define MAXVALUE 100

int main()
{
    std::vector<int> vec1{80, 285, 80, 70, 139, 285, 70};
    int n1 = singleNumber_136(vec1);
    std::cout << "n1 = " << n1 << std::endl;

    std::vector<int> vec2{180, 90, 180, 91, 34, 90, 90, 34, 180, 34};
    int n2 = singleNumberII_137(vec2);
    std::cout << "n2 = " << n2 << std::endl;

    // system("pause");

    //     int testTime = TESTTIME;
    //     bool success = true;

    //     while (testTime--)
    //     {
    //         std::vector<int> v;
    //         randomVector(MAXSIZE, MAXVALUE, v);

    //         std::vector<int> testVector1 = v;
    //         std::vector<int> testVector2 = v;
    //         std::vector<int> testVector3 = v;
    //         std::vector<int> testVector4 = v;
    //         std::vector<int> testVector5 = v;

    //         bubbleSort(testVector1);
    //         insertSort(testVector2);
    //         selectSort(testVector3);
    //         mergeSort(testVector4);
    //         systemSort(testVector5);

    //         if (testVector1 == testVector2 &&
    //             testVector2 == testVector3 &&
    //             testVector3 == testVector4 &&
    //             testVector4 == testVector5
    //             )
    //         {
    // #ifdef DEBUG
    //             std::cout << "Time " << TESTTIME - testTime << " OK" << std::endl;
    // #endif
    //         }
    //         else
    //         {
    //             std::cout << "Time " << TESTTIME - testTime << " NG" << std::endl;
    //             success = false;
    //             break;
    //         }
    //     }
    //     std::cout << "=================================" << std::endl;
    //     std::cout << TESTTIME - testTime - 1 <<"/"<< TESTTIME << " rounds sort test complete" << std::endl;
    //     std::cout << (success ? "Everything is Okay" : "Opps,NG") << std::endl;
    //     std::cout << "=================================" << std::endl;
    return 0;
}
