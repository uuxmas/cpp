#include "utils.h"
#include "sort.h"
#include "leetcode.h"

#define EPOCH 10000   // 权重其次大
#define MAXSIZE 1000 // 权重最大
#define MAXVALUE 100

void testUtils()
{
    std::vector<int> vec{2, 8, 9, 5, 6, 3, 4, 7, 1};
    int max = maxRecursive(vec, 0, vec.size() - 1);
    std::cout << "===============utils test in progress...=================" << std::endl;
    std::cout << "max = " << max << std::endl;
    std::cout << "=========================================================" << std::endl
              << std::endl;
}

void testSort()
{
    int testTime = EPOCH;
    bool success = true;

    std::cout << "===============sort test in progress...==================" << std::endl;

    while (testTime--)
    {
        std::vector<int> v;
        randomVector(MAXSIZE, MAXVALUE, v);

        std::vector<int> testVector1 = v;
        std::vector<int> testVector2 = v;
        std::vector<int> testVector3 = v;
        std::vector<int> testVector4 = v;
        std::vector<int> testVector5 = v;
        std::vector<int> testVector6 = v;
        std::vector<int> testVector7 = v;

        bubbleSort(testVector1);
        insertSort(testVector2);
        selectSort(testVector3);
        mergeSort(testVector4);
        systemSort(testVector5);
        quickSort(testVector6);
        radixSort(testVector7);

        if (testVector1 == testVector2 &&
            testVector2 == testVector3 &&
            testVector3 == testVector4 &&
            testVector4 == testVector5 &&
            testVector5 == testVector6 &&
            testVector6 == testVector7
            )
        {
#ifdef DEBUG
            std::cout << "Time " << EPOCH - testTime << " OK" << std::endl;
#endif
        }
        else
        {
            std::cout << "Time " << EPOCH - testTime << " NG" << std::endl;
            success = false;
            break;
        }
    }

    std::cout << EPOCH - testTime - 1 << "/" << EPOCH << " rounds sort test complete" << std::endl;
    std::cout << (success ? "Everything is Okay" : "Opps,NG") << std::endl;
    std::cout << "=========================================================" << std::endl
              << std::endl;
}

void testLeetcode()
{
    std::cout << "=============leetcode test in progress...================" << std::endl;

    // 有一个数字是唯一的，其他数字都是偶数个数，139
    std::vector<int> vec1{80, 285, 80, 70, 139, 285, 70};
    int n1 = singleNumber_136(vec1);
    std::cout << "n1 = " << n1 << std::endl;

    // 有一个数字是唯一的，其他数字都是k个数（k=3....），91
    std::vector<int> vec2{180, 90, 180, 91, 34, 90, 90, 34, 180, 34};
    int n2 = singleNumberII_137(vec2);
    std::cout << "n2 = " << n2 << std::endl;
    std::cout << "=========================================================" << std::endl;

    // 有两个唯一的数字，其他数字都是偶数个数，80，41
    std::vector<int> vec3{76, 12, 80, 12, 41, 76, 76, 6, 76, 6};
    std::vector<int> v = twoNumbers(vec3);
    std::cout << "v0 = " << v[0] << std::endl;
    std::cout << "v1 = " << v[1] << std::endl;
    std::cout << "=========================================================" << std::endl;

    // std::vector<int> vec4{1,1,1,1,1,1,1,1};
    // int target = 11;
    //  std::vector<int> vec4{2,3,1,2,4,3};
    //  int target = 7;
    // std::vector<int> vec4{1, 4, 4};
    // int target = 4;
    std::vector<int> vec4{12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    int target = 213;
    int min = minimumSizeSubarraySum_209(vec4, target);
    std::cout << "min = " << min << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::vector<int> vec5{1, 3, 4, 2, 5};
    int smallSum = smallSum_main(vec5);
    std::cout << "small sum = " << smallSum << std::endl;
    std::cout << "=========================================================" << std::endl;

    // std::vector<int> vec6{7, 5, 6, 4}; // 5
    std::vector<int> vec6{9, 7, 5, 4, 6}; // 8
    int reversePair = reversePair_main(vec6);
    std::cout << "reverse pairs = " << reversePair << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::vector<int> vec7{2,0,2,1,1,0};
    int r = vec7.size();
    int num = 2;
    dutchFlagI(vec7, 0, r - 1, num);
    std::cout << "Dutch flag problem: ";
    for (auto &item : vec7)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << "=========================================================" << std::endl
              << std::endl;

}

int main()
{
    testUtils();
    testSort();
    testLeetcode();
    // system("pause");linux没有pause命令
    return 0;
}