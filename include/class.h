#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Hero
{
friend std::ostream& operator<<(std::ostream& out, Hero& obj);

public : 
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
            std::cout << "illegal index" << std::endl;
        }
    }

private:
    T *p;
    int size;
    int capacity;
};
