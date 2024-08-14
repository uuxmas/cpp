#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include "utils.h"

class Hero
{
    friend std::ostream &operator<<(std::ostream &out, Hero &obj);

public:
    Hero();
    Hero(std::string name, int id, int energy, int attack);

    std::string getName();
    int getId();
    int getEnergy();
    int getAttack();

private:
    std::string name;
    int id;
    int energy;
    int attack;
};

template <class T>
class MyArray
{
public:
    MyArray()
    {
        capacity = 5;
        size = 0;
        p = new T[capacity];
        memset((void *)p, 0, sizeof(T) * capacity);
        std::cout << "constructor without parameter" << std::endl;
    }

    MyArray(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        p = new T[capacity];
        memset((void *)p, 0, sizeof(T) * capacity);
        std::cout << "constructor with parameter" << std::endl;
    }

    MyArray(const MyArray &obj)
    {
        this->capacity = obj.capacity;
        this->size = obj.size;
        this->p = new T[obj.capacity];
        memcpy(this->p, obj.p, sizeof(T) * obj.capacity);
        std::cout << "copy constructor" << std::endl;
    }

    ~MyArray()
    {
        if (p != nullptr)
        {
            delete[] p;
            p = nullptr;
        }
        std::cout << "destructor" << std::endl;
    }

    int getCapacity(void)
    {
        return capacity;
    }

    int getSize(void)
    {
        return size;
    }

    void push(T element)
    {
        if (size < capacity)
        {
            p[size++] = element;
        }
        else
        {
            std::cout << "already full" << std::endl;
        }
    }

    void pop()
    {
        if (size > 0)
        {
            size--;
        }
        else
        {
            std::cout << "already empty" << std::endl;
        }
    }

    // 重载[]运算符，返回一个引用，需要对其赋值
    T &operator[](int i)
    {
        if (i >= 0 && i < capacity)
        {
            return p[i];
        }
        else
        {
            // 因为这里是异常，所以没有返回可行的数组，但是还必须有返回，不然编译器总是报警告
            // control reaches end of non-void function
            // 所以通过抛出异常，避免编译警告的发生
            throw "illegal index!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        }
    }

private:
    T *p;
    int size;
    int capacity;
};

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data);
};

class LinkList
{
private:
    Node *head;
    Node *tail;
    Node *ReverseRecursivelyList(Node *&head);
    Node *ReverseIterateList(Node *&head);

public:
    LinkList();
    void InsertFrontData(int data);
    void PrintList();
    void InsertBackData(int data);
    void ReverseListI();
    void ReverseListII();
    void ReverseListIII();
    Node *getHead();
    void setHead(Node *&head);
    void DeleteFront();
    void DeleteBack();
    void DeleteData(int data);
    int findData(int data);
    void loopifyList(int index);
};

// 二叉树的节点定义,public定义成该类型，单链表也是，都需要定义成public类型
class TNode
{
public:
    int data;
    TNode *left;
    TNode *right;

public:
    TNode(int data);
};

class TNode2
{
public:
    int data;

    TNode2 *p;
    TNode2 *l;
    TNode2 *r;

public:
    TNode2(int data) : data(data), p(nullptr), l(nullptr), r(nullptr) {}
};

class Tree2
{
private:
    TNode2 *root;
    std::string getSpace(int num);
    TNode2 *getLeftMost(TNode2 *node);
    void printInorder(TNode2 *node, int height, std::string to, int len);
    std::string serialTree2ByPreOrder(TNode2 *node);
    void split(const std::string &s, std::queue<std::string> &tokens, const std::string &delimiters = "_"); // 又是一个坑，缺省值在头文件中写好，定义中只声明不写缺省值
    TNode2 *reconSerialTree2ByPreOrder(std::queue<std::string> &tokens);

public:
    Tree2() : root(nullptr) {}
    Tree2(const std::string &serialStr); // 反序列化构造一个树
    void addData(int data);
    TNode2 *getSuccessor(TNode2 *node);
    void printTree();
    TNode2 *findTreeNode2(int data);
    std::string serialTree2();
    TNode2 *getRoot();
};

