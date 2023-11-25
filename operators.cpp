#include <iostream>

struct Vector2
{
    int x, y;
    Vector2(int x, int y) : x(x), y(y) {}

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator*(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
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

// operator overload
std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << ", " << other.y;
    return stream;
}

int main()
{
    Vector2 position(4, 4);
    Vector2 speed(2, 2);
    Vector2 powerup(1, 1);

    Vector2 result1 = position + speed * powerup;
    Vector2 result2 = (position + speed) * powerup;

    if (result1 == result2)
    {
        // ...
    }

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
}