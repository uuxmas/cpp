#include "class.h"

Hero::Hero()
{
    this->name = "You";
    this->id = 10;
    this->energy = 100;
    this->attack = 50;
}

Hero::Hero(std::string name, int id, int energy, int attack)
{
    this->name = name;
    this->id = id;
    this->energy = energy;
    this->attack = attack;
}

std::string Hero::getName()
{
    return this->name;
}

int Hero::getId()
{
    return this->id;
}

int Hero::getEnergy()
{
    return this->energy;
}

int Hero::getAttack()
{
    return this->attack;
}

// IO对象无法使用拷贝构造和赋值运算符，所以流对象无法使用值传递，一般使用引用进行传递。
// cout << obj 相当于 operator<<(cout, obj)，而函数的定义是引用，所以是cout和对象的别名，省去了拷贝副本的时间
std::ostream &operator<<(std::ostream &out, Hero &obj)
{
    out << obj.name << " " << obj.id << " " << obj.energy << " " << obj.attack << std::endl;
    return out; // 返回out的引用，以便实现连续使用<<的操作。
}

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}

LinkList::LinkList()
{
    this->head = nullptr; // head不用初始化别的值，后续用来被一个新节点来覆盖 head中存的地址为0
    this->tail = nullptr; // tail不用初始化别的值，后续用来被一个新节点来覆盖 head中存的地址为0
}

void LinkList::InsertFrontData(int data)
{
    Node *node = new Node(data);
    if (head == nullptr) // 如果插入的是链表的第一个节点
    {
        tail = node;
        head = node;
    }
    else
    {
        node->next = head; // 新节点往head前面插入，next中存的地址变成head中存的地址，而head中存的地址是当前链表的第一个
        head = node;       // head中存的地址变成新增加的节点
    }
}

