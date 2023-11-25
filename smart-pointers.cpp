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

// This is an example function expanding on the one in lifetime.cpp
std::shared_ptr<int> CreateArray() // Read the main function to see how this is used
{
    std::shared_ptr<int> array = std::make_shared<int>(50);
    array.get()[1] = 2;
    return array; // The array won't be deleted now because of the shared pointer
                  // but it will also be deleted when the last shared pointer to it goes out of scope
}

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
    // Usually used for checking if an object is still alive without actually keeping it alive
    {
        std::weak_ptr<Robot> bumblebee;
        {
            std::shared_ptr<Robot> bumblebeePrime = std::make_shared<Robot>("Bumblebee Prime");
            bumblebee = bumblebeePrime;
        } // bumblebeePrime is deleted, meaning bumblebee is now expired

        if (bumblebee.expired()) // We can check if the object is expired
            std::cout << "Bumblebee is expired!" << std::endl;
        else
            std::cout << "Bumblebee is not expired!" << std::endl;
    }

    // In practice, we would use shared pointers like this:
    std::weak_ptr<int> weakArray; // We want to check if the array is deleted without keeping it alive
    {
        std::shared_ptr<int> sharedArray = CreateArray(); // This is how we would use the function above
                                                          // The array won't be deleted now because of the shared pointer
        std::cout << sharedArray.get()[1] << std::endl;   // We can access the array like normal

        weakArray = sharedArray; // Now, the array will be deleted when sharedArray goes out of scope
    }
    std::cout << (weakArray.expired() ? "Shared array is expired!" : "Shared array isn't expired!") << std::endl;
}