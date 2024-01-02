class Base
{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}
};

class Another
{
public:
    Another() {}
    ~Another() {}
};

int main()
{
    double x = 5.5;
    double y = 5;

    double c = (int)x + y; // C style cast

    // C++ style casts (adds compile time checks)
    Derived *derived = new Derived();
    Base *static_casted = static_cast<Base *>(derived);                       // checks for type compatibility
    Another *dynamic_casted = dynamic_cast<Another *>(static_casted);         // returns null if cast fails
    Another *reinterpret_casted = reinterpret_cast<Another *>(static_casted); // does not check for type compatibility
                                                                              // basically type punning
    const int constant = 5;
    int *const_casted = const_cast<int *>(&constant); // removes constness
}