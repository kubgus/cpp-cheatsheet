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
    const char *m_Name = "Player";
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

int main()
{

    Entity e;
    e.Print();

    Player p;
    p.Print();

    /*Interface i; // can't instantiate abstract class
    i.Print();*/
    // can't call pure virtual function

    Implement impl; // can instantiate derived class
    impl.Print();   // can call overridden function
}