#include "leetcode.h"

int singleNumber_136(std::vector<int> &vec)
{
    int result = 0;
    for (auto &item : vec)
    {
        result ^= item;
    }
    return result;
}

int singleNumberII_137(std::vector<int> &vec)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int single_sum = 0;
        for (auto &item : vec)
        {
            single_sum += item >> i & 1;
        }
        result += single_sum % 3 << i;
    }
    return result;
}

std::vector<int> twoNumbers(std::vector<int> &vec)
{
    int eor = 0;
    int rightOne = 0;
    int num1 = 0;
    int num2 = 0;

    // 两个所求数字的exclusive值，而出现偶数次的数字exclusive为0
    for (auto &item : vec)
    {
        eor ^= item;
    }

    // 上述结果的数字中为1的位置，都是两个所求数字的不同的地方，得到最右边第一个1，以此来作为两个所求数字的区分
    rightOne = eor & (~eor + 1);

    // 等于区分数的，在一边，不等于的在另外一边
    for (auto &item : vec)
    {
        if ((item & rightOne) == rightOne)
        {
            num1 ^= item;
        }
    }

    // 异或的结合律
    num2 = eor ^ num1;

    return std::vector<int>{num1, num2};
}

/**
 * 要求：子数组中连续元素之和大于等于target值时，满足要求的子数组中的数组元素个数最少是多少。
 * 方法：用双指针 start 和 end 表示一个滑动窗口。
 * 1. end 向右移增大窗口，直到窗口内的数字和大于等于 target，进行第 2 步。
 * 2. 记录此时的长度，start 向右移动，开始减少长度，每减少一次，就更新最小长度。直到当前窗口内的数字和小于 target，回到第 1 步。
 */
int minimumSizeSubarraySum_209(std::vector<int> &vec, int target)
{
    int min = __INT_MAX__;
    int size = vec.size();
    int sum = 0;
    int start = 0;
    int end = 0;

    while (end < size)
    {
        sum += vec[end++]; // 尾指针逐渐后移，满足要求时停止
        while (sum >= target)
        {
            min = (end - start) < min ? (end - start) : min;
            sum -= vec[start++]; // 满足要求后头指针逐渐后移
        }
    }
    return (min == __INT_MAX__) ? 0 : min;
}

// 计算小数和，归并排序的衍生
// 在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和
//  ----------------------------------
//  ^               ^^               ^
//  |               ||               |
//  l              m m+1             r
//  left            right
int smallSum_merge(std::vector<int> &vec, int l, int m, int r)
{
    int left = l;
    int right = m + 1;
    int sumMerge = 0;
    std::vector<int> helpVector;

    while (left <= m && right <= r)
    {
        sumMerge += vec[left] < vec[right] ? vec[left] * (r - right + 1) : 0;      // 大于或者等于时，不产生小和，当前右边有多少个数比vec[left]大
        helpVector.push_back(vec[left] < vec[right] ? vec[left++] : vec[right++]); // 一定是<，与merge排序最不一样的地方，没有等号=这里，也就是出现相等时，必须先拷贝右边的数据，也就是让右边的指针移动，而且不产生小和
    }
    while (left <= m)
    {
        helpVector.push_back(vec[left++]);
    }
    while (right <= r)
    {
        helpVector.push_back(vec[right++]);
    }
    // 右边的也单独需要排序，所以需要vec.begin()+l，而不是vec.begin()
    std::copy(helpVector.begin(), helpVector.end(), vec.begin() + l);
    return sumMerge;
}

int smallSum_process(std::vector<int> &vec, int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    // 分半，等号右边的括号需要加上
    int m = l + ((r - l) >> 1);
    // 左边排序
    int sumL = smallSum_process(vec, l, m);
    // 右边排序
    int sumR = smallSum_process(vec, m + 1, r);
    // 合并
    int sumM = smallSum_merge(vec, l, m, r);

    return sumL + sumR + sumM;
}

int smallSum_main(std::vector<int> &vec)
{
    int n = vec.size();
    int smallSum = 0;

    if (n <= 1)
    {
        return 0;
    }

    smallSum = smallSum_process(vec, 0, n - 1);

    return smallSum;
}

