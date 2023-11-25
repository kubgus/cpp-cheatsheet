// https://www.youtube.com/watch?v=PocJ5jXv8No&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=46&ab_channel=TheCherno
// https://www.youtube.com/watch?v=HcESuwmlHEY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=47&ab_channel=TheCherno

// this file will be used later for expanding on the concept of vectors
// and creating a custom vector class

#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
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
    vertices.reserve(3);            // reserves memory for 3 elements
                                    // this is different from passing 3 as an argument
                                    // to the constructor, which would create 3 elements
                                    // and initialize them with the default constructor
                                    // this is useful when we know how many elements we
                                    // will have in the vector, but we don't know what
                                    // values they will have
                                    // less copying and less memory allocation = faster code
    vertices.emplace_back(1, 2, 3); // adds an element to the end of the vector
                                    // this is the same as push_back, but it
                                    // is more efficient, because it doesn't
                                    // have to copy the element
    vertices.emplace_back(4, 5, 6);
    vertices.push_back({7, 8, 9}); // this is also correct, but it is less efficient
                                   // because it has to copy the element

    for (Vertex &v : vertices)
        std::cout << v << std::endl;

    vertices.erase(vertices.begin() + 1); // removes element at index 1

    for (Vertex &v : vertices)
        std::cout << v << std::endl;

    vertices.clear(); // removes all elements
}