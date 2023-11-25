#include <iostream>
#include <memory>

// Smart pointers allow allocation on the heap without having to manually delete the object
// They also allow us to keep track of the lifetime of the object
// They are essentially wrappers around raw pointers
// They are defined in the <memory> header

struct Robot
{
    const char *name;
    Robot(const char *name) : name(name) { std::cout << "Starting up " << this->name << "!" << std::endl; }
    ~Robot() { std::cout << "Shutting down " << name << "!" << std::endl; }
    void Print() { std::cout << "I am " << name << "!" << std::endl; }
};

int main()
{
    // A unique pointer is a smart pointer that automatically deletes the object when it goes out of scope
    // Can't be copied to prevent mistakes (see lifetime.cpp)
    {
        std::unique_ptr<Robot> r2d2 = std::make_unique<Robot>("R2-D2");
        // Note: "std::make_unique" is preferred over using new because it is exception-safe
        // But it essentially works the same way as "new"
        r2d2->Print(); // We can call methods on the pointer like normal
    }

    // A shared pointer is a smart pointer that automatically deletes the object
    // when the last shared pointer to it goes out of scope
    {
        std::shared_ptr<Robot> optimus;
        {
            std::shared_ptr<Robot> optimusPrime = std::make_shared<Robot>("Optimus Prime");
            // Don't use "new" with shared pointers

            optimus = optimusPrime; // Now, optimusPrime won't be deleted when it goes out of scope
                                    // because optimus is still pointing to it
        }
        optimus->Print(); // The optimusPrime variable was deleted, but the object still exists
    }

    // A weak pointer is a smart pointer that doesn't increase the reference count
    // We use it when we want to reference an object without keeping it alive
    {
        std::weak_ptr<Robot> bumblebee;
        {
            std::shared_ptr<Robot> bumblebeePrime = std::make_shared<Robot>("Bumblebee Prime");
            bumblebee = bumblebeePrime;
        } // bumblebeePrime is deleted, meaning bumblebee is now expired

        /*bumblebee->Print();*/ // This now won't work

        if (bumblebee.expired()) // We can check if the object is expired
            std::cout << "Bumblebee is expired!" << std::endl;
        else
            std::cout << "Bumblebee is not expired!" << std::endl;
    }
}