// 在一个数组中，左边的数如果比右边的大，则这两个数构成一个逆序对，请打印所有逆序对
// 计算逆序对的数量，reverse pair，归并排序的衍生
//  ----------------------------------
//  ^               ^^               ^
//  |               ||               |
//  l              m m+1             r
//              left                right
int reversePair_merge(std::vector<int> &vec, int l, int m, int r)
{
    int left = m;
    int right = r;
    int reversePair = 0;
    std::vector<int> helpVector;

    while (left >= l && right >= m + 1)
    {
        reversePair += vec[left] > vec[right] ? (right - (m + 1) + 1) : 0;                            // 大的数字，要离开，队列有序才能O(1)的时间复杂度立刻算出来有多少个逆序对
        helpVector.insert(helpVector.begin(), (vec[left] > vec[right] ? vec[left--] : vec[right--])); // 大的数字进入队列时，还是需要升序排列，才能快速算出逆序对的数量,所以使用头插法
    }
    while (left >= l)
    {
        helpVector.insert(helpVector.begin(), vec[left--]);
    }
    while (right >= m + 1)
    {
        helpVector.insert(helpVector.begin(), vec[right--]);
    }
    // 右边的也单独需要排序，所以需要vec.begin()+l，而不是vec.begin()
    std::copy(helpVector.begin(), helpVector.end(), vec.begin() + l);
    return reversePair;
}

int reversePair_process(std::vector<int> &vec, int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    // 分半，等号右边的括号需要加上
    int m = l + ((r - l) >> 1);
    // 左边排序
    int reverseL = reversePair_process(vec, l, m);
    // 右边排序
    int reverseR = reversePair_process(vec, m + 1, r);
    // 合并
    int reverseM = reversePair_merge(vec, l, m, r);

    return reverseL + reverseR + reverseM;
}

int reversePair_main(std::vector<int> &vec)
{
    int n = vec.size();
    int reversePair = 0;

    if (n <= 1)
    {
        return 0;
    }

    reversePair = reversePair_process(vec, 0, n - 1);

    return reversePair;
}

// 荷兰国旗问题（三色球分类问题）
void dutchFlagI(std::vector<int> &vec, int l, int r, int target)
{
    int cur = l;
    int less = l - 1;
    int more = r + 1;

    while (cur < more)
    {
        if (vec[cur] < target)
        {
            // 该值与less的下一个互换，less区域右扩，cur右移
            std::swap(vec[cur], vec[++less]);
            cur++;
        }
        else if (vec[cur] > target)
        {
            // 该值与more的上一个互换，more区域左扩，cur不动，因为要继续比较新换过来的
            std::swap(vec[cur], vec[--more]);
        }
        else
        { // 相等，则cur右移
            cur++;
        }
    }
}

// 给定一个数组，基本有序，无序的元素与有序的差值不大于k个
// 如何使用最快的方式对该数组进行排序，k远小于数组的长度
void sortArrDistanceLessK(std::vector<int> &vec, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> q; // 小根堆，默认是大根堆
    // std::priority_queue<int, std::vector<int>, std::less<int>> q; // 大根堆

    int n = vec.size();
    std::vector<int> v;

    int i = 0;
    for (; i <= k; i++)
    {
        q.push(vec[i]);
    }
    for (; i < n; i++)
    {
        v.push_back(q.top());
        q.pop();
        q.push(vec[i]);
    }
    while (!q.empty())
    {
        v.push_back(q.top());
        q.pop();
    }

    vec = v;
}

// 查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法。
// 遍历一遍哈希表
std::vector<int> twoSum_1(const std::vector<int> &vec, int target)
{
    std::unordered_map<int, int> map;

    std::size_t n = vec.size();

    for (std::size_t i = 0; i < n; i++)
    {
        auto iterator = map.find(target - vec[i]); // HashMap(哈希表)'s find returns an iterator，which is a pointer，不等于map.end()，则表示找到了
        // if (iterator != map.end() && iterator->second != i) // vector中同一个元素不能使用两遍，target=8，使用了两遍4
        if (iterator != map.end()) // 如果是先插入的话，再查的话，会用到同一个元素vector中同一个元素不能使用两遍，target=8，使用了两遍4
        {
            return std::vector<int>{iterator->second, static_cast<int>(i)};
        }
        else
        {
            // map.insert(vec[i], i);
            // c++ 中往hashmap中插入键值对，使用如下方式：vec[i]是key，i是value
            map[vec[i]] = i;
        }
    }
    return std::vector<int>{};
}

