// https://www.youtube.com/watch?v=f3FVU-iwNuA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=21&ab_channel=TheCherno

static void Function()
{
    // if there was a function with the same name in another file
    // we would get a linker error
}

static int s_Variable = 5; // only accessible in this file
                           // linker won't look for it outside this file
extern int variable;       // this is the default behavior
                           // linker will look for it outside this file

struct Struct // the static keyword can also be used with structs and classes
{
    static int s_Variable; // only one instance of this variable
                           // shared by all instances of this class
                           // can be accessed with Struct::s_Variable
    static void Function()
    {
        // doesn't use the class instance
    }
};

int main()
{
    Struct::s_Variable = 2;
    Struct::Function();
}