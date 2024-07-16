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

    int n = vec.size();

    for (int i = 0; i < n; i++)
    {
        auto iterator = map.find(target - vec[i]);          // HashMap(哈希表)'s find returns an iterator，which is a pointer，不等于map.end()，则表示找到了
        if (iterator != map.end() && iterator->second != i) // vector中同一个元素不能使用两遍，target=8，使用了两遍4
        {
            return std::vector<int>{iterator->second, i};
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

    const int MS = 10;
    const int MV = 10;

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

    while (p != nullptr) // 空间复杂度O(N)
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
    while ((h1 != slow) && (h1->data == h2->data))
    {
        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 != slow) // 说明有不相等的数据，提前跳出while循环
    {
        res = false;
    }

    // 恢复原来的链表
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