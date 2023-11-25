#include <iostream>
#include <string>

class Class
{
public:
    std::string name = "Class";
    mutable int counter = 0;

    void Print() const
    {
        std::cout << name << std::endl; // can't modify member variables in a const function
        counter++;                      // can modify mutable member variables in a const function
    }

    void SetName(const std::string &newName)
    {
        name = newName; // can modify member variables in a non-const function
                        // can't modify newName because it's a const reference
    }

    void ExtraPrint(const std::string &extra) const
    {
        // can't modify name because we're in a const function
        // can't modify extra because it's a const reference
        std::cout << name << extra << std::endl;
    }
};

int main()
{
    int value = 3;

    const int *a = &value;       // pointer to a constant integer
                                 // the value can't be changed through this pointer
    int *const b = &value;       // constant pointer to an integer
                                 // the pointer can't be changed to point to another integer
    int const *c = &value;       // same as const int *a
    const int *const d = &value; // constant pointer to a constant integer
                                 // the pointer can't be changed to point to another integer
                                 // the value can't be changed through this pointer
    const int &e = value;        // reference to a constant integer
                                 // the value can't be changed through this reference
    int const &f = value;        // same as const int &e
}