// 打印两个有序链表的功能部分
// 两个指针分别指向两个链表的头部，一起右移，相等打印，否则谁小，谁右移，直到有一个指针结束
void orderedTwoListsSameElements()
{
    LinkList myList1;
    LinkList myList2;

    std::vector<int> vec1;
    std::vector<int> vec2;

    const int MS = 10; // max size
    const int MV = 10; // max value

    randomVector(MS, MV, vec1);
    randomVector(MS, MV, vec2);

    quickSort(vec1);
    quickSort(vec2);

    for (int &item : vec1)
    {
        myList1.InsertBackData(item);
    }

    for (int &item : vec2)
    {
        myList2.InsertBackData(item);
    }

    myList1.PrintList();
    myList2.PrintList();

    // 已生成两个有序的链表
    Node *p1 = myList1.getHead();
    Node *p2 = myList2.getHead();

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->data == p2->data)
        {
            std::cout << "the same: " << p1->data << " ";
            p1 = p1->next;
            p2 = p2->next;
            continue;
        }
        if (p1->data < p2->data)
        {
            p1 = p1->next;
        }
        else
        {
            p2 = p2->next;
        }
    }
}

// 判断给定的链表是否为回文
bool isPalindromeI(LinkList &myList)
{
    std::stack<int> s;
    bool res = true;
    Node *p = myList.getHead();

    while (p != nullptr) // extra space 空间复杂度O(N)
    {
        s.push(p->data);
        p = p->next;
    }

    p = myList.getHead(); // p指针复位重新从头开始

    while (p != nullptr) // 时间复杂度O(N)
    {
        if (p->data == s.top())
        {
            s.pop();
            p = p->next;
            continue;
        }
        res = false;
        break;
    }

    return res;
}

// 快慢指针，判断回文结构的链表，时间复杂度O(N)，空间复杂度O(1)
bool isPalindromeII(LinkList &myList)
{
    bool res = true;

    Node *slow = myList.getHead();
    Node *fast = myList.getHead();

    while ((fast != nullptr) && (fast->next != nullptr)) // 快指针结束，则结束，后续使用此时的慢指针，奇数和偶数同时考虑
    {
        slow = slow->next; // AAABBB，得到第一个B // AACBB，得到C
        fast = fast->next->next;
    }

    // 反转开始
    Node *cur = slow; // 使用慢指针，指向第一个B,或者指向了C
    Node *prev = nullptr;
    while (cur != nullptr) // 反转链表的后半部分
    {
        Node *tmp = cur->next; // 临时保存当前节点的下一个节点
        cur->next = prev;      // 反转当前节点的指针
        prev = cur;            // 前一个节点移到当前节点
        cur = tmp;             // 当前节点移到下一个节点
    }
    // 反转结束，prev是右半部分反转后的链表的头

    // 保存一份，以便后续再反转回来
    Node *copy = prev;

    // 左右两个链表同时开始比较，从外向内移动指针
    Node *h1 = myList.getHead();
    Node *h2 = prev;

    // 使用前半部分进行结束的判断，因为这样奇偶都能覆盖上
    // 前半部分最后一个节点，他的next还是指向slow这个节点，这点很重要！！！
    while ((h1 != slow) && (h1->data == h2->data)) // check palindrome
    {
        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 != slow) // 说明有不相等的数据，提前跳出while循环
    {
        res = false;
    }

    // 恢复原来的链表 recover list
    // 反转开始
    Node *cur_ = copy; // 使用慢指针，指向第一个B,或者指向了C
    Node *prev_ = nullptr;
    while (cur_ != nullptr) // 反转链表的后半部分
    {
        Node *tmp_ = cur_->next; // 临时保存当前节点的下一个节点
        cur_->next = prev_;      // 反转当前节点的指针
        prev_ = cur_;            // 前一个节点移到当前节点
        cur_ = tmp_;             // 当前节点移到下一个节点
    }
    // 反转结束，prev是右半部分反转后的链表的头

    return res;
}