class Tree
{
private:
    TNode *root;

private:
    void TreePreOrderTraversalRecur(TNode *&node);  // 前序遍历
    void TreeInOrderTraversalRecur(TNode *&node);   // 中序遍历
    void TreePostOrderTraversalRecur(TNode *&node); // 后序遍历

    void TreePreOrderTraversalUnRecur(TNode *&node);  // 前序非递归遍历
    void TreeInOrderTraversalUnRecur(TNode *&node);   // 中序非递归遍历
    void TreePostOrderTraversalUnRecur(TNode *&node); // 后序非递归遍历

    std::string getSpace(int num);
    void printInOrder(TNode *&node, int height, std::string to, int len);
    bool isBSTRecur(TNode *&node, int *&preValue);
    std::vector<int> isBSTRecurIII(TNode *&node);
    bool isBSTIterator(TNode *&node);
    std::pair<bool, int> isBBTRecur(TNode *&node);
    std::pair<int, int> isFBTRecur(TNode *&node);

public:
    Tree();                     // tree的无参构造
    void TreePrint();           // 打印tree
    void TreeAddData(int data); // 添加数据到叶子上
    void PreRecursive();
    void PreUnRecur();  // 前序非递归
    void InUnRecur();   // 中序非递归
    void PostUnRecur(); // 后序非递归
    void InRecursive();
    void PostRecursive();
    void levelOrder();
    TNode *getRoot();
    TNode *findTreeNode(int data);
    void setRoot(TNode *&node);
    int getTreeWidth();
    bool isBinarySearchTreeI();
    bool isBinarySearchTreeII();
    bool isBinarySearchTreeIII();
    bool isCompletedBinaryTree();
    bool isBalanceBinaryTree();
    bool isFullBinaryTree();
};

/**
 * 图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图
 */

class Edge; // 前向引用声明，两个类相互依赖，循环引用，但不能定义出对象，Vertex类中定义一个Edge对象，会出错

class Vertex
{
public:
    int value;
    int in;                         // 指向自己的边的数量indegree
    int out;                        // 从自己发出的边的数量outdegree
    std::vector<Vertex *> vertices; // 从自己发出的边所指向的顶点的集合数组
    std::vector<Edge *> edges;      // 从自己发出的边的集合数组

public:
    Vertex(int v) : value(v), in(0), out(0), vertices{}, edges{} {}
};

class Edge
{
public:
    int weight;         // 边的权重
    Vertex *vertexFrom; // 边的起点
    Vertex *vertexTo;   // 边的终点

public:
    Edge(int w, Vertex *vF, Vertex *vT) : weight(w), vertexFrom(vF), vertexTo(vT) {}
};

class DirectedGraph
{
public:
    std::unordered_map<int, Vertex *> mapVertices; // 哈希表，存放图中所有的顶点值与定点的键值对
    std::unordered_set<Edge *> setEdges;           // 哈希表，存放图中所有的边

public:
    DirectedGraph() : mapVertices{}, setEdges{} {}
    void addVertexEdge(const int matrix[][3], const int rows);
    Vertex *findVertex(int value);
    void breadthFirstSearch(Vertex *v);
    void depthFirstSearch(Vertex *v);
    void topologySort();
};

template <class T>
class UndirectedGraph
{
public:
    UndirectedGraph(int vertices);

