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

    const int EPOCH = 100;   // 权重其次大，取代宏定义会好一些
    const int MAXSIZE = 100; // 权重最大
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

    std::vector<int> vec9{2, 4, 3, 7};
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
    myList.InsertBackData(2);
    myList.InsertBackData(7);
    myList.InsertBackData(9);
    myList.InsertBackData(5);
    myList.InsertBackData(4);
    bool flag = isPalindromeII(myList);
    std::cout << "\n\n\n"
              << (flag == true ? "Palindrome true" : "Palindrome false") << "\n";
    std::cout << "\n";

    myList.PrintList();
    // myList.ReverseListIII();
    // myList.PrintList();
    std::cout << "\n";

    LinkList hisList;
    hisList.InsertBackData(9);
    hisList.InsertBackData(3);
    // hisList.InsertBackData(12);
    // hisList.InsertBackData(2);
    hisList.InsertBackData(5);

    // partitionList(hisList, 3);
    //  hisList.PrintList();
    //  std::cout << "\n";

    // partitionListII(hisList, 1);

    // hisList.PrintList();
    // std::cout << "\n";

    // Node *p = copyListWithRandNode(hisList);
    // std::cout << "\n";

    intersectLists(myList, hisList);

    // TNode *p = lowestCommonAncestor();
    // std::cout << "common ancestor node: " << p << " " << p->data << "\n";

    paperFold(3);

    std::cout << "\n";
    std::cout << "\n";

    meetingsArrage();

    stringSort();

    int a = lessMoneySplit();
    std::cout << "less money split(haffoman code problem): " << a << "\n";

    a = maxCapitalised();
    std::cout << "max capital: " << a << "\n";

    findMediumNumber();
    const int N = 8; // N=16, NQueenBits == 14.6629s
    // NQueen(N);
    NQueenII(N);
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
    myList.InsertFrontData(3);
    myList.InsertFrontData(4);
    myList.InsertFrontData(5);
    myList.InsertFrontData(6);

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

    myList.findData(2);
    myList.findData(6);

    std::cout << "\n";

    Tree myTree;

    // TNode *p1 = new TNode(46);
    // TNode *p2 = new TNode(20);
    // TNode *p3 = new TNode(50);
    // TNode *p4 = new TNode(45);
    // TNode *p5 = new TNode(55);
    // TNode *p6 = new TNode(6);
    // TNode *p7 = new TNode(8);
    for (int i = 1; i <= 31; i++)
    {
        myTree.TreeAddData(i * 10);
    }

    myTree.TreePrint();
    // myTree.PreUnRecur();
    // myTree.PreRecursive();
    // myTree.InUnRecur();
    // myTree.InRecursive();
    // myTree.PostUnRecur();
    // myTree.PostRecursive();

    std::cout << "\n";

    myTree.levelOrder();

    std::cout << "\n";

    std::cout << "tree max width: " << myTree.getTreeWidth() << std::endl;

    std::cout << "\n";

    bool isFlag = myTree.isBinarySearchTreeI();
    std::cout << "is binary search tree I: " << isFlag << "\n";
    isFlag = myTree.isBinarySearchTreeII();
    std::cout << "is binary search tree II: " << isFlag << "\n";

    isFlag = myTree.isCompletedBinaryTree();
    std::cout << "is completed binary tree: " << isFlag << "\n";

    isFlag = myTree.isBalanceBinaryTree();
    std::cout << "is balanced binary tree: " << isFlag << "\n";

    // std::cout <<"std::min: " <<std::min(std::min(10,2),3) <<"\n";
    // std::cout <<"std::min: " <<std::min({10,3,2},[](int a, int b){return a<b;})<< "\n";
    isFlag = myTree.isBinarySearchTreeIII();
    std::cout << "is binary search tree: " << isFlag << "\n";

    isFlag = myTree.isFullBinaryTree();
    std::cout << "is full binary tree: " << isFlag << "\n";

    std::cout << "find address of node data = 0 :" << myTree.findTreeNode(0) << "\n";

    TNode *node1 = myTree.findTreeNode(190);
    TNode *node2 = myTree.findTreeNode(40);

    // 没有换行符的话，控制台是不会输出打印内容的，直到遇到\n换行符！！！！！
    std::cout << "find address of 3 nodes: " << "\n";

    TNode *res1 = lowestCommonAncestor(myTree.getRoot(), node1, node2);
    std::cout << res1 << "  " << "  " << node1 << "  " << node2 << "\n";

    TNode *res2 = lowestCommonAncestorII(myTree.getRoot(), node1, node2);
    std::cout << res2 << "  " << "  " << node1 << "  " << node2 << "\n";

    // 带有父节点的树
    Tree2 myTree2;

    for (int i = 1; i <= 31; i++)
    {
        myTree2.addData(i * 10);
    }

    myTree2.printTree();

    TNode2 *node3 = myTree2.getSuccessor(myTree2.findTreeNode2(170));

    std::cout << "get successor node, address: " << node3 << " value: " << (node3 == nullptr ? 0 : node3->data) << "\n";

    std::string strTree = myTree2.serialTree2();

    std::cout << "serial tree nodes: \n"
              << strTree << "\n";

    Tree2 myTree3(strTree);

    myTree3.printTree();

    const int ROWS = 5;
    int matrix[ROWS][3] = {
        // {2, 1, 3},
        // {2, 7, 6},
        // {1, 5, 9},
        // {7, 5, 12},
        // {5, 3, 100},//顶点不会重复存储在图中，但是线会有重复的顶点组成的新线
        // {7,8,300},
        {1, 2, 5},
        {2, 3, 5},
        {3, 4, 5},
        {2, 4, 5},
        {1, 3, 5},

    };

    DirectedGraph myGraph;
    myGraph.addVertexEdge(matrix, ROWS);

    myGraph.breadthFirstSearch(myGraph.findVertex(2));
    myGraph.depthFirstSearch(myGraph.findVertex(2));
    myGraph.topologySort();

    UndirectedGraph<int> myUnGraph(10);
    // myUnGraph.addEdge(0, 1, 10);
    // myUnGraph.addEdge(0, 4, 20);
    // myUnGraph.addEdge(1, 2, 30);
    // myUnGraph.addEdge(1, 3, 40);
    // myUnGraph.addEdge(1, 4, 50);
    // myUnGraph.addEdge(2, 3, 60);
    // myUnGraph.addEdge(3, 4, 70);

    // myUnGraph.addEdge(1, 2, 3);
    // myUnGraph.addEdge(2, 3, 5);
    // myUnGraph.addEdge(3, 4, 2);
    // myUnGraph.addEdge(4, 5, 7);
    // myUnGraph.addEdge(5, 1, 1);
    // myUnGraph.addEdge(2, 5, 4);
    // myUnGraph.addEdge(3, 5, 6);

    myUnGraph.addEdge(1, 2, 3);
    myUnGraph.addEdge(1, 6, 9);
    myUnGraph.addEdge(1, 3, 6);
    myUnGraph.addEdge(2, 1, 3);
    myUnGraph.addEdge(2, 3, 4);
    myUnGraph.addEdge(2, 4, 2);
    myUnGraph.addEdge(2, 5, 9);
    myUnGraph.addEdge(2, 6, 9);
    myUnGraph.addEdge(3, 7, 9);
    myUnGraph.addEdge(3, 4, 2);
    myUnGraph.addEdge(3, 2, 4);
    myUnGraph.addEdge(3, 1, 6);
    myUnGraph.addEdge(4, 3, 2);
    myUnGraph.addEdge(4, 7, 9);
    myUnGraph.addEdge(4, 5, 8);
    myUnGraph.addEdge(4, 2, 2);
    myUnGraph.addEdge(5, 6, 8);
    myUnGraph.addEdge(5, 2, 9);
    myUnGraph.addEdge(5, 4, 8);
    myUnGraph.addEdge(5, 7, 7);
    myUnGraph.addEdge(5, 9, 9);
    myUnGraph.addEdge(5, 10, 10);
    myUnGraph.addEdge(6, 1, 9);
    myUnGraph.addEdge(6, 2, 9);
    myUnGraph.addEdge(6, 5, 8);
    myUnGraph.addEdge(6, 10, 18);
    myUnGraph.addEdge(7, 3, 9);
    myUnGraph.addEdge(7, 4, 9);
    myUnGraph.addEdge(7, 5, 7);
    myUnGraph.addEdge(7, 9, 5);
    myUnGraph.addEdge(7, 8, 4);
    myUnGraph.addEdge(8, 7, 4);
    myUnGraph.addEdge(8, 9, 1);
    myUnGraph.addEdge(8, 10, 4);
    myUnGraph.addEdge(9, 8, 1);
    myUnGraph.addEdge(9, 7, 5);
    myUnGraph.addEdge(9, 5, 9);
    myUnGraph.addEdge(9, 10, 3);
    myUnGraph.addEdge(10, 8, 4);
    myUnGraph.addEdge(10, 9, 3);
    myUnGraph.addEdge(10, 5, 10);
    myUnGraph.addEdge(10, 6, 18);

    myUnGraph.BFSTraversal(4);

    std::cout << "\n";
    myUnGraph.printGraphBST(4);
    std::cout << "\n";
    myUnGraph.printDotFormatBST(8);
    std::cout << "\n";

    myUnGraph.DFSTraversal(8);
    std::cout << "\n";

    myUnGraph.Kruskal();
    std::cout << "\n";

    // C++中模板类和模板成员函数不能分开写，否则编译时无法找到对应文件，应该声明和定义全写在头文件h中，就像STL也是如此
    // 踩过好几次坑了，这问题
    UndirectedGraph<char> myGraph2(3);
    myGraph2.addEdge('A', 'B', 1);
    myGraph2.addEdge('A', 'C', 1);
    myGraph2.addEdge('B', 'C', 3);
    myGraph2.addEdge('A', 'D', 2);
    myGraph2.printDotFormatBST('A');
    myGraph2.Kruskal();
    myGraph2.Prim('A');

    // https://www.cnblogs.com/biyeymyhjob/archive/2012/07/30/2615542.html
    UndirectedGraph<char> myGraph3(7);
    myGraph3.addEdge('A', 'B', 7);
    myGraph3.addEdge('A', 'D', 5);
    myGraph3.addEdge('B', 'A', 7);
    myGraph3.addEdge('B', 'D', 9);
    myGraph3.addEdge('B', 'C', 8);
    myGraph3.addEdge('B', 'E', 7);
    myGraph3.addEdge('C', 'B', 8);
    myGraph3.addEdge('C', 'E', 5);
    myGraph3.addEdge('D', 'A', 5);
    myGraph3.addEdge('D', 'B', 9);
    myGraph3.addEdge('D', 'E', 15);
    myGraph3.addEdge('D', 'F', 6);
    myGraph3.addEdge('E', 'C', 5);
    myGraph3.addEdge('E', 'B', 7);
    myGraph3.addEdge('E', 'D', 15);
    myGraph3.addEdge('E', 'F', 8);
    myGraph3.addEdge('E', 'G', 9);
    myGraph3.addEdge('F', 'D', 6);
    myGraph3.addEdge('F', 'E', 8);
    myGraph3.addEdge('F', 'G', 11);
    myGraph3.addEdge('G', 'F', 11);
    myGraph3.addEdge('G', 'E', 9);

    myGraph3.Kruskal();
    myGraph3.Prim('A');
    myGraph3.printDotFormatBST('A');

    myGraph3.Dijkstra('A');

    UndirectedGraph<int> myGraph4(8);
    // myGraph4.addEdge(1,2,4);
    // myGraph4.addEdge(1,6,6);
    // myGraph4.addEdge(4,6,5);
    // myGraph4.addEdge(6,7,6);
    // myGraph4.addEdge(5,7,5);
    // myGraph4.addEdge(3,7,9);
    myGraph4.addEdge(0, 2, 7);
    myGraph4.addEdge(0, 3, 6);
    myGraph4.addEdge(0, 4, 2);
    myGraph4.addEdge(1, 3, 8);
    myGraph4.addEdge(1, 6, 9);
    myGraph4.addEdge(2, 0, 7);
    myGraph4.addEdge(2, 6, 9);
    myGraph4.addEdge(3, 0, 6);
    myGraph4.addEdge(3, 1, 8);
    myGraph4.addEdge(3, 5, 1);
    myGraph4.addEdge(4, 0, 2);
    myGraph4.addEdge(4, 6, 9);
    myGraph4.addEdge(4, 7, 7);
    myGraph4.addEdge(5, 3, 1);
    myGraph4.addEdge(5, 6, 5);
    myGraph4.addEdge(6, 4, 9);
    myGraph4.addEdge(6, 2, 9);
    myGraph4.addEdge(6, 1, 9);
    myGraph4.addEdge(6, 5, 5);
    myGraph4.addEdge(6, 7, 3);
    myGraph4.addEdge(7, 6, 3);
    myGraph4.addEdge(7, 4, 7);
    myGraph4.printDotFormatBST(0);
    myGraph4.Dijkstra(0);

    std::cout << "\n";

    Trie trieTree;
    // bool res;
    trieTree.insert("apple"); //

    // res = trieTree.search("apple"); // true
    // std::cout << "res" << res << "\n";

    // res = trieTree.search("app"); // false
    // std::cout << "res" << res << "\n";

    // res = trieTree.prefix("app"); // true
    // std::cout << "res" << res << "\n";

    trieTree.insert("app"); //

    // res = trieTree.search("app"); // true
    // std::cout << "res" << res << "\n";

    trieTree.deleteWord("apple");
    // trieTree.deleteWord("app");

    // trieTree.insert("lead");
    // res = trieTree.search("lead"); // true

    // res = trieTree.search("apple"); // false or true
    // std::cout << "res" << res << "\n";

    // trieTree.deleteWord("lead");

    std::cout << "\n";
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