// 笔试使用不用理会多增加的extra space，只要第一时间把代码写出来即可，
// 但是面试不行，你得extra space得是O(1)，因为他在面试中要考察你的coding能力
// 没有改变头，所以不需要返回head
void partitionList(LinkList &myList, int pivot)
{

    Node *cur = myList.getHead();

    std::vector<int> vec;

    while (cur != nullptr)
    {
        vec.push_back(cur->data);
        cur = cur->next;
    }

    // partition
    int less = 0 - 1;
    int more = vec.size();
    int i = 0;
    while (i != more)
    {
        if (vec[i] < pivot)
        {
            std::swap(vec[i], vec[++less]);
            i++;
        }
        else if (vec[i] > pivot)
        {
            std::swap(vec[i], vec[--more]);
        }
        else
        {
            i++;
        }
    }

    // 重新把vec赋值给链表
    cur = myList.getHead();
    i = 0;
    while (cur != nullptr)
    {
        cur->data = vec[i++];
        cur = cur->next;
    }
}

// 空间复杂度从O(N)，变为O(1)，面试时要这样写，这样才是考察你的coding能力
// 代价是，原本的myList已经被改的乱七八糟了，为了省空间，只能从原来的链表中作动作
void partitionListII(LinkList &myList, int pivot)
{
    Node *sh = nullptr; // short head
    Node *st = nullptr; // short tail
    Node *eh = nullptr; // equal head
    Node *et = nullptr; // equal tail
    Node *bh = nullptr; // big head
    Node *bt = nullptr; // big tail

    Node *cur = myList.getHead();

    while (cur != nullptr) // 把所有的节点按要求放到大中小3个链表上
    {
        if (cur->data < pivot)
        {
            if (sh == nullptr && st == nullptr)
            {
                sh = cur;
                st = cur;
            }
            else
            {
                st->next = cur;
                st = cur;
            }
        }
        else if (cur->data > pivot)
        {
            if (bh == nullptr && bt == nullptr)
            {
                bh = cur;
                bt = cur;
            }
            else
            {

                bt->next = cur;
                bt = cur;
            }
        }
        else
        {
            if (eh == nullptr && et == nullptr)
            {
                eh = cur;
                et = cur;
            }
            else
            {

                et->next = cur;
                et = cur;
            }
        }

        cur = cur->next;
    }

    if (sh != nullptr)
    {
        st->next = eh == nullptr ? bh : eh;
    }
    if (eh != nullptr)
    {
        et->next = bh;
    }
    if (bh != nullptr)
    {
        bt->next = nullptr;
    }

    Node *p = sh == nullptr ? (eh == nullptr ? bh : eh) : sh;
    myList.setHead(p);
}

Node *copyListWithRandNode(LinkList &myList)
{
    std::unordered_map<Node *, Node *> map;
    Node *cur = myList.getHead();

    while (cur != nullptr) // hashmap哈希表将所有的节点都存起来，key是原来的节点，value是同样的data值对应的新节点
    {
        Node *p = new Node(cur->data);
        map[cur] = p;
        cur = cur->next;
    }

    // 对新的节点进行链接link
    cur = myList.getHead();
    while (cur != nullptr)
    {
        auto iterator = map.find(cur);
        auto iteratorNext = map.find(cur->next);

        if (iteratorNext == map.end()) // 说明iteratorNext为空
        {
            iterator->second->next = nullptr;
            break;
        }

        iterator->second->next = iteratorNext->second;

        cur = cur->next;
    }
    cur = myList.getHead();
    return map.find(cur)->second;
}

// 入环节点，有则返回入环节点，无则返回空
Node *getLoopPoint(LinkList &myList)
{
    Node *slow = myList.getHead();
    Node *fast = myList.getHead();

    if (slow == nullptr || slow->next == nullptr || slow->next->next == nullptr)
    {
        return nullptr;
    }

    do
    {
        if (fast->next == nullptr || fast->next->next == nullptr) // 奇数偶数两种情况都考虑进来
        {
            return nullptr; // 单向无环则退出
        }

        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast); // 快慢指针第一次相遇（内存地址），退出循环，slow保持当前的位置

    fast = myList.getHead(); // 快指针从头开始，变成慢指针，与前面的slow指针一起walk，直到再次相遇，则是入环节点
    do
    {
        slow = slow->next;
        fast = fast->next;
    } while (slow != fast); // 两个慢指针再次相遇（内存地址），退出循环，相遇点（内存地址相等），则是入环地址

    return slow;
}