    void addEdge(T v1, T v2, int weight);
    void printGraphBST(T startVertex);
    void printDotFormatBST(T startVertex);
    void BFSTraversal(T startVertex);
    void DFSTraversal(T startVertex);
    void Kruskal();
    void Prim(T startVertex);
    void Dijkstra(T startVertex);

private:
    std::pair<T, int> findMinDistanceVertexForDijkstra(std::unordered_map<T, int> &map, std::unordered_set<T> &set);

public:
    struct Edge
    {
        T v1;
        T v2;
        int weight;
    };
    struct myCompare
    {
        bool operator()(const Edge &e1, const Edge &e2) const;
    };
    struct myHash
    {
        std::size_t operator()(const std::pair<T, std::pair<T, int>> &p) const;
    };
    struct myEqual
    {
        bool operator()(const std::pair<T, std::pair<T, int>> &p1, const std::pair<T, std::pair<T, int>> &p2) const;
    };

private:
    int vertices;                                                // 无向图中顶点数量
    std::unordered_map<T, std::list<std::pair<T, int>>> adjList; // 邻接表由哈希表构成，key：某个顶点，value：一个链表，链表中的每个元素是一个pair<邻接点和权重>
    std::priority_queue<Edge, std::vector<Edge>, myCompare> edgeQueue;
};

// 无向图的实例化，有参构造，输入顶点个数
template <class T>
UndirectedGraph<T>::UndirectedGraph(int vertices)
{
    this->vertices = vertices;
}

template <class T>
void UndirectedGraph<T>::addEdge(T v1, T v2, int weight)
{
    // adjList[v1].push_back(std::make_pair(v2, weight));
    // adjList[v2].push_back(std::make_pair(v1, weight));
    adjList[v1].push_back({v2, weight});
    adjList[v2].push_back({v1, weight});
    Edge e = {v1, v2, weight};
    edgeQueue.push(e);
}

template <class T>
void UndirectedGraph<T>::printGraphBST(T startVertex)
{
    std::queue<T> q;
    std::unordered_set<T> visited;
    q.push(startVertex);
    visited.insert(startVertex);

    std::cout << "Print start from vertex: " << startVertex << "\n"; // 开始遍历的点
    while (!q.empty())
    {
        T cur = q.front();
        q.pop();

        for (const auto &item : adjList[cur]) // 遍历邻接表
        {
            // 顶点对应的链表，遍历链表中所有元素，每个元素是个pair<int,int>
            std::cout << cur << "--" << item.first << " [lable =  " << item.second << "];\n";
            if (visited.find(item.first) == visited.end()) // 访问过的节点，说明已经处理过了，没访问过的节点，才能入队列，不然则进入死循环
            {
                q.push(item.first);
                visited.insert(item.first);
            }
        }
    }
}

/**
 * unordered_set的第一个参数如果是常规数据类型，plain old data, POD类型，如int，string等，使用默认的unordered_set的类模板参数即可
 * 如需使用struct或者class或自定义数据类型结构作为unordered_set输入时，需重载类模板参数中的hash和operator ==
 * 即需要自定义哈希函数和比较器，用在自定义类型的unordered_set中
 * unordered_set类模板中规定，
 *
 */
// unordered_set 底层实现是哈希表，该容器的类模板定义如下：
// template < class Key,                    //容器中存储元素的类型
//            class Hash = hash<Key>,       //确定元素存储位置所用的哈希函数
//            class Pred = equal_to<Key>,   //判断各个元素是否相等所用的函数
//            class Alloc = allocator<Key>  //指定分配器对象的类型
//            > class unordered_set;

// 自定义一个pair的数据类型
// std::hash<int>是个类模板所派生的一个模板类，这个类重载了operator()运算符，所以这个模板类变成了仿函数（函数对象，该对象当成函数来用），用于返回hash值，const必须要加上
// 仿函数的调用方式：类名()(参数1，参数2....)，下面这个std::hash<int>就是类名，或者实例化对象，然后对象(参数1，参数2....)
// 函数对象（仿函数）是一个类，不是一个函数；函数对象（仿函数）通过重载operator()操作符，使得它像函数一样得到调用
// 如果一个类重载了operator()运算符，该operator()运算符要求传入一个参数，则这个类称为一元仿函数(unary functor)，
// 如果要求传入两个参数，该类称为二元仿函数(binary functor)
// 参考：https://blog.csdn.net/bandaoyu/article/details/106358830
// 参考：https://www.cnblogs.com/my_life/articles/7910166.html

