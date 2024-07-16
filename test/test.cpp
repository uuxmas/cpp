#include "utils.h"
#include "sort.h"
#include "leetcode.h"
#include "class.h"
#include <queue>

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

    const int EPOCH = 10;   // 权重其次大，取代宏定义会好一些
    const int MAXSIZE = 10; // 权重最大
    const int MAXVALUE = 100;

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
        std::vector<int> testVector8 = v;
        std::vector<int> testVector9 = v;

        bubbleSort(testVector1);
        insertSort(testVector2);
        selectSort(testVector3);
        mergeSort(testVector4);
        systemSort(testVector5);
        quickSort(testVector6);
        radixSort(testVector7);
        bigRootHeapSort(testVector8);
        smallRootHeapSort(testVector9);

        if (testVector1 == testVector2 &&
            testVector2 == testVector3 &&
            testVector3 == testVector4 &&
            testVector4 == testVector5 &&
            testVector5 == testVector6 &&
            testVector6 == testVector7 &&
            testVector7 == testVector8 &&
            testVector8 == testVector9)
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

bool compareLess(const int &a, const int &b) // 防止篡改，防止拷贝占用时间，所以常引用
{
    return a < b; // 返回true，则返回第一个参数，是a，此时a是小，所以从小到大排序
}

bool compareGreater(const int &a, const int &b) // 防止篡改，防止拷贝占用时间，所以常引用
{
    return a > b; // 返回true，则返回第一个参数，是a，此时a是大，所以是从大到小排序
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

    std::vector<int> vec7{2, 0, 2, 1, 1, 0};
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

    std::vector<int> vec8{17, 27, 25, 20, 26};
    sortArrDistanceLessK(vec8, 2);

    std::sort(vec8.begin(), vec8.end(), compareLess);
    std::cout << "比较器的使用，返回为真，则第一个参数先出来" << std::endl;

    std::vector<int> vec9{2, 4, 3, 4};
    std::vector<int> res = twoSum_1(vec9, 8);
    if (!res.empty()) // 不然会有段错误
    {
        std::cout << res[0] << " " << res[1] << "\n";
    }

    orderedTwoListsSameElements();

    LinkList myList;
    myList.InsertBackData(1);
    myList.InsertBackData(3);
    // myList.InsertBackData(8);
    // myList.InsertBackData(8);
    myList.InsertBackData(3);
    myList.InsertBackData(1);
    bool flag = isPalindromeII(myList);
    std::cout << "\n\n\n"
              << (flag == true ? "Palindrome true" : "Palindrome false") << "\n";
    std::cout << "\n";

    myList.PrintList();
    //myList.ReverseListIII();
    //myList.PrintList();
    std::cout << "\n";
}

void testCPP_constExpression()
{
    // 符号常量表,define和const修饰的叫做符号常量
    // initialized with a constant expression
    const int a = 10;   // a为常量，性质为常量的const值，值与内存无关，值存在符号常量表里，编译阶段不去内存中寻址取值
    int *p = (int *)&a; // 取地址时，会分配一个内存地址，然后给p

    *p = 100;

    std::cout << "符号常量与内存地址是两个不同的地方，此时打印的是符号常量 " << a << std::endl;
    std::cout << "符号常量与内存地址是两个不同的地方，此时打印的是内存地址 " << *p << std::endl;

    int b = 80;
    // not initialized with a constant expression
    // 如果以普通变量初始化const修饰的变量 会立即开辟空间，不会有符号常量表的出现了
    const int c = b; // c为常变量，性质为常变量的const量，值与内存相关联，编译阶段需要去内存中寻址取值
    int *p6 = (int *)&c;

    *p6 = 90;

    std::cout << "性质为常变量，与内存相关联， " << c << std::endl;
    std::cout << "性质为常变量，与内存相关联， " << *p6 << std::endl;

    int m = 50;
    std::cout << "size of int " << sizeof(m) << std::endl;

    int *p1 = &m;
    std::cout << "size of int * " << sizeof(p1) << std::endl;

    int *p2 = new int[100];
    std::cout << "size of int * " << sizeof(p2) << std::endl;

    char k = 'B';
    std::cout << "size of char " << sizeof(k) << std::endl;

    char *p3 = &k;
    std::cout << "size of char * " << sizeof(p3) << std::endl;
    std::cout << "content * " << *p3 << std::endl;

    char *p4 = new char[20]{1, 2, 3, 4, 5, 6};
    std::cout << "size of char * " << sizeof(p4) << std::endl;

    double *p5 = new double[20]{1.0, 2.23, 3, 4, 5, 6};
    std::cout << "size of double * " << sizeof(p5) << std::endl;

    delete[] p2;
    delete[] p4;
    p2 = nullptr;
    p4 = nullptr;
    p5 = nullptr;
}

