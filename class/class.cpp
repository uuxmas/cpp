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

TNode2 *Tree2::getLeftMost(TNode2 *node)
{
    if (node == nullptr)
    {
        return node;
    }

    while (node->l != nullptr)
    {
        node = node->l;
    }
    return node;
}

/**
 * 后继节点定义：中序遍历二叉树，某节点后面紧挨着的节点就是某节点的后继节点
 * 题目：在带有父节点的二叉树中，给定某节点，返回其后继节点
 */
TNode2 *Tree2::getSuccessor(TNode2 *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->r != nullptr) // 情况三，右树不空
    {
        return getLeftMost(node->r); // 找到右树中最左的孩(y)
    }

    // 如果到了根节点（根节点的父辈为空）都没有找到左树，说明一直在右侧，后继节点为空，返回空
    // 从本节点开始，往上找祖辈，某个祖辈是祖辈的父辈的左孩子，返回该祖辈的父辈(y)
    /** 一           二          三
     * ()           (y)         (x)
     *  \          /           /  \
     *   ()       ()         ()    ()
     *    \        \               /\
     *     (x)      (x)          (y) ()
     */

    while (node->p != nullptr) // 是根节点就从while退出了
    {
        if (node == node->p->l) // 情况二
        {
            return node->p;
        }

        node = node->p;
    }

    return nullptr; // 情况一
}

void Tree2::addData(int data)
{
    TNode2 *node = new TNode2(data);

    if (root == nullptr)
    {
        root = node;
        return;
    }

    std::queue<TNode2 *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode2 *cur = q.front();
        q.pop();

        if (cur->l != nullptr)
        {
            q.push(cur->l);
        }
        else
        {
            cur->l = node;
            cur->l->p = cur;
            return;
        }

        if (cur->r != nullptr)
        {
            q.push(cur->r);
        }
        else
        {
            cur->r = node;
            cur->r->p = cur;
            return;
        }
    }
}

std::string Tree2::getSpace(int num)
{
    std::string str = "";
    str.append(num, ' ');
    return str;
}

void Tree2::printInorder(TNode2 *node, int height, std::string to, int len)
{
    if (node == nullptr)
    {
        return;
    }

    printInorder(node->r, height + 1, "v", len);
    std::string val = to + std::to_string(node->data) + to;
    int lenM = val.length();
    int lenL = (len - lenM) >> 1;
    int lenR = len - lenM - lenL;
    std::cout << getSpace(height * len) + getSpace(lenL) + val + getSpace(lenR) << "\n";
    printInorder(node->l, height + 1, "^", len);
}

void Tree2::printTree()
{
    printInorder(root, 0, "H", 17);
}

// 二叉树节点的查找（层级遍历level order）
TNode2 *Tree2::findTreeNode2(int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    std::queue<TNode2 *> q;
    q.push(root);

    while (!q.empty())
    {
        TNode2 *cur = q.front();
        q.pop();

        if (cur->data == data)
        {
            return cur;
        }

        if (cur->l != nullptr)
        {
            q.push(cur->l);
        }

        if (cur->r != nullptr)
        {
            q.push(cur->r);
        }
    }

    return nullptr;
}

TNode2 *Tree2::getRoot()
{
    return this->root;
}

// 序列化一个二叉树
std::string Tree2::serialTree2()
{
    return serialTree2ByPreOrder(root);
}

// 序列化一个二叉树，使用前序遍历
std::string Tree2::serialTree2ByPreOrder(TNode2 *node)
{
    if (node == nullptr)
    {
        return "#_";
    }

    std::string str = std::to_string(node->data) + "_";

    std::string leftStr = serialTree2ByPreOrder(node->l);
    std::string rightStr = serialTree2ByPreOrder(node->r);

    return str + leftStr + rightStr;
}

// 构造函数，通过反序列化构造一个二叉树，使用前序遍历
Tree2::Tree2(const std::string &serialStr)
{
    std::queue<std::string> tokens;
    this->root = nullptr;
    split(serialStr, tokens);
    this->root = reconSerialTree2ByPreOrder(tokens);
}