// 两个链表长度和为N，要求时间复杂度O(N)，extra space O(1)，
// 也就是不允许使用哈希表（extra space = O(N)）
Node *intersectListsNoLoop(LinkList &myList1, LinkList &myList2)
{
    // myList1.loopifyList(2);
    // myList2.loopifyList(1);

    // Node *loop1 = getLoopPoint(myList1);
    // Node *loop2 = getLoopPoint(myList2);

    // 两个链表都没有成环，只有一种情况可以相交，即成一个Y字型
    // if (loop1 == nullptr && loop2 == nullptr)

    Node *cur1 = myList1.getHead();
    Node *cur2 = myList2.getHead();
    int len = 0;

    while (cur1->next != nullptr) // 是最后一个节点，停止
    {
        len++;
        cur1 = cur1->next;
    }

    while (cur2->next != nullptr)
    {
        len--;
        cur2 = cur2->next;
    }

    if (cur1 != cur2) // 没有成环，而且最后的节点不相等，说明是两个链表没有相交，直接返回空
    {
        return nullptr;
    }

    // 说明是两个链表组成了Y字型，有共同的Y字型的下半部分，最后一个节点的内存地址相等
    // cur1赋值长链表的头，cur2赋值短链表的头
    cur1 = len > 0 ? myList1.getHead() : myList2.getHead();
    cur2 = cur1 == myList1.getHead() ? myList2.getHead() : myList1.getHead();
    len = std::abs(len);

    while (len--)
    {
        cur1 = cur1->next;
    }

    while (cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return cur1;
}

Node *intersectListsBothLoop(LinkList &myList1, Node *loop1, LinkList &myList2, Node *loop2)
{
    // 类似两个都无环的情况
    if (loop1 == loop2) // 相等时，只有一个情况，Y字型下面挂着一个气球
    {
        Node *cur1 = myList1.getHead();
        Node *cur2 = myList2.getHead();
        int len = 0;
        while (cur1 != loop1)
        {
            len++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2)
        {
            len--;
            cur2 = cur2->next;
        }

        cur1 = len > 0 ? myList1.getHead() : myList2.getHead();
        cur2 = cur1 == myList1.getHead() ? myList2.getHead() : myList1.getHead();
        len = std::abs(len);

        while (len--)
        {
            cur1 = cur1->next;
        }

        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return cur1;
    }
    else
    {
        Node *cur1 = loop1->next;
        while (cur1 != loop1)
        {
            if (cur1 == loop2) // 带耳朵的猫头形状
            {
                return loop1;
            }

            cur1 = cur1->next; // 转一圈，如果没有遇到loop2，则说明是两个独立的6形状
        }
        return nullptr; // 样子像两个6，各自独立，没有相交intersect
    }
}

Node *intersectLists(LinkList &myList1, LinkList &myList2)
{
    Node *loop1 = getLoopPoint(myList1);
    Node *loop2 = getLoopPoint(myList2);

    // 两个都不环，可能有相交
    if (loop1 == nullptr && loop2 == nullptr)
    {
        return intersectListsNoLoop(myList1, myList2);
    }
    // 两个都环，可能有相交
    if (loop1 != nullptr && loop2 != nullptr)
    {
        return intersectListsBothLoop(myList1, loop1, myList2, loop2);
    }
    // 一个不环，一个环，不可能有相交的情况
    return nullptr;
}

// 所有节点的父节点，都记录下来
void fatherMap(TNode *&node, std::unordered_map<TNode *, TNode *> &map) // 这个map入参必须是引用，否则对外面的map无效！！！
{
    if (node == nullptr)
    {
        return;
    }

    if (node->left != nullptr)
    {
        map[node->left] = node;
    }

    if (node->right != nullptr)
    {
        map[node->right] = node;
    }

    fatherMap(node->left, map);
    fatherMap(node->right, map);
}

TNode *lowestCommonAncestor(TNode *root, TNode *node1, TNode *node2)
{
    if (node1 == nullptr || node2 == nullptr)
    {
        return node1 != nullptr ? node1 : node2;
    }

    std::unordered_map<TNode *, TNode *> map; // fatherMap这里有个最大的坑，必须得传引用，不然从fatherMap函数出来后map是空的！！！
    fatherMap(root, map);                     // 除了根节点10，所有节点的父节点都对应好了，还有个空节点，父节点为150这个节点（最后一个节点）
    map[root] = root;                         // 根节点对应的还是根节点

    std::unordered_set<TNode *> set; // 把所有node1的祖辈节点都放在一个集合里面

    while (true)
    {
        set.insert(node1); // 把自己跟一条链上的祖辈都放到一个set中
        if (node1 == root) // 如果是根节点了，就退出
        {
            break;
        }
        node1 = map.find(node1)->second; // 让节点等于自己的父亲
    }

    while (true)
    {
        auto iterator = set.find(node2); // 在包含了node1和node1祖辈的set中，从node2自己开始找起,一次一次的找

        if (iterator != set.end()) // 找到了，则返回
        {
            return *iterator;
        }

        if (node2 == root) // 到了根节点了，还是没找到，返回空
        {
            return nullptr;
        }

        node2 = map.find(node2)->second; // 让节点等于自己的父亲
    }

    return nullptr;
}

// 需要自己打印出树图后，举例，两种情况，一个节点本身就是最低公共祖先，
// 一个是两个节点分别汇聚在一个相同的节点。分别跟踪，比较好理解
TNode *lowestCommonAncestorII(TNode *root, TNode *node1, TNode *node2)
{
    if (root == nullptr || root == node1 || root == node2)
    {
        return root; // 返回就三种情况，两个节点或者空
    }

    TNode *leftNode = lowestCommonAncestorII(root->left, node1, node2);
    TNode *rightNode = lowestCommonAncestorII(root->right, node1, node2);

    if (leftNode != nullptr && rightNode != nullptr)
    {
        return root; // 两个都不为空，只能是两个节点都找到了，那就返回他们共同的父节点就是结果
    }

    return leftNode != nullptr ? leftNode : rightNode;
}

// 折纸打印凹痕和凸痕，纸条折叠一次，中间凹，再对折一次，左凹，中间凹，右凸
// 所以，根是凹，孩子是左凹右凸，新折痕的两侧分别是左凹右凸
// 题目：将对折了N次后的凹凸痕迹图打印出来（从纸条的最左边开始打印）
// 把这些痕迹画成一颗二叉树，纸条从上到向的痕迹类型，正好是中序递归遍历，N是二叉树的深度，空间复杂度O(N)
// 否则申请一个 2^N-1 的空间，遍历一个个打印，空间复杂度就是O(2^N)，太大了
void paperFold(int N)
{
    printFold(1, N, false); // 假设false为0凹，true为1凸，第一次折叠，痕迹为0凹
}

void printFold(int i, int N, bool appear)
{
    if (i > N)
    {
        return;
    }

    printFold(i + 1, N, false); // 左0凹

    // 中间处理打印（中序遍历）
    std::cout << appear << " ";
    // 中间处理打印（中序遍历）

    printFold(i + 1, N, true); // 右1凸
}

bool CompareMeetings::operator()(const std::pair<int, int> &v1, const std::pair<int, int> &v2) const
{
    return v1.second < v2.second;
}

void endEarlyArrange(int timePoint, std::vector<std::pair<int, int>> &meetingVec)
{
    // 按照谁先结束进行排列
    std::sort(meetingVec.begin(), meetingVec.end(), CompareMeetings());

    int res = 0;
    // 遍历所有的会议
    for (const auto &i : meetingVec)
    {
        if (timePoint <= i.first)
        {
            res++;                // 会议的场次计数
            timePoint = i.second; // 更新时间点
            std::cout << i.first << "----" << i.second << "\n";
        }
    }
    std::cout << "total " << res << " meetings\n";
}

/**
 * 1---6,8------
 * 2---6,12-----
 * 3---7,16-----
 * 4---14,18-----
 * 5---10,20-----
 * 6---19,30----
 */
void meetingsArrage()
{
    std::vector<std::pair<int, int>> timeTable;
    int timePoint = 6;
    timeTable.push_back({19, 30});
    timeTable.push_back({10, 20});
    timeTable.push_back({6, 12});
    timeTable.push_back({14, 18});
    timeTable.push_back({6, 8});
    timeTable.push_back({7, 16});
    endEarlyArrange(timePoint, timeTable);
}

// 贪心策略！！！！！得需要证明是有效的贪心策略，但是笔试时，没有时间去证明，需要平时提炼对数器，进行对比，得出该贪心算法是正确的结论，包括ACM竞赛，同样如此
// 最小字典序，只有a.b<b.a，此时的a放前面，b放后面才是正确的最小字典序的排列方式，如果直接比较a<b，就让a放在前面b放在后面，这样的序列不一定是最小字典序
// 该排序策略具有传递性，就是需要证明a.b<<b.a, b.c<<c.b --> a.c<<c.a,点代表两个字符串拼接在一起的意思
// "abc"+"de" == "adc"*k^2 + "de"， k进制的平方表示左移两位，如k=26，表示英文字母，这样拼接运算变成了数学运算
bool CompareStrings::operator()(const std::string &str1, const std::string &str2) const
{
    return (str1 + str2).compare(str2 + str1) < 0; // compare会返回负数，0或者正数，而CompareStrings要求返回bool，所以需要加上 后面的<0才可以
}

void lowString(std::vector<std::string> &stringVec)
{
    std::sort(stringVec.begin(), stringVec.end(), CompareStrings());
}

void stringSort()
{
    std::vector<std::string> stringVec1;
    std::vector<std::string> stringVec2;

    stringVec1 = {"jibw", "ji", "jp", "bw", "jibw"};
    // stringVec1 = {"b", "d", "a", "c"};
    stringVec2 = {"ba", "b"};
    // stringVec2 = {"bba", "bab"};

    lowString(stringVec1);
    lowString(stringVec2);

    std::string str1 = "";
    std::string str2 = "";

    for (const auto &i : stringVec1)
    {
        str1 += i;
    }

    for (const auto &i : stringVec2)
    {
        str2 += i;
    }

    std::cout << str1 << "\n";
    std::cout << str2 << "\n";
}

// 分割黄金的最小成本问题，即霍夫曼编码
int lessMoneySplit()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> haffoman; // 使用小根堆，greater是小根堆，less才是大根堆
    int res = 0;

    haffoman.push(30);
    haffoman.push(20);
    haffoman.push(10);

    while (haffoman.size() > 1)
    {
        int a = haffoman.top(); // 每次弹出两个最小的值，求和，再将此和加入小根堆
        haffoman.pop();

        int b = haffoman.top();
        haffoman.pop();

        int c = a + b;
        res += c;

        haffoman.push(c);
    }

    return res;
}

