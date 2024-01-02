// https://www.youtube.com/watch?v=8egZ_5GA9Bc&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=66

#include <iostream>

struct Entity
{
    int x, y;
};

int main()
{
    Entity e = {5, 8};
    int *position = (int *)&e;
    std::cout << position[0] << ", " << position[1] << std::endl;

    int *reinterpreted_position = reinterpret_cast<int *>(&e); // same as above, but using C++ casting
    std::cout << reinterpreted_position[0] << ", " << reinterpreted_position[1] << std::endl;
}