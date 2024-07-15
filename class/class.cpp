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

    while (cur != nullptr) // 压栈
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
    head = ReverseRecursivelyList(head);
}

// 链表反转，递归方法
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