void LinkList::InsertBackData(int data)
{
    Node *node = new Node(data);
    if (tail == nullptr) // 如果插入的是链表的第一个节点
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

void LinkList::PrintList()
{
    Node *cur = head;
    while (cur != nullptr)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << "\n";
}

Node *LinkList::getHead()
{
    return this->head;
}

void LinkList::setHead(Node *&head)
{
    this->head = head;
}

// 链表反转
void LinkList::ReverseListI()
{
    Node *cur = head;

    std::stack<Node *> s;

    while (cur != nullptr) // 压栈，空间复杂度O(N)，时间复杂度O(N)
    {
        s.push(cur);
        cur = cur->next;
    }

    while (!s.empty()) // 出栈
    {

        Node *p = s.top();
        s.pop();
        if (p->next == nullptr)
        {
            head = p; // head的next也能被被下面的cur的操作next改变，因为指向同一个地址
            cur = p;
            continue;
        }
        cur->next = p;
        cur = p;
    }

    cur->next = nullptr;
    tail = cur;
}

void LinkList::ReverseListII()
{
    // 链表反转，换头操作需要返回新的头指针，递归
    head = ReverseRecursivelyList(head);
}

Node *LinkList::ReverseRecursivelyList(Node *&node)
{
    if (node->next == nullptr)
    {
        return node; // 找到了链表最后一个节点，然后一个个往后面穿起来了
    }

    Node *cur = ReverseRecursivelyList(node->next);
    node->next->next = node;
    node->next = nullptr;
    tail = node; // 别把尾巴忘了
    return cur;  // 最后需要有head来接这个返回值
}

void LinkList::ReverseListIII()
{
    // 链表反转，换头操作需要返回新的头指针，迭代
    head = ReverseIterateList(head);
}

Node *LinkList::ReverseIterateList(Node *&head)
{
    Node *cur = head;
    Node *prev = nullptr;

    while (cur != nullptr)
    {
        Node *tmp = cur->next;
        cur->next = prev;
        if (prev == nullptr)
        {
            tail = cur; // 说明是第一个节点，也就是尾巴，让tail这个标签附上来
        }
        prev = cur;
        cur = tmp;
    }

    return prev;
}

void LinkList::DeleteFront()
{
    if (head == nullptr) // 没有节点
    {
        return;
    }

    Node *tmp = head;
    if (tmp->next == nullptr) // 一个节点
    {
        head = nullptr;
        tail = nullptr;
        delete tmp;
        tmp = nullptr;
        return;
    }

    head = head->next; // 多个节点

    delete tmp;
    tmp = nullptr;
}

void LinkList::DeleteBack()
{
    if (head == nullptr) // 没有节点
    {
        return;
    }

    Node *cur = head;

    if (cur->next == nullptr) // 只有一个节点
    {
        head = nullptr;
        tail = nullptr;
        delete cur;
        cur = nullptr;
        return;
    }

    Node *parent;
    while (cur->next != nullptr) // 多个节点
    {
        parent = cur;
        cur = cur->next;
    }

    parent->next = nullptr;
    tail = parent;

    delete cur;
    cur = nullptr;
}

void LinkList::DeleteData(int data)
{
    if (head == nullptr) // 没有节点
    {
        return;
    }

    if (head->data == data) // 第一个节点命中
    {
        if (head->next == nullptr) // 且只有一个节点
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node *p = head; // 后面有很多节点
        head = head->next;
        delete p;
        p = nullptr;
        return;
    }

    Node *cur = head;
    Node *parent = cur;
    while (cur->next != nullptr && cur->data != data)
    {
        parent = cur;
        cur = cur->next;
    }

    if (cur->next == nullptr) // 如果是最后一个节点
    {
        if (cur->data == data)
        {
            parent->next = nullptr;
            tail = parent;
            delete cur;
            cur = nullptr;
        }
        return;
    }

    parent->next = cur->next; // 找到了data，在中间位置
    delete cur;
    cur = nullptr;
}

int LinkList::findData(int data)
{
    Node *cur = head;
    int i = 0;

    std::unordered_map<int, int> map; // 定义一个哈希表hashmap,空间复杂度变成O(N)了，没必要，这里是为了练习哈希表的coding

    while (cur != nullptr)
    {
        map[cur->data] = i; // 先插入，再找，根据判断条件不同，这里有不同，跟两数之和的顺序，数据作为键值，index作为value存入哈希表，查谁把谁作为key

        auto iterator = map.find(data);
        if (iterator != map.end())
        {
            return iterator->second; // 返回对应的index
        }

        cur = cur->next;
        i++;
    }

    return -1; // 没找到，返回负数
}

// 把链表在position所指位置成环
void LinkList::loopifyList(int index)
{
    Node *p = head;
    while (index--)
    {
        p = p->next;
    }

    tail->next = p;
}

// 二叉树节点，有参构造函数
TNode::TNode(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

Tree::Tree()
{
    this->root = nullptr;
}

TNode *Tree::getRoot()
{
    return this->root;
}

void Tree::setRoot(TNode *&node)
{
    this->root = node;
}

void Tree::TreeAddData(int data)
{
    TNode *node = new TNode(data);

    if (root == nullptr)
    {
        root = node;
        return;
    }
    // 遍历二叉树，添加新数据

    // 层序遍历，添加新数据
    std::queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *cur = q.front();
        q.pop();

        if (cur->left == nullptr)
        {
            cur->left = node;
            return;
        }
        else
        {
            q.push(cur->left);
        }

        if (cur->right == nullptr)
        {
            cur->right = node;
            return;
        }
        else
        {
            q.push(cur->right);
        }
    }
}

void Tree::PreRecursive()
{
    std::cout << "pre order recursive traversal:\n";
    TreePreOrderTraversalRecur(root);
    std::cout << "\n";
}

void Tree::TreePreOrderTraversalRecur(TNode *&node)
{
    // 第一次进来
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->data << " ";
    TreePreOrderTraversalRecur(node->left);
    // 第二次进来

    TreePreOrderTraversalRecur(node->right);
    // 第三次进来
}

void Tree::InRecursive()
{
    std::cout << "in order recursive traversal:\n";
    TreeInOrderTraversalRecur(root);
    std::cout << "\n";
}

void Tree::TreeInOrderTraversalRecur(TNode *&node)
{
    // 第一次进来
    if (node == nullptr)
    {
        return;
    }

    TreeInOrderTraversalRecur(node->left);
    // 第二次进来
    std::cout << node->data << " ";

    TreeInOrderTraversalRecur(node->right);
    // 第三次进来
}

void Tree::PostRecursive()
{
    std::cout << "post order recursive traversal:\n";
    TreePostOrderTraversalRecur(root);
    std::cout << "\n";
}

void Tree::TreePostOrderTraversalRecur(TNode *&node)
{
    // 第一次进来
    if (node == nullptr)
    {
        return;
    }

    TreePostOrderTraversalRecur(node->left);
    // 第二次进来

    TreePostOrderTraversalRecur(node->right);
    // 第三次进来
    std::cout << node->data << " ";
}

void Tree::PreUnRecur()
{
    TreePreOrderTraversalUnRecur(root);
}

void Tree::TreePreOrderTraversalUnRecur(TNode *&node)
{
    std::cout << "pre order unrecursive traversal:\n";

    if (node == nullptr)
    {
        std::cout << "null node\n";
        return;
    }

    std::stack<TNode *> s;
    s.push(node);

    while (!s.empty())
    {
        TNode *cur = s.top();
        s.pop();

        std::cout << cur->data << " ";

        if (cur->right != nullptr)
        {
            s.push(cur->right);
        }
        if (cur->left != nullptr)
        {
            s.push(cur->left);
        }
    }
    std::cout << "\n";
}

void Tree::PostUnRecur()
{
    TreePostOrderTraversalUnRecur(root);
}

void Tree::TreePostOrderTraversalUnRecur(TNode *&node)
{
    std::cout << "post order unrecursive traversal:\n";

    if (node == nullptr)
    {
        std::cout << "null node\n";
        return;
    }

    std::stack<TNode *> s1;
    std::stack<TNode *> s2;
    s1.push(node);

    while (!s1.empty())
    {
        TNode *cur = s1.top();
        s1.pop();

        s2.push(cur);

        if (cur->left != nullptr)
        {
            s1.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            s1.push(cur->right);
        }
    }

    while (!s2.empty())
    {
        std::cout << s2.top()->data << " ";
        s2.pop();
    }
    std::cout << "\n";
}

void Tree::InUnRecur()
{
    TreeInOrderTraversalUnRecur(root);
}

void Tree::TreeInOrderTraversalUnRecur(TNode *&node)
{
    std::cout << "in order unrecursive traversal:\n";

    if (node == nullptr)
    {
        std::cout << "null node\n";
        return;
    }

    std::stack<TNode *> s;
    TNode *cur = node;

    while (cur != nullptr)
    {
        s.push(cur);
        cur = cur->left;
    }

    while (!s.empty())
    {
        cur = s.top();
        s.pop();
        std::cout << cur->data << " ";

        if (cur->right != nullptr)
        {
            TNode *p = cur->right;
            do
            {
                s.push(p);
                p = p->left;
            } while (p != nullptr);
        }
    }
    std::cout << "\n";
}

void Tree::TreePrint()
{
    std::cout << "print binary tree:\n";
    printInOrder(root, 0, "H", 17);
    std::cout << "\n";
}

void Tree::printInOrder(TNode *&node, int height, std::string to, int len)
{
    if (node == nullptr)
    {
        return;
    }
    printInOrder(node->right, height + 1, "v", len);

    // 第二次进来开始处理，中序遍历
    std::string val = to + std::to_string(node->data) + to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    std::cout << getSpace(height * len) + val << "\n";
    // 第二次处理完毕

    printInOrder(node->left, height + 1, "^", len);
}

std::string Tree::getSpace(int num)
{
    std::string space = "";

    space.append(num, ' ');

    return space;
}

void Tree::levelOrder()
{

    if (root == nullptr)
    {
        return;
    }

    std::queue<TNode *> q;
    TNode *cur = root;
    TNode *end = root;
    q.push(root);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        std::cout << cur->data << " ";

        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }

        if (cur == end) // 到达本层的最后一个节点
        {
            std::cout << "|";
            end = q.back();
        }
    }
}

