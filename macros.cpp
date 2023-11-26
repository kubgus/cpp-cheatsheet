// https://www.youtube.com/watch?v=j3mYki1SrKE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=55

#include <iostream>

#define LOG(x) std::cout << x << std::endl
// before compiling, the preprocesser:
// replaces all instances of LOG with std::cout << x << std::endl
// replaces all instances of x inside LOG with the argument passed in

#define STR_HELLO "Hello!"
// this is horrendous never do something like this
// this is just an example to show how macros replace text

#if DEBUG == 1
#define EFFICIENT_LOG(x) std::cout << x << std::endl
#define ASSERT(x) \
    if (!(x))     \
        __debugbreak();
#else
#define EFFICIENT_LOG(x)
#define ASSERT(x)
#endif
// g++ -D DEBUG=1 macros.cpp -o macros
// this will define DEBUG as 1 before compiling

int main()
{
    LOG("Hello World!"); // this is the same as std::cout << "Hello World!" << std::endl;
    LOG(STR_HELLO);      // this is the same as std::cout << "Hello!" << std::endl;

    EFFICIENT_LOG("Debug message...");
}