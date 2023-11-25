#include <iostream>

struct Robot
{
    const char *name;
    Robot(const char *name) : name(name) { std::cout << "Starting up " << this->name << "!" << std::endl; }
    ~Robot() { std::cout << "Shutting down " << name << "!" << std::endl; }
};

// Curly braces create a new scope
// When the scope ends, the object is destroyed
int main()
{
    Robot r2d2("R2-D2");

    {
        Robot optimus("Optimus");
    }

    Robot bumblebee("Bumblebee");
}

// This is important because of a common mistake in C++. Consider this snippet:
// int *CreateArray()
// {
//     int array[50];
//     return array;
// }
// This function returns a pointer to an array of 50 integers
// However, the array is destroyed when the function ends
// This means that the pointer is now pointing to garbage memory
// This is called a dangling pointer
// See arrays.cpp and smart-pointers.cpp for more information