int Tree::getTreeWidth()
{
    std::queue<TNode *> q;
    TNode *cur = root;
    TNode *end = root;
    int maxWidth = __WINT_MIN__;
    int counter = 0;
    q.push(root);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        counter++;

        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }

        if (cur == end)
        {
            maxWidth = counter > maxWidth ? counter : maxWidth;
            counter = 0;
            end = q.back();
        }
    }

    return maxWidth;
}

std::vector<int> Tree::isBSTRecurIII(TNode *&node)
{
    if (node == nullptr)
    {
        return std::vector<int>{1, __WINT_MIN__, __INT_MAX__}; // 空节点是BST，最大值，最小值，设置成这样叶子节点才能大于左空节点的最大，小于右空节点的最小
    }

    std::vector<int> isLeftBSTRecurIII = isBSTRecurIII(node->left);   // 当做黑盒
    std::vector<int> isRightBSTRecurIII = isBSTRecurIII(node->right); // 当做黑盒

    // 黑盒内分解，动态规划
    // 拿着左右两个树的数据，进行处理。
    bool isBSTRecurIII = isLeftBSTRecurIII[0] &
                         isRightBSTRecurIII[0] &
                         (node->data > isLeftBSTRecurIII[1]) &
                         (node->data < isRightBSTRecurIII[2]);

    std::vector<int> cur;

    cur.push_back(isBSTRecurIII);
    if (isLeftBSTRecurIII[1] == __WINT_MIN__ && isRightBSTRecurIII[2] == __INT_MAX__)
    {
        cur.push_back(node->data);
        cur.push_back(node->data);
        return cur;
    }

    cur.push_back(std::max(std::max(node->data, isLeftBSTRecurIII[1]), isRightBSTRecurIII[1])); // 三者中最大
    cur.push_back(std::min(std::min(node->data, isLeftBSTRecurIII[2]), isRightBSTRecurIII[2])); // 三者中最小

    return cur;
}
// 树形DP，规划最难的
bool Tree::isBinarySearchTreeIII()
{
    std::vector<int> res;
    res = isBSTRecurIII(root);
    return res[0];
}

