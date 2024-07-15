#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <stack>

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

public:
    LinkList();
    void InsertFrontData(int data);
    void PrintList();
    void InsertBackData(int data);
    void ReverseListI();
    void ReverseListII();
    Node *getHead();
    void setHead(Node *&head);
    void DeleteFront();
    void DeleteBack();
    void DeleteData(int data);
};