void testCPP_class()
{
    // 常引用
    // int b = 20;

    // // 常指针
    // int a = 10;
    // const int *p1 = &a;
    // // int *p2 = p1;//这里会报错
    // int *p2 = const_cast<int *>(p1); // 强制转换成非 常指针
    Hero h1;
    Hero h2("nihao", 4, 11, 23);

    std::cout << "h1 id " << h1.getId() << std::endl;
    std::cout << "h1 name " << h1.getName() << std::endl;
    std::cout << "h2 energy " << h2.getEnergy() << std::endl;
    std::cout << "h2 name " << h2.getName() << std::endl;

    MyArray<int> array1;
    array1.push(1);
    array1.push(2);
    array1.push(3);
    array1.push(4);
    array1.push(5);

    for (int i = 0; i < array1.getSize(); i++)
    {
        try
        {
            std::cout << array1[i] << std::endl;
        }
        catch (const char *e)
        {
            std::cerr << e << '\n';
        }
    }

    try
    {
        array1[5] = 1000; // 越界会产生段错误
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    array1[0] = 2000;

    std::cout << array1[0] << std::endl;

    MyArray<char> array2;
    array2.push('A');
    array2.push('B');
    array2.push('C');
    array2.push('D');
    array2.push('E');
    // array2.push('F');

    for (int i = 0; i < array2.getSize(); i++)
    {
        std::cout << array2[i] << std::endl;
    }

    // array2[5] = 'G'; 越界会产生段错误
    array2[0] = 'Z';

    std::cout << array2[0] << std::endl;

    MyArray<Hero> array3;
    array3.push(Hero("you1", 1, 101, 51));
    array3.push(Hero("you2", 2, 102, 52));
    array3.push(Hero("you3", 3, 103, 53));
    array3.push(Hero("you4", 4, 104, 54));
    array3.push(Hero("you5", 5, 105, 55));

    for (int i = 0; i < array3.getSize(); i++)
    {
        std::cout << array3[i] << std::endl;
    }

    std::cout << array3[0] << " " << array3[1] << " " << array3[2] << std::endl;

    // array3[0] = Hero("me", 888, 88, 8888);

    // std::cout << array3[0] << std::endl;

    // int *p = nullptr;
    // *p = 10;
    // std::cout << *p <<std::endl;

    LinkList myList;

    myList.InsertFrontData(1);
    myList.InsertFrontData(2);
    // myList.InsertFrontData(3);
    // myList.InsertFrontData(4);
    // myList.InsertFrontData(5);
    // myList.InsertFrontData(6);

    myList.PrintList();

    // myList.ReverseListI();
    // myList.ReverseListII();
    // myList.PrintList();

    // myList.DeleteBack();
    // myList.DeleteBack();
    // myList.DeleteBack();
    // myList.DeleteBack();
    // myList.DeleteBack();
    // myList.DeleteFront();
    // myList.DeleteFront();
    // myList.DeleteFront();
    // myList.DeleteFront();
    // myList.DeleteFront();
    // myList.DeleteFront();
    myList.DeleteData(1);

    myList.PrintList();

    std::cout << "end" << std::endl;
}

int main()
{
    testUtils();
    testSort();
    testLeetcode();
    testCPP_class();

    // system("pause");linux没有pause命令
    return 0;
}