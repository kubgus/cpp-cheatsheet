#include <iostream>

struct Entity
{
    virtual void Print()
    {
        std::cout << "Entity" << std::endl;
    }
};

class Player : public Entity // class has private inheritance by default
{
public:
    void Print() override
    {
        std::cout << m_Name << std::endl;
    }

private:
    int m_Name;
};

class Interface
{
public:
    virtual void Print() = 0; // pure virtual function
                              // makes the class abstract
                              // must be overridden by derived classes
};

class Implement : public Interface
{
public:
    void Print() override
    {
        std::cout << "Hello, World!" << std::endl;
    }
};

int main() {}