bool CompareCapital::operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) const
{
    return p1.first > p2.first; // min_heap 小根堆,比较第一个参数（投资成本）
}

bool CompareProfit::operator()(const std::pair<int, int> &p1, const std::pair<int, int> &p2) const
{
    return p1.second < p2.second; // max_heap 大根堆，比较第二个参数（利润）
}

/**
 * 可以投资的轮数给定，启动资金给定，项目有很多个，每个都包括成本和收益，最终可获得的最大收入是多少
 * 贪心策略，暴力法找到所有的投资可能，然后对比自己的贪心策略是否正确饿
 */
int maxCapitalised()
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareCapital> projectQueue;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareProfit> profitQueue;
    int k = 4; // 可以投资的轮数
    int w = 1; // 启动资金

    // 项目按照投资成本从小到大，放在小根堆中
    projectQueue.push({1, 1});
    projectQueue.push({4, 10});
    projectQueue.push({2, 3});
    projectQueue.push({1, 2});
    projectQueue.push({3, 2});
    projectQueue.push({2, 7});

    // 有几轮的投资机会
    for (int i = 0; i < k; i++)
    {
        // 把能投资的所有项目都放在从大到小的利润大根堆中
        while (!projectQueue.empty() && projectQueue.top().first <= w)
        {
            profitQueue.push(projectQueue.top());
            projectQueue.pop();
        }

        // 此次能投的项目中，找出利润最大的投资
        if (!profitQueue.empty())
        {
            w += profitQueue.top().second; // 利润加到投资资金中，此次投资完成
            profitQueue.pop();             // 将已投资的项目删除
        }
    }

    return w; // 返回最大的收入是多少
};