// 判断一个树是否为搜索二叉树（左小，右大），直接中序遍历该树，如果是升序排列，则是搜索二叉树
// 还有一种recursive的方法，就是直接中序递归，该处理的时候，压入栈
bool Tree::isBSTRecur(TNode *&node, int *&preValue)
{
    if (node == nullptr)
    {
        return true;
    }

    bool isLeftBST = isBSTRecur(node->left, preValue);

    if (isLeftBST != true)
    {
        return false;
    }

    if (node->data < *preValue)
    {
        return false;
    }

    *preValue = node->data;

    bool isRightBST = isBSTRecur(node->right, preValue);

    return isRightBST;
}

bool Tree::isBSTIterator(TNode *&node)
{
    if (node == nullptr)
    {
        return true;
    }

    std::stack<TNode *> s;

    TNode *cur = node;
    int preValue = __WINT_MIN__;

    while (cur != nullptr)
    {
        s.push(cur);
        cur = cur->left;
    }

    while (!s.empty())
    {
        cur = s.top();
        s.pop();

        // 下面这部分本来是中序打印的地方
        if (cur->data < preValue)
        {
            return false;
        }
        else
        {
            preValue = cur->data;
        }
        // 上面这部分本来是中序打印的地方

        if (cur->right != nullptr)
        {
            TNode *p = cur->right;
            do
            {
                s.push(p);
                p = p->left;
            } while (p != nullptr);
        }
    }

    return true;
}

