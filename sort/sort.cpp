#include "sort.h"

// 简单排序之冒泡排序，太慢
// 简单排序之选择排序，不稳定
// 简单排序之插入排序，样本小且基本有序时效率高，类似扑克牌的插入
// 稳定的排序
void bubbleSort(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// 不稳定的排序
void selectSort(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            minIndex = vec[minIndex] > vec[j] ? j : minIndex;
        }
        if (i != minIndex)
        {
            std::swap(vec[i], vec[minIndex]);
        }
    }
}

// 稳定的排序
void insertSort(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
    {
        return;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

/* 归并排序，本质是递归+merge，左边排好序，右边排好序，整体再合并，利用master公式计算时间复杂度(runtime complexity)*/
// master公式
// T(N) = a*T(N/b) + O(N^d)
// 1) log(b,a) > d 复杂度为O(N^log(b,a))
// 2) log(b,a) = d 复杂度为O(N^d * logN)
// 3) log(b,a) < d 复杂度为O(N^d)

// 归并排序，a=2，b=2，d=1，O(N*logN)
void mergeSort_merge(std::vector<int> &vec, int l, int m, int r) // merge的时间复杂度O(N) ---> d = 1
{
    //  ----------------------------------
    //  ^               ^^               ^
    //  |               ||               |
    //  l              m m+1             r
    //  left            right

    int left = l;
    int right = m + 1;
    std::vector<int> helpVector;

    while (left <= m && right <= r)
    {
        if (vec[left] <= vec[right]) // 一定是<=，因为合并排序算法是稳定的，有相同元素，前面的放前面，小和算法中，这里是只有<没有=
        {
            helpVector.push_back(vec[left++]);
        }
        else
        {
            helpVector.push_back(vec[right++]);
        }
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
}

void mergeSort_process(std::vector<int> &vec, int l, int r)
{
    // 判定边界
    if (l == r)
        return;

    // 分半，等号右边的括号需要加上
    int m = l + ((r - l) >> 1);

    // 左边排序
    mergeSort_process(vec, l, m);

    // 右边排序
    mergeSort_process(vec, m + 1, r);

    // 合并
    mergeSort_merge(vec, l, m, r);
}

void mergeSort(std::vector<int> &vec)
{
    int n = vec.size();

    if (n <= 1)
    {
        return;
    }
    mergeSort_process(vec, 0, n - 1);
}

// 系统自带的排序法
void systemSort(std::vector<int> &vec)
{
    std::sort(vec.begin(), vec.end(), std::less<int>());
}

// master公式
// T(N) = a*T(N/b) + O(N^d)
// 1) log(b,a) > d 复杂度为O(N^log(b,a))
// 2) log(b,a) = d 复杂度为O(N^d * logN)----归并排序，a=2，b=2，d=1，O(N*logN)
// 3) log(b,a) < d 复杂度为O(N^d)

// 经典快排和随机快排，差在一句话上： 准备partition的时候，是否会先随机挑选vector中的一个数作为参考数
// O(NlogN)---随机快排
// O(N^2)-----经典快排最差情况是O(N^2),因为参考值选的太偏(而好的参考值是数组中值的大小是中间的值),每次只搞定一个数字,比如有序的数组,每次选择最后一个数作为参考数,那么一轮下来只搞定这一个数
// 下一轮,还是选最右边的数,也是只搞定一个数,循环下去是个等差数列,所以是经典快速排序的最差情况就是O(N^2)
// 所以需要改进为随机快速排序,每次不是选择最后一个,而是整个数组中随机找一个,再进行partition的过程,从数学角度来看,随机找的整个参考值是个概率,有可能好,有可能坏
// 但平均值就是O(N*logN)
std::vector<int> quickSort_partition(std::vector<int> &vec, int l, int r)
{
    int cur = l;
    int less = l - 1;
    int more = r;

    while (cur < more)
    {
        if (vec[cur] < vec[r]) // vec[r]作为参考数对vector进行调整
        {
            std::swap(vec[cur], vec[++less]);
            cur++;
        }
        else if (vec[cur] > vec[r]) // vec[r]作为参考数一直没有动过，一直存放在more区域里的最后一个位置
        {
            std::swap(vec[cur], vec[--more]);
        }
        else
        {
            cur++;
        }
    }

    // 最后处理参考数，将其放在合适的位置（more的第一个元素），
    // 此轮调整结束时，参考数的整体位置确定了: 小于参考数的所有数都在参考数的左边，大于参考数的所有数都在参考数的右边
    std::swap(vec[more], vec[r]);

    std::vector<int> boundryVec{less, more + 1}; // 返回此次调整完毕后的less和more的边界，以便进行下一轮的partition

    return boundryVec;
}

void quickSort_process(std::vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int randNum = randomInt() % (r - l + 1); // 随机快排，体现在这两句话
        std::swap(vec[l + randNum], vec[r]);     // 随机快排，体现在这两句话

        std::vector<int> v = quickSort_partition(vec, l, r); // 经典快排从这里开始,中间的值已经排好,所以继续递归左边的整体和右边的整体
        quickSort_process(vec, l, v[0]);
        quickSort_process(vec, v[1], r);
    }
}

void quickSort(std::vector<int> &vec)
{
    int n = vec.size();
    if (n <= 1)
    {
        return;
    }
    quickSort_process(vec, 0, n - 1);
}

// vector中的最大数包含有几位数，如最大数是1324，包含有四位数，如果最大数是29，包含有二位数
int maxBit(std::vector<int> &vec)
{
    int max = maxRecursive(vec, 0, vec.size() - 1);
    int bit = 0;
    while (max != 0)
    {
        max = max / 10;
        bit++;
    }
    return bit;
}

// 获得一个整数的个位，十位，百位，千位等每位上的数字，0表示个位，1表示十位，2表示百位，3表示千位
int getDigit(int num, int bit)
{
    return num / powerRaise(10, bit) % 10;
}

// 基数排序
// 根据键值的每位数字来分配桶；
void radixSort(std::vector<int> &vec)
{
    int d = maxBit(vec);
    int len = vec.size();
    int *p = new int[len];

    for (int i = 0; i < d; i++) // 有几位数字，就需要出入几次bucket，个位，百位，千位等分别进行比较
    {
        int count[10] = {0};

        for (auto &item : vec) // 先统计vec中所有元素的个位数字所对应的数量
        {
            int k = getDigit(item, i);
            count[k]++;
        }

        for (int j = 1; j < 10; j++) // 桶中所代表的数字，在后续数组中所处的位置，未来入桶的位置
        {
            count[j] = count[j - 1] + count[j];
        }

        for (auto item = vec.rbegin(); item < vec.rend(); item++) // 逆序遍历，然后入桶p，入桶的过程就是排序的过程
        {
            int k = getDigit(*item, i);
            *(p + count[k] - 1) = *item;
            count[k]--;
        }
        vec.clear(); // 清空，不然push的时候是追加了
        for (int m = 0; m < len; m++)
        {
            vec.push_back(*(p + m)); // 出桶，进行下一轮的十位数的排序，此时，vec的内容已经被重新改写
        }
    }

    delete[] p;
    p = nullptr;
}

// 手写一个堆，并对其进行堆排序，系统虽然有现成的堆结构（如优先级队列），但是个黑盒，只有push（添加元素时就是堆化的过程），pop（堆化后的弹出都是最大或者最小值）的操作，
// 如果需要操作堆里面的某个节点，对其进行相关操作，就不方便了，所以得自己写堆
// 面试时经常让手写堆，系统提供的现成的堆结构，如优先级队列，priority_queue，在C++中的实现是大根堆，java中默认是小根堆

// 从某个位置开始heap up，大根堆
void bigRootHeapUp(std::vector<int> &vec, int index)
{
    while (index > 0) // 根节点前，就一直跟父节点比较，大，则交换，小则提前退出
    {
        if (vec[index] > vec[(index - 1) >> 1])
        {
            std::swap(vec[index], vec[(index - 1) >> 1]);
            index = (index - 1) >> 1; // 指针上移，继续循环
        }
        else
        {
            break;
        }
    }
}

// 从某个位置开始heap up，小根堆
void smallRootHeapUp(std::vector<int> &vec, int index)
{
    while (index > 0) // 根节点前，就一直跟父节点比较，小，则交换，大则提前退出
    {
        if (vec[index] < vec[(index - 1) >> 1])
        {
            std::swap(vec[index], vec[(index - 1) >> 1]);
            index = (index - 1) >> 1; // 指针上移，继续循环
        }
        else
        {
            break;
        }
    }
}

// 从某个位置开始heap down
void bigRootHeapDown(std::vector<int> &vec, int index)
{
    if (vec.size() == 0)
    {
        return;
    }

    int heapSize = vec.size() - 1;
    int p = index;

    int l = (p << 1) + 1;
    int r = (p << 1) + 2;

    while (l <= heapSize) // 有左孩子，没有左孩子就直接退出
    {
        int largeChild = (r <= heapSize && vec[r] > vec[l]) ? r : l; // 有右孩，且右孩大，给右孩的指针，
                                                                     // 否则没有右孩或者有右孩但小于左孩，则给左孩的指针
        if (vec[largeChild] > vec[p])                                // 最大孩跟父比，大，则跟父换
        {
            std::swap(vec[largeChild], vec[p]);
            p = largeChild; // 继续以孩的视角，继续下行堆化
            l = (p << 1) + 1;
            r = (p << 1) + 2;
        }
        else
        {
            break; // 孩都很小，则退出
        }
    }
}

// 从某个位置开始heap down
void smallRootHeapDown(std::vector<int> &vec, int index)
{
    if (vec.size() == 0)
    {
        return;
    }

    int heapSize = vec.size() - 1;
    int p = index;

    int l = (p << 1) + 1;
    int r = (p << 1) + 2;

    while (l <= heapSize) // 有左孩子，没有左孩子就直接退出
    {
        int smallChild = (r <= heapSize && vec[r] < vec[l]) ? r : l; // 有右孩，且右孩小，给右孩的指针，
                                                                     // 否则没有右孩或者有右孩但小于左孩，则给左孩的指针
        if (vec[smallChild] < vec[p])                                // 最大孩跟父比，大，则跟父换
        {
            std::swap(vec[smallChild], vec[p]);
            p = smallChild; // 继续以孩的视角，继续下行堆化
            l = (p << 1) + 1;
            r = (p << 1) + 2;
        }
        else
        {
            break; // 孩都很大，则退出
        }
    }
}

// heap sort，从大根堆的尾部弹出是大的数字
void bigRootHeapSort(std::vector<int> &vec)
{
    int n = vec.size();

    // 从0开始，逐个上堆化，最终变成大根堆O(NlogN)
    // for (int i = 0; i < n; i++)//O(N) 一共执行N次
    // {
    //     bigRootHeapUp(vec, i);//O(logN)每一次的时间复杂度，都是O(logN)
    // }

    // runtime complexity = O(N)，why？answer：
    // geometric sequence 等比数列
    // vec中一共有N个节点，其中，N/2个节点都是叶节点，所以无需堆化，但每个叶节点也算一次操作（就算进来看一眼），时间复杂度1
    // N/4是倒数第二层，这里的每个节点都需要一次下行堆化，每个节点堆化后，再下到叶节点看一眼，所以这一层每个节点时间复杂度是2
    // N/8是倒数第三层的数量，需要两次下行堆化再加看一眼，复杂度3。。。。
    // T(N)  =  N/2 * 1  +  N/4 * 2  +  N/8 * 3 ........，两边同时乘以2得到第二个式子
    // 第二个式子减去第一个式子，得到等比数列和，N+1-(1/2)^N，当N趋向无穷大时，结果是N，所以时间复杂度=O(N)
    for (int i = n - 1; i >= 0; i--) // 从最后一个节点开始往回分别作下堆化
    {
        bigRootHeapDown(vec, i); // O(N)，比上面更快一些，对一个无序数组进行堆化，使用此方式会更快。
    }

    int *p = new int[n];

    while (!vec.empty()) // O(N)
    {
        std::swap(vec[vec.size() - 1], vec[0]); // 此时vec已经是大根堆了，vec队首是最大值，把vec队首放到vec队尾

        *p++ = vec.back(); // vec队尾放入另外的新临时数组，大根堆的尾部弹出的是大数字
        vec.pop_back();    // 去掉vec的队尾

        bigRootHeapDown(vec, 0); // O(logN)，从头开始作，所以跟从尾（上面那个过程）开始作，不一样的时间复杂度// 对刚换新队首的vec，从头位置0重新下行堆化，结束后，vec又是一个大根堆
    }

    for (int i = 0; i < n; i++)
    {
        vec.push_back(*(--p));
    }

    delete[] p;
    p = nullptr;
}

// heap sort，从小根堆的尾部弹出是小的数字
void smallRootHeapSort(std::vector<int> &vec)
{
    int n = vec.size();

    // 从0开始，逐个上堆化，最终变成小根堆O(NlogN)
    // for (int i = 0; i < n; i++)//O(N) 一共执行N次
    // {
    //     smallRootHeapUp(vec, i);//O(logN)每一次的时间复杂度，都是O(logN)
    // }

    // runtime complexity = O(N)，why？answer：
    // geometric sequence 等比数列
    // vec中一共有N个节点，其中，N/2个节点都是叶节点，所以无需堆化，但每个叶节点也算一次操作（就算进来看一眼），时间复杂度1
    // N/4是倒数第二层，这里的每个节点都需要一次下行堆化，每个节点堆化后，再下到叶节点看一眼，所以这一层每个节点时间复杂度是2
    // N/8是倒数第三层的数量，需要两次下行堆化再加看一眼，复杂度3。。。。
    // T(N)  =  N/2 * 1  +  N/4 * 2  +  N/8 * 3 ........，两边同时乘以2得到第二个式子
    // 第二个式子减去第一个式子，得到等比数列和，N+1-(1/2)^N，当N趋向无穷大时，结果是N，所以时间复杂度=O(N)
    for (int i = n - 1; i >= 0; i--) // 从最后一个节点开始往回 分别作下堆化
    {
        smallRootHeapDown(vec, i); // O(N)，比上面更快一些，对一个无序数组进行堆化，使用此方式会更快。
    }

    int *p = new int[n];

    while (!vec.empty()) // O(N)
    {
        std::swap(vec[vec.size() - 1], vec[0]); // 此时vec已经是小根堆了，vec队首是最小值，把vec队首放到vec队尾

        *p++ = vec.back(); // vec队尾放入另外的新临时数组，小根堆的尾部弹出的是小数字
        vec.pop_back();    // 去掉vec的队尾

        smallRootHeapDown(vec, 0); // O(logN)，从头开始作，所以跟从尾（上面那个过程）开始作，不一样的时间复杂度// 对刚换新队首的vec，从头位置0重新下行堆化，结束后，vec又是一个小根堆
    }

    for (int i = 0; i < n; i++)
    {
        vec.push_back(*(--p));
    }

    std::reverse(vec.begin(), vec.end());

    delete[] p;
    p = nullptr;
}

// 对给定的一个vec作大堆化或小堆化
void rootHeapify(std::vector<int> &vec, bool flag)
{
    int n = vec.size();

    for (int i = n - 1; i >= 0; i--) // 从最后一个节点开始往回分别作下堆化
    {
        if (flag)
        {
            bigRootHeapDown(vec, i); // O(N)，比上面更快一些，对一个无序数组进行堆化，使用此方式会更快。
        }
        else
        {
            smallRootHeapDown(vec, i);
        }
    }
}