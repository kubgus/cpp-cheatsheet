int main()
{
    int value = 5;

    int *pointer = &value;  // & is the address-of operator
    int &reference = value; // & is part of the type, not the operator

    *pointer = 6;  // * is the dereference operator
                   // value is now 6
    reference = 7; // no dereference operator needed
                   // value is now 7

    int *a, b;  // a is a pointer to an integer
                // b is an integer
    int *c, *d; // c and d are both pointers to integers
}