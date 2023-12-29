// troubleshooting: use -pthread flag when compiling

#include <chrono>
#include <iostream>
#include <thread>

struct Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::microseconds duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
        duration = std::chrono::microseconds::zero();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        Print();
    }

    void Print()
    {
        std::cout << "Timer took " << duration.count() << "μs." << std::endl;
    }
};

void TimedFunction()
{
    Timer timer;

    for (int i = 0; i < 100; i++)
        std::cout << "Hello, timer!" << std::endl;
}

int main()
{
    TimedFunction();
}