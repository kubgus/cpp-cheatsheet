# C++ Cheatsheet 📜
A collection of C++ snippets that explain how the language works.

### Made possible by @TheCherno 🚀
Cherno makes programming tutorials focused on C++. The concepts explained in this repo reference his explanations from different videos.
- [Website](https://thecherno.com/)
- [YouTube Channel](https://www.youtube.com/@TheCherno)
- [C++ Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

### Contribution 🤝
Feel free to contribute your code or point out any issues. We're all human, mistakes in this code are inevitable, but unlikely.

## Built-in data types 🛠️
https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
| Data type          | Size     | Range (approx.)                               |
| :----------------: | :------: | --------------------------------------------- |
| `bool`               | 1 byte   | 0 and 1                                       |
| `char`               | 1 byte   | -127 to 127                                   |
| `unsigned char`      | 1 byte   | 0 to 255                                      |
| `short (int)`        | 2 bytes  | -32768 to 32767                               |
| `unsigned short`     | 2 bytes  | 0 to 65535                                    |
| `int`                | 4 bytes  | -2147483648 to 2147483647                     |
| `unsigned int`       | 4 bytes  | 0 to 4294967295                               |
| `long (int)`         | 8 bytes  | -9223372036854775808 to 9223372036854775807   |
| `unsigned long`      | 8 bytes  | 0 to 18446744073709551615                     |
| `long long`          | 8 bytes  | -(2^63) to (2^63)-1                           |
| `unsigned long long` | 8 bytes  | 0 to 18446744073709551615                     |
| `float`              | 4 bytes  | Floating point numbers                        |
| `double`             | 8 bytes  | Floating point numbers                        |
| `long double`        | 12 bytes | Floating point numbers                        |

## Operators 🧮
https://www.tutorialspoint.com/cplusplus/cpp_operators.htm
| Operator | Description |
| :------: | ----------- |
| `sizeof` | Returns the size of a variable |
| `&` | Returns the address of a variable |
| `*` | Pointer to a variable |
| `? :` | Conditional operator |
| `.` | Member operator |
| `->` | Member operator |
| `++` | Increments the value of a variable |
| `--` | Decrements the value of a variable |
| `+` | Adds two operands |
| `-` | Subtracts two operands |
| `*` | Multiplies two operands |
| `/` | Divides two operands |
| `%` | Modulus operator |
| `=` | Assigns values from right side operands to left side operand |
| `+=` | Adds right operand to the left operand and assign the result to left operand |
| `-=` | Subtracts right operand from the left operand and assign the result to left operand |
| `*=` | Multiplies right operand with the left operand and assign the result to left operand |
| `/=` | Divides left operand with the right operand and assign the result to left operand |
| `%=` | Takes modulus using two operands and assign the result to left operand |
| `==` | Checks if the values of two operands are equal or not. If yes, then the condition becomes true |
| `!=` | Checks if the values of two operands are equal or not. If the values are not equal, then the condition becomes true |
| `>` | Checks if the value of left operand is greater than the value of right operand. If yes, then the condition becomes true |
| `<` | Checks if the value of left operand is less than the value of right operand. If yes, then the condition becomes true |
| `>=` | Checks if the value of left operand is greater than or equal to the value of right operand. If yes, then the condition becomes true |
| `<=` | Checks if the value of left operand is less than or equal to the value of right operand. If yes, then the condition becomes true |
| `&&` | Called Logical AND operator. If both the operands are non-zero, then the condition becomes true |
| `||` | Called Logical OR Operator. If any of the two operands is non-zero, then the condition becomes true |
| `!` | Called Logical NOT Operator. Use to reverses the logical state of its operand. If a condition is true, then Logical NOT operator will make it false |

## Stack vs Heap 📚
https://www.youtube.com/watch?v=wJ1L2nSIV1s&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=54
|                      | Stack                              | Heap                                |
| :------------------: | ---------------------------------- | ----------------------------------- |
| Initialization       | `int a;`                           | `int* a = new int;`                 |
| Memory Allocation    | `int a[5];`                        | `int* a = new int[5];`              |
| Access               | `a = 2;`                           | `*a = 2;`                           |
| Deletion             | Automatically when out of scope    | `delete a;`                         |
| Size                 | Smaller                            | Larger                              |
| Stored               | Togetger in memory                 | Fragmented                          |
| Allocating           | Costs around 1 CPU instruction     | Costs a lot more                    |