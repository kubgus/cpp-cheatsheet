#include <iostream>

struct Vector2
{
    int x, y;

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2{x + other.x, y + other.y};
    }

    Vector2 operator*(const Vector2 &other) const
    {
        return Vector2{x * other.x, y * other.y};
    }

    bool operator==(const Vector2 &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2 &other) const
    {
        return !(*this == other);
        // note: "this" is a pointer to the current object
    }

    // ...
};

class ScopedPtr
{
public:
    ScopedPtr(Vector2 *ptr) : m_Ptr(ptr) {}
    ~ScopedPtr() { delete m_Ptr; }
    Vector2 *operator->() { return m_Ptr; }             // makes code cleaner
    const Vector2 *operator->() const { return m_Ptr; } // const version

private:
    Vector2 *m_Ptr;
};

// operator overload
std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    Vector2 position = {1, 2};
    Vector2 speed = {2, 3};
    Vector2 powerup = {4, 5};

    Vector2 result1 = position + speed * powerup;
    Vector2 result2 = (position + speed) * powerup;

    if (result1 == result2)
    {
        // ...
    }

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    // operator overloading is very useful for smart pointers (see smart-pointers.cpp)
    ScopedPtr vector = new Vector2{1, 2};
    std::cout << vector->x << std::endl;
    // without operator overloading, this would be something like "vector.GetObject()->x"
}