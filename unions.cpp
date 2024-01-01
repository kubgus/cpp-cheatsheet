// https://www.youtube.com/watch?v=6uqU9Y578n4&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=67

#include <iostream>

struct Position
{
    int x, y;
};

struct Entity
{
    // both members share the same memory
    // meaning that we can access x, y, as well as position
    union
    {
        struct
        {
            int x, y;
        };
        Position position;
    };
};

int main()
{
    Entity e = {1, 2};
    std::cout << e.x << ", " << e.y << std::endl;
    e.x = 2;
    e.position.y = 3;
    std::cout << e.position.x << ", " << e.position.y << std::endl;
}