void Tree2::split(const std::string &s, std::queue<std::string> &tokens, const std::string &delimiters) // 又是一个坑，缺省值delimeters在头文件中写明，在定义中不写缺省值
{
    std::string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    std::string::size_type pos = s.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        tokens.push(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

TNode2 *Tree2::reconSerialTree2ByPreOrder(std::queue<std::string> &tokens)
{
    std::string str = tokens.front();

    if (str == "#")
    {
        tokens.pop();
        return nullptr;
    }

    TNode2 *node = new TNode2(std::stoi(str));
    if (root == nullptr)
    {
        root = node;
    }
    tokens.pop();

    node->l = reconSerialTree2ByPreOrder(tokens);
    node->r = reconSerialTree2ByPreOrder(tokens);

    if (node->l != nullptr)
    {
        node->l->p = node;
    }

    if (node->r != nullptr)
    {
        node->r->p = node;
    }

    return node;
}

// 图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图图
/**
 * from,to,weight=matrix[i][3]
 */
void DirectedGraph::addVertexEdge(const int matrix[][3], const int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int from = matrix[i][0];
        int to = matrix[i][1];
        int weight = matrix[i][2];

        auto iterator = mapVertices.find(from);

        if (iterator == mapVertices.end()) // 图中不会存储重复的顶点
        {
            mapVertices.insert({from, new Vertex(from)});
        }

        iterator = mapVertices.find(to);

        if (iterator == mapVertices.end()) // 图中不会存储重复的顶点
        {
            mapVertices.insert({to, new Vertex(to)});
        }

        Vertex *vFrom = mapVertices.find(from)->second;
        Vertex *vTo = mapVertices.find(to)->second;

        Edge *e = new Edge(weight, vFrom, vTo);

        setEdges.insert(e);
        vFrom->out++;
        vFrom->vertices.push_back(vTo);
        vFrom->edges.push_back(e);
        vTo->in++;
    }
}

Vertex *DirectedGraph::findVertex(int value)
{
    auto iterator = mapVertices.find(value);
    if (iterator != mapVertices.end())
    {
        return iterator->second;
    }

    return nullptr;
}

// 广度优先搜索Breadth First Search
// 从根节点开始，沿着树的宽度遍历树的所有节点，如果树的所有节点都被访问，则终止
// 尚未遍历的节点放入open容器（如queue），已遍历的节点放入closed容器（如set哈希表）
void DirectedGraph::breadthFirstSearch(Vertex *v)
{

    if (v == nullptr)
    {
        return;
    }

    std::queue<Vertex *> q;         // open 表，如果更快的话，可以使用数组，改和查比哈希表更快一些
    std::unordered_set<Vertex *> s; // closed 表

    q.push(v);
    s.insert(v);

    std::cout << "Breadth First Search...\n";
    while (!q.empty())
    {
        Vertex *cur = q.front(); // 从open表中弹出，开始处理
        q.pop();

        // 开始处理当前节点，如打印
        std::cout << cur->value << " ";
        // 结束处理当前节点

        for (auto item : cur->vertices) // 对邻居顶点集合vector做遍历，没有进入过closed表的邻居进行处理
        {
            if (s.find(item) == s.end()) // closed表中没有，说明没有遍历或者访问过，则加入到open表和closed表中
            {
                q.push(item);
                s.insert(item);
            }
        }
    }
    std::cout << "\nBreadth First Search End!\n";
}

void DirectedGraph::depthFirstSearch(Vertex *v)
{
    if (v == nullptr)
    {
        return;
    }

    std::stack<Vertex *> stack;
    std::unordered_set<Vertex *> set;

    stack.push(v);
    set.insert(v);

    std::cout << "\nDepth First Search...\n";
    std::cout << v->value << " ";

    while (!stack.empty())
    {
        Vertex *cur = stack.top();
        stack.pop();

        for (auto item : cur->vertices)
        {
            if (set.find(item) == set.end())
            {
                stack.push(cur);
                stack.push(item);
                set.insert(item);
                std::cout << item->value << " ";
                break;
            }
        }
    }

    std::cout << "\nDepth First Search End!\n";
}

// 有向图，且有入度为0的顶点，且没有环的图
void DirectedGraph::topologySort()
{
    std::queue<Vertex *> q;

    for (auto item : mapVertices) // 遍历图中的所有顶点，将入度为0的节点放入单独的队列q
    {
        if (item.second->in == 0)
        {
            q.push(item.second); // 找到入度为0的节点，放入单独的队列q中
        }
    }

    std::cout << "\nTopology Sort...\n";

    while (!q.empty())
    {
        Vertex *cur = q.front();
        q.pop();

        // 开始处理遍历结果，如打印
        std::cout << cur << " ";
        // 结束处理遍历结果，如打印

        for (auto item : cur->vertices) // 遍历受其影响的所有邻居节点
        {

            item->in--; // 某个邻居的入度节点减一
            if (item->in == 0)
            {
                q.push(item); // 入度为0的邻居节点放入队列q
            }
        }
    }

    std::cout << "\nTopology Sort Ends!\n";
}

TrieNode::TrieNode()
{
    pass = 0;
    end = 0;
    // for (int i = 0; i < 26; i++)
    // {
    //     next[i] = nullptr;
    // }
}

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(std::string word)
{
    if (word == "")
    {
        return;
    }

    TrieNode *cur = root;
    cur->pass++;

    for (std::string::size_type i = 0; i < word.size(); i++)
    {
        int pos = word[i] - 'a';

        if (cur->nodeMap.find(pos) == cur->nodeMap.end())
        {
            cur->nodeMap[pos] = new TrieNode();
        }

        // if (cur->next[pos] == nullptr)
        // {
        //     cur->next[pos] = new TrieNode();
        // }

        cur = cur->nodeMap[pos];
        // cur = cur->next[pos];

        cur->pass++;
    }

    cur->end++;
}

int Trie::search(std::string word)
{
    if (word == "")
    {
        return 0;
    }

    TrieNode *cur = root;

    for (size_t i = 0; i < word.size(); i++)
    {
        int pos = word[i] - 'a';

        // if (cur->next[pos] == nullptr)
        if (cur->nodeMap.find(pos) == cur->nodeMap.end())
        {
            return 0;
        }
        // cur = cur->next[pos];
        cur = cur->nodeMap[pos];
    }

    return cur->end; // bool变量也可以通过end值返回，search时必须有end不为0，如在apple中search app，应该返回false
}

int Trie::prefix(std::string word)
{
    if (word == "")
    {
        return 0;
    }

    TrieNode *cur = root;

    for (size_t i = 0; i < word.size(); i++)
    {
        int pos = word[i] - 'a';

        // if (cur->next[pos] == nullptr)
        if (cur->nodeMap.find(pos) == cur->nodeMap.end())
        {
            return 0;
        }
        // cur = cur->next[pos];
        cur = cur->nodeMap[pos];
    }

    return cur->pass; // bool变量，也可以通过这个pass值返回
}

void Trie::deleteWord(std::string word)
{
    if (search(word) == 0)
    {
        return;
    }

    TrieNode *cur = root;
    --cur->pass;

    TrieNode *parent = nullptr;
    // int delIndex = -1;
    std::queue<int> delQueue;

    for (size_t i = 0; i < word.size(); i++)
    {
        int pos = word[i] - 'a';

        // if (--cur->next[pos]->pass == 0) // pass--
        if (--cur->nodeMap[pos]->pass == 0)
        {
            // cur->next[pos] = nullptr; // 如果降到0了，则直接nullptr，当做没有这个节点
            // cur->nodeMap[pos] = nullptr;//指针为0，还是可以找到，并不是哈希表的end()

            // cur->nodeMap.erase(pos);// 这里只是把这一个节点删除了，他后面的都还在，所以应该删除后续所有的节点
            // return;

            // 把第一次遇到的情况信息记录下来
            // pass为0的点都需要删除，所以这里进行记录，最后统一删除
            // 高级语言入java有GC回收机制，所以直接后面的全都可以自动回收，但是C++必须自己手动回收 
            parent = parent == nullptr ? cur : parent;//parent不用每次都替换
            //delIndex = delIndex == -1 ? pos : delIndex;
            delQueue.push(pos);//孩子必须每次都入队列，最后需要用到parent和孩子的队列，进行递归删除
        }

        // cur = cur->next[pos]; // 指向当前的pos对应的位置，下一个循环继续处理他的下一个
        cur = cur->nodeMap[pos];
    }

    --cur->end;

    // 统一从parent开始（不一定是root），将所有pass为0的delQueue节点从nodeMap中删除
    deleteZeroPassNode(parent, delQueue);
}

// 自己写的递归，逆着删除，牛逼得很
void Trie::deleteZeroPassNode(TrieNode *cur, std::queue<int> &delQueue)
{
    if (delQueue.empty())
    {
        return;
    }

    int index = delQueue.front();
    delQueue.pop();
    deleteZeroPassNode(cur->nodeMap[index], delQueue);
    cur->nodeMap.erase(index);
}