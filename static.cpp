// https://www.youtube.com/watch?v=f3FVU-iwNuA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=21&ab_channel=TheCherno
// https://www.youtube.com/watch?v=f7mtWD9GdJ4&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=48&ab_channel=TheCherno

#include <iostream>

static void Function1()
{
    // if there was a function with the same name in another file
    // we would get a linker error
}

void Function2()
{
    static int i = 0; // a static variable is only initialized once
                      // and it is not destroyed when it goes out of scope
                      // it is only accessible in this function
                      // it is initialized when the program starts
                      // and destroyed when the program ends
                      // it is useful for caching values or counting how many
                      // times a function has been called
    i++;
    std::cout << i << std::endl;
}

class Singleton
{
public:
    int value = 0;

public:
    static Singleton &Get()
    {
        static Singleton instance;
        return instance;
    }
};

static int s_Variable = 5; // only accessible in this file
                           // the linker won't look for it outside this file
extern int variable;       // this is the default behavior
                           // linker will look for it outside this file

struct Struct // The static keyword can also be used with structs and classes
{
    inline static int s_Member; // only one instance of this variable
                                // shared by all instances of this class
                                // can be accessed with Struct::s_Member
    static void Method()
    {
        // doesn't use the class instance
    }
};

int main()
{
    Function2(); // prints 1
    Function2(); // prints 2
    Function2(); // prints 3

    // another great example of using static in a function
    Singleton::Get().value = 4;
    std::cout << Singleton::Get().value << std::endl;

    // note: "Struct::s_Member" would have to be defined before this if it wasn't declared inline (C++17)
    Struct::s_Member = 2;
    Struct::Method();
}