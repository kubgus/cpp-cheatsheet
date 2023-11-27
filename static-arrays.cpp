// https://www.youtube.com/watch?v=Hw42GkHPyvk&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=57

#include <iostream>
#include <array>

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &stream, const std::array<T, N> &array)
{
    stream << "[";
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            stream << ", ";
        stream << array[i];
    }
    stream << "]";
    return stream;
}

int main()
{
    std::array<int, 3> data;
    data[0] = 2; // data.at(0) = 2;
    data[1] = 5;
    data[2] = 7;
    /*data[3] = 9;*/ // automatic bounds checking in debug mode
                     // in release mode, no bounds checking
                     // = no performance cost

    std::cout << data.size() << std::endl; // size is known at compile time
                                           // = no performance cost
    std::cout << data << std::endl;
}