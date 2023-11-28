// https://www.youtube.com/watch?v=mWgmBBz0y8c&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=59&ab_channel=TheCherno
// https://en.cppreference.com/w/cpp/language/lambda

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void ForEach(std::vector<int> &values, const std::function<void(int &)> &func)
{
    for (int &value : values)
        func(value);
}

void Increment(int &value)
{
    value++;
}

int main()
{
    std::vector<int> values = {1, 2, 3, 4, 5};

    // uses a function pointer
    ForEach(values, Increment);

    int a = 5; // we'll use this as an example of a capture
    auto lambda = [a](int &value)
    { value += a; };

    // uses a lambda expression (anonymous function)
    ForEach(values, lambda);
    ForEach(values, [](int &value)
            { std::cout << value << std::endl; });

    auto it = std::find_if(values.begin(), values.end(), [](int value)
                           { return value > 8; });
    std::cout << *it << " " << it[1] << std::endl;
}