// https://www.youtube.com/watch?v=jELbKhGkEi0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=68
// lesson: if a class has a possibility of being subclassed, always declare the destructor as virtual

#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base Constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base Destructor" << std::endl; } // important line
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived Constructor" << std::endl; }
    ~Derived() { std::cout << "Derived Destructor" << std::endl; }
};

int main()
{
    Base *base = new Base();
    delete base;
    // everything works as expected

    std::cout << std::endl;

    Derived *derived = new Derived();
    delete derived;
    // everything works as expected

    std::cout << std::endl;

    Base *poly = new Derived();
    delete poly;
    // if the base destructor is not marked as virtual
    // then the derived destructor will not be called
}