bool Tree::isBinarySearchTreeI()
{
    int *preValue = new int(__WINT_MIN__);

    bool isBST = isBSTRecur(root, preValue);

    delete preValue;
    preValue = nullptr;
    return isBST;
}

bool Tree::isBinarySearchTreeII()
{
    return isBSTIterator(root);
}

// level order进行遍历，所以得用队列，1，有右没有左，返回false 2. 如果是叶节点，后续所有节点必须也是叶节点
// 完全二叉树的性质
bool Tree::isCompletedBinaryTree()
{
    std::queue<TNode *> q;
    q.push(root);
    bool leaf = false;

    while (!q.empty())
    {
        // 弹出当前节点开始处理
        TNode *cur = q.front();
        TNode *l = cur->left;
        TNode *r = cur->right;
        q.pop();

        if (l == nullptr && r != nullptr) // 有右，没左，返回false
        {
            return false;
        }
        if (l == nullptr && r == nullptr) // 当前节点是否叶子节点
        {
            leaf = true;
        }
        if (leaf == true && (l != nullptr || r != nullptr)) // 之前曾经出现过leaf，但是当前节点又有孩子，返回false
        {
            return false;
        }

        // level order 层序遍历，入队列
        if (l != nullptr)
        {
            q.push(l);
        }
        if (r != nullptr)
        {
            q.push(r);
        }
    }

    return true;
}

// 平衡二叉树的判断
bool Tree::isBalanceBinaryTree()
{
    return isBBTRecur(root).first;
}

// 需要两个指标进行判断，1. 左边和右边都是（平）衡二叉树，2. 左右的高度差小于2
// 通过递归，因为需要用到左右两个树的信息，所以应该在类似后序遍历的打印时机开始处理本节点，使用上述的信息进行处理
std::pair<bool, int> Tree::isBBTRecur(TNode *&node)
{
    if (node == nullptr)
    {
        return std::pair<bool, int>{true, 0};
    }

    std::pair<bool, int> isLeftBBT = isBBTRecur(node->left);
    std::pair<bool, int> isRightBBT = isBBTRecur(node->right);

    // 本层的高度是左右孩子高度的最大值再加1
    int maxHeight = std::max(isLeftBBT.second, isRightBBT.second) + 1;

    // 判断左右是否都是平衡二叉树，且左右高度差是否小于2
    bool isBalanced = isLeftBBT.first & isRightBBT.first & (std::abs(isLeftBBT.second - isRightBBT.second) < 2);

    // 返回本层的判断和本层的高度
    return std::pair<bool, int>(isBalanced, maxHeight);
}

// 满二叉树的判断，节点数量=2^l -1, l为树的深度
// 根据树的DP思路，需要提供节点数和深度，左右子树进行递归
std::pair<int, int> Tree::isFBTRecur(TNode *&node)
{
    if (node == nullptr)
    {
        return std::pair<int, int>(0, 0);
    }

    std::pair<int, int> leftPair = isFBTRecur(node->left);
    std::pair<int, int> rightPair = isFBTRecur(node->right);

    int nodeNum = leftPair.first + rightPair.first + 1;           // 到本层为止，一共的节点数是多少
    int height = std::max(leftPair.second, rightPair.second) + 1; // 本层的深度是多少

    return std::pair<int, int>(nodeNum, height);
}

bool Tree::isFullBinaryTree()
{
    std::pair<int, int> res = isFBTRecur(root);
    return res.first == ((1 << res.second) - 1);
}

TNode *Tree::findTreeNode(int data)
{
    std::unordered_map<int, TNode *> map;
    std::queue<TNode *> q;
    TNode *cur = root;
    q.push(cur);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        map[cur->data] = cur;

        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }

    auto iterator = map.find(data);
    if (iterator != map.end())
    {
        return iterator->second;
    }

    return nullptr;
}