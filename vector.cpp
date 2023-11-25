// https://www.youtube.com/watch?v=PocJ5jXv8No&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=46&ab_channel=TheCherno

// this file will be used later for expanding on the concept of vectors
// and creating a custom vector class

#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
};

void Function(const std::vector<Vertex> &vertices) {} // passing by reference to avoid copying

std::ostream &operator<<(std::ostream &stream, const Vertex &vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    for (Vertex &v : vertices)
        std::cout << v << std::endl;

    vertices.erase(vertices.begin() + 1); // removes element at index 1

    for (Vertex &v : vertices)
        std::cout << v << std::endl;

    vertices.clear(); // removes all elements
}