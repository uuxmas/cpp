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
    return out;//返回out的引用，以便实现连续使用<<的操作。
}
