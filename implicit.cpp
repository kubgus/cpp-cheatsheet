struct Vector2
{
    int x, y;
    // constructors are implicit by default
    Vector2(int x, int y) : x(x), y(y) {}
    explicit Vector2(int xy) : x(xy), y(xy)
    {
        // the explicit keyword prevents implicit conversions
    }
    Vector2() : x(0), y(0) {}
    // note: constructors in this struct are not necessary,
    // but they are here to demonstrate the explicit keyword
};

int main()
{
    Vector2 v1 = {1, 2}; // implicit constructor
                         // equivalent to Vector2 v1(1, 2);
    /*Vector2 v2 = 3;*/  // implicit constructor
                         // equivalent to Vector2 v2 = Vector2(3);
                         // we can't do this because of the explicit keyword

    Vector2 v3 = Vector2(3); // explicit constructor
    Vector2 v4(3);           // explicit constructor
    Vector2 v5 = (Vector2)3; // explicit constructor
    Vector2 v6;              // default constructor
}