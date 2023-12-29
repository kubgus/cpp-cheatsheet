// troubleshooting: use -pthread flag when compiling

#include <iostream>
#include <thread>

static bool s_Finished = false;

void Work()
{
    using namespace std::literals::chrono_literals;

    while (!s_Finished)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(Work);

    std::cout << "Still running in main thread..." << std::endl;

    std::cin.get();
    s_Finished = true;

    worker.join(); // wait for thread to finish (basically await)

    std::cout << "Done!" << std::endl;
}