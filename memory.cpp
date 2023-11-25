#include <iostream>

struct Vertex
{
    float x, y, z;
    Vertex() : x(0), y(0), z(0) {}
};

int main()
{
    // allocating memory on the stack
    int value = 5;
    int array[5];
    Vertex vertex;

    // allocating memory on the heap (malloc)
    int *hvalue = new int;
    *hvalue = 5;
    int *harray = new int[5];
    Vertex *hvertex = new Vertex;
}