// The array in C++ is a very simple concept.
// However, many people use it without understanding how it works.

struct Struct
{
};

int main()
{
    // The array is basially a pointer to the first element
    int array[50]; // The most common way to create an array

    array[2] = 50; // This is the same as *(array + 2) = 50;
                   // When we use the [] operator, we move the pointer
                   // by the index multiplied by the size of the type

    int *ptr = array; // We can also create a pointer to the array
                      // This is the same as int *ptr = &array[0];

    ptr[2] = 50; // This is the same as *(ptr + 2) = 50;
                 // This is the same as *(array + 2) = 50;
                 // This is the same as array[2] = 50;

    // We can also create an array of structs or classes
    Struct structs[50];
    structs[48] = Struct();
    // ...

    int *another = new int[50]; // We can also create an array on the heap
    delete[] another;           // But we have to delete it with delete[]
    // See lifetime.cpp and smart-pointers.cpp to get a better understanding of this
}