double findMediumNumber()
{
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    std::queue<int> arrayNum;
    arrayNum.push(0);
    arrayNum.push(9);
    arrayNum.push(17);
    arrayNum.push(7);

    int num = arrayNum.front();
    arrayNum.pop();

    maxHeap.push(num);
    while (!arrayNum.empty())
    {
        num = arrayNum.front();
        arrayNum.pop();

        if (num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        int s1 = maxHeap.size();
        int s2 = minHeap.size();
        if (s1 - s2 >= 2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (s2 - s1 >= 2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double res;
    if (maxHeap.size() != minHeap.size())
    {
        std::cout << "豆子，你的计算结果是啥？我是计算机，我的结果是：" << (res = (maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top())) << "\n";
    }
    else
    {
        std::cout << "子，你的计算结果是啥？我是计算机，我的结果是：" << (res = ((maxHeap.top() + minHeap.top()) / 2.0)) << "\n";
    }

    return res;
}

// n不要超过32，递归或者非递归非常耗时，
// n=8,92个摆法，耗时0.001869s
// n=10,724个摆法，耗时0.020427s
// n=12,14200个摆法，耗时0.607357s
// n=13,73712个摆法，耗时3.06196ss
// n=14,365596个摆法，耗时19.9257s，bits方法：365596，耗时2.36875s
// n=15,2279184个摆法，耗时
// n=16,14772512个摆法，耗时好久，bits方法：14772512，耗时14.8916s
void NQueens(int n)
{
    if (n < 1 || n > 32)
    {
        return;
    }

    std::vector<int> record(n, -1); // Initialize record with n elements，all set to -1

    clock_t start = clock();

    int res = process(0, record, n);

    clock_t end = clock();

    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << n << "-Queens puzzle total: " << res << "\n";
    std::cout << "Elapsed time: " << elapsed_time << "s\n";
}

// 当前的行row和列colomn与前面的一一检查
bool isValid(const std::vector<int> &record, int row, int colomn)
{
    for (int i = 0; i < row; i++) // 之前所有的行都检测一下
    {
        // 列不能跟之前的重合coincide，以及对角线也不行coincide
        if (colomn == record[i] || std::abs(row - i) == std::abs(colomn - record[i]))
        {
            return false;
        }
    }
    return true;
}

int process(int i, std::vector<int> &record, int n)
{
    if (i == n)
    {
        // 需要再打开，比较耗时
        // std::cout << "find one solution: < ";

        // for (const auto &i : record)
        // {
        //     std::cout << i + 1 << " "; // 原始比较是从0开始，这里输出为了好看，变成从1开始
        // }

        // std::cout << ">\n";

        return 1; // 如果到这里了，说明找到了一种摆放方法
    }

    int res = 0;

    for (int j = 0; j < n; j++)
    {
        if (isValid(record, i, j))
        {
            record[i] = j;
            res += process(i + 1, record, n);
        }
    }

    return res;
}

void NQueenII(int n)
{
    if (n < 1 || n > 32)
    {
        return;
    }

    int limit = n == 32 ? -1 : (1 << n) - 1; // 这个括号一定得加上，不然就先做减法了

    clock_t start = clock();

    int res = NQueenIIProcess(limit, 0, 0, 0);

    clock_t end = clock();

    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << n << "-Queens puzzle total(bits): " << res << "\n";
    std::cout << "Elapsed time(bits): " << elapsed_time << "s\n";
}

int NQueenIIProcess(int limit, int c, int l, int r) // colomn限制，左对角线限制，右对角线限制
{
    if (c == limit) // base case
    {
        return 1; // 如果到这里了，说明找到了一种摆放方法
    }

    int pos = limit & (~(c | l | r)); // 本行所有可以放皇后的地方，（1是可以放，0是不可以放）
    int mostRightOne = 0;             // 某次可以放皇后的位置
    int res = 0;

    while (pos != 0)
    {
        mostRightOne = pos & (~pos + 1); // 每次取出最右边的1，即取出来一个当前可以放皇后的位置
        pos -= mostRightOne;             // 这次处理完毕，更新pos

        // 三个方向的约束全部加上mostRightOne，表示mostRightOne位置被标记已放置皇后，在后来的操作中将被禁用
        res += NQueenIIProcess(limit, (c | mostRightOne), (l | mostRightOne) << 1, (r | mostRightOne) >> 1);
    }

    return res;
}