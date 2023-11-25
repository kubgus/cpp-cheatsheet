#include <iostream>

struct Vector2
{
    int x, y;
    Vector2(int x, int y) : x(x), y(y) {}
    Vector2(int xy) : x(xy), y(xy) {}
    Vector2() : x(0), y(0) {}
};

int main()
{
    Vector2 v1 = {1, 2};
    Vector2 v2 = 3;
    Vector2 v3;
}