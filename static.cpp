// https://www.youtube.com/watch?v=f3FVU-iwNuA&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=21&ab_channel=TheCherno

static void Function()
{
    // if there was a function with the same name in another file
    // we would get a linker error
}

static int s_Variable = 5; // only accessible in this file
                           // the linker won't look for it outside this file
extern int variable;       // this is the default behavior
                           // linker will look for it outside this file

struct Struct // The static keyword can also be used with structs and classes
{
    inline static int s_Member; // only one instance of this variable
                                // shared by all instances of this class
                                // can be accessed with Struct::s_Member
    static void Method()
    {
        // doesn't use the class instance
    }
};

int main()
{
    // note: "Struct::s_Member" would have to be defined before this if it wasn't declared inline (C++17)
    Struct::s_Member = 2;
    Struct::Method();
}