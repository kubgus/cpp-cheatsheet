// note: don't overuse templates, it can (and will) make code hard to read

#include <iostream>

template <typename T> // this is a template declaration
void Print(T value)   // this is a template function
{
    std::cout << value << std::endl;
}

template <typename T, int N>
class Array
{
public:
    int GetSize() const { return N; }

private:
    T m_Array[N];
};

int main()
{
    Print<int>(5); // this is a template argument
    Print(5.5f);   // this is also a template argument
    Print("Hello, World!");

    Array<int, 11> array;
    std::cout << array.GetSize() << std::endl;
}