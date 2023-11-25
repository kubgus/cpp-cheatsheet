// https://www.youtube.com/watch?v=BvR1Pgzzr38&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=44&t=25s&ab_channel=TheCherno

#include <iostream>
#include <string.h>

struct Vector2
{
    int x, y;
};

struct NoCopy
{
    int value;
    // disable copy constructor
    // this prevents copying by value
    NoCopy(const NoCopy &other) = delete;
};

class String
{
public:
    String(const char *string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0; // null terminator at the end
        std::cout << "Created string!" << std::endl;
    }

    // deep copy constructor instead of default shallow copy constructor
    String(const String &other)
        : m_Size(other.m_Size)
    {
        // the reason we need to do this is because
        // the default copy constructor only copies the pointer
        // this means that both objects will point to the same data
        // if one object is destroyed, the other object will have a dangling pointer
        // if one object changes data, the other object will be affected
        // this would be called a shallow copy
        // we want to do a deep copy:
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        std::cout << "Copied string!" << std::endl;
    }

    ~String()
    {
        delete[] m_Buffer;
        std::cout << "Destroyed string!" << std::endl;
    }

    const char *GetValue() const
    {
        return m_Buffer;
    }

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

private:
    char *m_Buffer;
    unsigned int m_Size;
};

std::ostream &operator<<(std::ostream &stream, const String &other)
{
    stream << other.GetValue();
    return stream;
}

int main()
{
    { // copying
        int value = 3;
        int copy = value; // changing copy doesn't affect value
        Vector2 vector1 = {1, 2};
        Vector2 vector2 = vector1;
        vector2.x = 5; // changing vector2 doesn't affect vector1
                       // vector1.x is still 1
    }

    { // not copying (reference)
        int value = 3;
        int &reference = value; // reference is an alias for value
        Vector2 vector1 = {1, 2};
        Vector2 &vector2 = vector1; // vector2 is an alias for vector1
        vector2.x = 5;              // changing vector2 changes vector1
                                    // vector1.x is now 5
    }

    { // not copying (pointers)
        int value = 3;
        int *pointer = &value; // pointer points to address of value
        Vector2 vector1 = {1, 2};
        Vector2 *vector2 = &vector1; // vector2 points to address of vector1
        vector2->x = 5;              // changing vector2 changes vector1
                                     // vector1.x is now 5
    }

    String str1 = "Hello";
    String str2 = str1; // copy constructor
    str2[1] = 'a';      // change value of str2 to see if str1 is affected

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
}