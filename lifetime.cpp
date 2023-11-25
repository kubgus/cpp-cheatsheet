#include <iostream>

struct Robot
{
    const char *name;
    Robot(const char *name) : name(name) { std::cout << "Starting up " << this->name << "!" << std::endl; }
    ~Robot() { std::cout << "Shutting down " << name << "!" << std::endl; }
};

// curly braces create a new scope
// when the scope ends, the object is destroyed
int main()
{
    Robot r2d2("R2-D2");

    {
        Robot optimus("Optimus");
    }

    Robot bumblebee("Bumblebee");
}

// this is important because of a common mistake in C++. Consider this snippet:
int *CreateArray1() // Causes warning
{
    int array[50];
    return array;
}
// this function returns a pointer to an array of 50 integers
// however, the array is destroyed when the function ends
// this means that the pointer is now pointing to garbage memory
// this is called a dangling pointer

// to fix this, we can use the "new" keyword:
int *CreateArray2()
{
    int *array = new int[50];
    return array;
}
// this works, but now we have to manually delete the array
// this is a common source of memory leaks

// this is where smart pointers come in handy (see smart-pointers.cpp)