// this指针指向当前的实例对象的地址，是一个常量指针，总是指向当前对象实例，但不能改变this的指向
// 常量成员函数
// 带const声明的函数,在该函数内,不能修改类的成员变量
// 成员函数的后面，加上const，this指针的类型会被改变为指向常量的指针，常量成员函数中，不能修改类的成员变量
// 新插入的值先计算哈希值，如果哈希值相等（哈希冲突），则调用相等比较，如果还一样，那就不是冲突，而是同样的值，所以不会插入，如果不一样则是哈希冲突，系统会处理冲突，然后insert成功
template <class T>
std::size_t UndirectedGraph<T>::myHash::operator()(const std::pair<T, std::pair<T, int>> &p) const
{
    int min = std::min(p.first, p.second.first);
    int max = std::max(p.first, p.second.first);

    return std::hash<int>()(min) ^ (std::hash<int>()(max) << 1); // std::hash<int>是一个通过类模板具体化的一个模板类，类模板中重载()运算符
}

template <class T>
bool UndirectedGraph<T>::myEqual::operator()(const std::pair<T, std::pair<T, int>> &p1, const std::pair<T, std::pair<T, int>> &p2) const
{
    if (p1.first == p2.first && p1.second.first == p2.second.first)
    {
        return true;
    }
    else if (p1.first == p2.second.first && p1.second.first == p2.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void UndirectedGraph<T>::printDotFormatBST(T startVertex)
{
    if (adjList.find(startVertex) == adjList.end())
    {
        return;
    }

    std::cout << "graph UndirectedGraph {\n"; // dot语法中，graph是无向图，digraph是有向图，后面的名字可以省略
    std::cout << "subgraph cluster {\n";      // 子图subgraph cluster才会有外框，如果有多个子图，则使用subgraph cluster_xxx区分，总之不能改成别的名字

    // std::cout << "label = \"Undirected Graph with Weight\";\n";
    std::cout << "label = \"无向图\";\n";
    std::cout << "fontcolor = red;\n";
    std::cout << "fontsize = 35;\n";
    std::cout << "labelloc = t;\n";
    std::cout << "bgcolor = beige;\n";
    std::cout << "style = dashed;\n"; // 外框的样式

    std::cout << "node [";
    std::cout << "shape = circle, ";
    std::cout << "fontname = Helvetia, ";
    std::cout << "fontcolor = \"#ffffff\", ";
    std::cout << "style = filled, ";
    std::cout << "color = red, ";
    std::cout << "fillcolor = \"#00334e\", "; // 5588a3,145374,00334e
    std::cout << "penwidth = 3,";
    std::cout << "];\n";

    std::cout << "edge [";
    std::cout << "color = green, ";
    std::cout << "fontname = Helvetia, ";
    std::cout << "fontcolor = \"#145374\", ";
    std::cout << "penwidth = 3,";
    std::cout << "];\n";

    std::queue<T> q;
    std::unordered_set<T> visited;
    std::unordered_set<std::pair<T, std::pair<T, int>>, myHash, myEqual> mySets;

    q.push(startVertex);
    visited.insert(startVertex);

    std::cout << "{rank = same; " << startVertex << ";}\n";

    while (!q.empty())
    {
        T cur = q.front();
        q.pop();

        std::cout << "{rank = same; ";

        for (const auto &item : adjList[cur])
        {
            mySets.insert({cur, item}); // 使用unordered_set的insert去重边，需要自己实现相等函数的运算符重载和哈希函数

            if (visited.find(item.first) == visited.end())
            {
                q.push(item.first);
                visited.insert(item.first);
                std::cout << item.first << ";";
            }
        }
        std::cout << "};\n";
    }

    for (auto &item : mySets)
    {
        std::cout << item.first << "--" << item.second.first << " [label = " << std::to_string(item.second.second) << "];\n";
    }

    std::cout << "}\n";
    std::cout << "}\n";
}

template <class T>
void UndirectedGraph<T>::BFSTraversal(T startVertex)
{
    if (adjList.find(startVertex) == adjList.end())
    {
        return;
    }

    std::queue<T> q;               // BFS队列
    std::unordered_set<T> visited; // 记录已访问的节点
    // std::vector<std::pair<int, int>> traversalEdges; // 记录遍历边

    q.push(startVertex);
    visited.insert(startVertex);
    std::cout << "BFS Traversal starting from vertex " << startVertex << ": \n";

    while (!q.empty())
    {
        T currentVertex = q.front();
        q.pop();
        std::cout << currentVertex << " ";

        // std::list<std::pair<int, int>> l = adjList.find(cur)->second;//找到该节点的邻接表

        for (const auto &item : adjList[currentVertex]) // 找到该节点的邻接表，并遍历每个元素
        {
            if (visited.find(item.first) == visited.end())
            {
                visited.insert(item.first);
                q.push(item.first);
                // traversalEdges.push_back(std::make_pair(currentVertex, item.first));
                // traversalEdges.push_back({currentVertex, item.first});
            }
        }
    }

    std::cout << "\n";
}

template <class T>
void UndirectedGraph<T>::DFSTraversal(T startVertex)
{
    if (adjList.find(startVertex) == adjList.end())
    {
        return;
    }

    std::stack<T> stack;
    std::unordered_set<T> visited;

    stack.push(startVertex);
    visited.insert(startVertex);
    std::cout << "Depth First Search starts from vertex: " << startVertex << "\n";
    std::cout << startVertex << " ";
    while (!stack.empty())
    {
        T cur = stack.top();
        stack.pop();

        for (const auto &item : adjList[cur]) // 该节点的邻接表进进行遍历
        {
            if (visited.find(item.first) == visited.end())
            {
                stack.push(cur);
                stack.push(item.first);
                visited.insert(item.first);
                std::cout << item.first << " ";
                break;
            }
        }
    }

    std::cout << "\n";
}

// struct默认是public，class默认是private
template <class T>
bool UndirectedGraph<T>::myCompare::operator()(const Edge &e1, const Edge &e2) const
{
    return e1.weight > e2.weight;
}

// 克鲁斯卡尔算法
// 数据结构：并查集
// 类别：最小权重生成树Minimum Weight Spanning Tree，简称最小生成树
// 按照边的权重顺序（从小到大）将边加入生成树中，但是若加入该边会与生成树形成环则不加入该边
// 直到树中含有 V − 1 条边为止。这些边组成的就是该图的最小生成树
// 克鲁斯卡尔算法的时间复杂度为 E*logE
template <class T>
void UndirectedGraph<T>::Kruskal()
{
    // 实例化一个边权重为优先级的小根堆，以便后续弹出时，先出来最小的，类的成员变量edgeQueue即是，故此处不用再搞

    std::priority_queue<Edge, std::vector<Edge>, myCompare> copyQueue(edgeQueue); // 拷贝构造

    // 加入各自的集合
    std::unordered_map<T, std::unordered_set<T>> mySets;
    std::cout << "Kruskal Minimum Spanning Tree...\n";

    for (const auto &item : adjList) // 所有顶点各自形成一个独立的集合，使用哈希表对应起来
    {
        std::unordered_set<T> s;
        s.insert(item.first);
        mySets[item.first] = s; // key:顶点，value:所属集合
    }

    while (!copyQueue.empty())
    {
        Edge e = copyQueue.top(); // 小根堆，弹出的元素就是最小的，得到权重最小的边
        copyQueue.pop();

        // 两个顶点是否在一个集合，查集
        if (mySets[e.v1] != mySets[e.v2])
        {
            // 不在一个集合中，处理打印最小的权重的边，对应的两个顶点，合并两个顶点各自对应的集合，一个集合中所有的元素都放到另外一个集合中，并将元素指向新的集合
            // std::cout << e.v1 << "--(" << e.weight << ")--" << e.v2 << "\n"; // 处理打印出来边，此边就是需要的边
            std::cout << e.v1 << "--" << e.v2 << "[label=" << e.weight << "];\n";
            // 并集
            for (const auto &i : mySets[e.v2])
            {
                mySets[e.v1].insert(i); // 源集合v2中所有的元素，都放入目的集合v1中
            }
            for (const auto &i : mySets[e.v1]) // 对新的集合v1，所有元素，重新更新目的集合v1，上面循环只是加入了，但是没有更新各自的目的集合
            {
                mySets[i] = mySets[e.v1]; // 让这个元素指向目的集合v1
            }
        }
    }
}

template <class T>
void UndirectedGraph<T>::Prim(T startVertex)
{
    if (adjList.find(startVertex) == adjList.end())
    {
        return;
    }

    std::priority_queue<Edge, std::vector<Edge>, myCompare> minEdges;

    std::unordered_set<T> visited;

    std::cout << "Prim Minimum Spanning Tree...\n";

    // 如果不是连通图，则需要for循环，遍历每一个节点，做出如下一整套的操作，森林
    // 如果是连通图，则直接使用给定的起始点开始做如下一整套的操作即可

    visited.insert(startVertex); // 起点放入已访问的节点集合中

    for (const auto &i : adjList[startVertex])
    {
        minEdges.push({startVertex, i.first, i.second}); // 起点对应的边，全部放入minEdges小根堆队列中
    }

    while (!minEdges.empty())
    {
        Edge curMinEdge = minEdges.top(); // 拿到当前权重最小的边
        minEdges.pop();

        if (visited.find(curMinEdge.v2) == visited.end()) // 边对应的小终点不在已访问的节点集合中，如果在，则重新再找一个小的边
        {
            // 打印处理正确的边
            // std::cout << curMinEdge.v1 << "--<" << curMinEdge.weight << ">--" << curMinEdge.v2 << "\n";
            std::cout << curMinEdge.v1 << "--" << curMinEdge.v2 << "[label=" << curMinEdge.weight << "];\n";
            // 小终点放入已访问的节点集合中
            visited.insert(curMinEdge.v2);

            // 小终点对应的边，全部放入minEdges中，此时已经重复放置了边！！！但前面会检查，如果是Visitd的节点，跳过了，不会进入死循环
            for (const auto &i : adjList[curMinEdge.v2])
            {
                minEdges.push({curMinEdge.v2, i.first, i.second});
            }
        }
    }
}

// 在距离哈希表distanceMap中获取距离startVertex最近(小)的节点，但不包含已经在visited中的节点
// distanceMap中存的就是与startVertex不同距离的节点
template <class T>
std::pair<T, int> UndirectedGraph<T>::findMinDistanceVertexForDijkstra(std::unordered_map<T, int> &map, std::unordered_set<T> &set)
{
    int d = __INT_MAX__;
    T v;
    for (const auto &i : map) // 时间复杂度O(N)，循环遍历
    {
        if ((i.second < d) && (set.find(i.first) == set.end()))
        {
            d = i.second;
            v = i.first;
        }
    }
    return std::make_pair(v, d);
}

// Dijkstra shortest trace 戴克斯特拉算法
// 该最小路径算法要求：权重之和为负数的环
template <class T>
void UndirectedGraph<T>::Dijkstra(T startVertex)
{
    if (adjList.find(startVertex) == adjList.end())
    {
        return;
    }

    std::cout << "Dijkstra traversal from given vertex...\n";
    // 实例化“距离哈希表”：从节点startVertex出发，到达某节点的距离，key-value：（某节点，距离值）
    std::unordered_map<T, int> distanceMap;

    std::unordered_map<T, T> shortTraceMap; // 第一个参数是本节点，第二个参数是父节点

    // startVertex到达自己的距离是0
    distanceMap[startVertex] = 0;
    shortTraceMap[startVertex] = startVertex; // 如果父亲是自己，则表示是起点，这里不能赋值-1，因为类型T根本就还没有确定

    // 访问过的节点
    std::unordered_set<T> visited;

    // 在距离哈希表distanceMap中获取距离startVertex最近的节点，但不包含已经在visited中的节点
    // 每次找出来的顶点（或者从优先队列中取出顶点）就是这一轮最短路径权值确定的点
    std::pair<T, int> nearestDistance = findMinDistanceVertexForDijkstra(distanceMap, visited);

    // 如果找不到了，就说明结束了
    while (nearestDistance.second != __INT_MAX__)
    {
        for (const auto &i : adjList[nearestDistance.first]) // 遍历母点所有的边，（从这个节点出发的所有射线（邻接表））
        {
            // 每根射线的子点
            if (distanceMap.find(i.first) == distanceMap.end()) // 不在距离哈希表中，直接覆盖，说明这个节点是初始状态的无穷大，所以进行替换
            {
                distanceMap[i.first] = nearestDistance.second + i.second; // 使用射线起点往前的距离nearestDistance.second，加上 射线的长度i.second, 来替代无穷大
                // 这里从无到有，是添加键值对，如果换成优先级队列即小根堆，是可以在添加的同时完成大小排序的
                // 但是，后面会修改堆中的元素，这样就保证不了是小根堆了，这就是系统无法帮你完成的事情
                // 只能自己修改堆，实现堆，当值发生变化时，完成上堆化的操作，系统实现的优先级队列或者堆只能从无到有insert时才会排序

                shortTraceMap[i.first] = nearestDistance.first; // 谁让他变小的，记录下来
            }
            else // 如果在距离哈希表中，说明此时又找到了一条新的路线，那就看当前的值需不需要被替换，如果新的值更小，则替换老的
            {
                // distanceMap[i.first] = std::min(distanceMap[i.first], nearestDistance.second + i.second);
                // 这里发生了从旧值更替成新值，这样的修改，系统是不会帮你重新堆化的，只能自己实现堆化
                // 这样可以优化一些time complexity,所谓的自建堆和堆的优化
                if (nearestDistance.second + i.second < distanceMap[i.first])
                {
                    distanceMap[i.first] = nearestDistance.second + i.second;
                    shortTraceMap[i.first] = nearestDistance.first; // 谁让他变小的，记录下来
                }
                // 如果大于或者等于，就不动了
            }
        }
        visited.insert(nearestDistance.first); // 当前最近的节点（母点）已经处理完毕，固定下来了，标记为访问过的节点

        // 继续从距离哈希表中，弹出距离最小的顶点，这个过程是个遍历的过程，time complexity是O(N)
        // 换成自建的堆，可以有所优化
        // 从子点形成的扩大的堆或者哈希表中继续找最近的点
        nearestDistance = findMinDistanceVertexForDijkstra(distanceMap, visited);
    }

    for (const auto &i : distanceMap)
    {
        std::cout << startVertex << "--nearest--" << i.first << ": " << i.second << "\n";
        std::cout << startVertex << "--trace--" << i.first << ":\n";
        std::cout << i.first << " ";
        T cur = shortTraceMap[i.first];
        while (cur != startVertex) // 到了起点
        {
            std::cout << cur << " ";
            cur = shortTraceMap[cur];
        }
        std::cout << cur << "--\n";
    }
}

// 前缀树
struct TrieNode
{
    int pass;
    int end;
    // TrieNode *next[26];

    std::unordered_map<int, TrieNode *> nodeMap;

    TrieNode();
};

class Trie
{
public:
    Trie();
    void insert(std::string word);
    int search(std::string word);
    int prefix(std::string word);
    void deleteWord(std::string word);

private:
    void deleteZeroPassNode(TrieNode *cur, std::queue<int> &delQueue);

private:
    TrieNode *root;
};
