#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> values = {7, 1, 2, 5, 7, 9, 8, 40, 1};
    std::sort(values.begin(), values.end(), [](int a, int b)
              { return a < b; }); // Return true if order is correct

    for (int value : values)
        std::cout << value << ", ";
    std::cout << std::endl;
}