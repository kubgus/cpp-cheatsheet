struct Vector2
{
    int x, y;
    // Constructors are implicit by default
    Vector2(int x, int y) : x(x), y(y) {}
    explicit Vector2(int xy) : x(xy), y(xy)
    {
        // The explicit keyword prevents implicit conversions
    }
    Vector2() : x(0), y(0) {}
};

int main()
{
    Vector2 v1 = {1, 2}; // Implicit constructor
                         // Equivalent to Vector2 v1(1, 2);
    /*Vector2 v2 = 3;*/  // Implicit constructor
                         // Equivalent to Vector2 v2 = Vector2(3);
                         // We can't do this because of the explicit keyword

    Vector2 v3 = Vector2(3); // Explicit constructor
    Vector2 v4(3);           // Explicit constructor
    Vector2 v5 = (Vector2)3; // Explicit constructor
    Vector2 v6;              // Default constructor
}