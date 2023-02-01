# Parenthesis Checker

A function that checks if the parentheses in an expression are organized correctly. The definition of a correct expression is as follows:

    Any expression that does not contain any parentheses is correct (in particular, an empty expression is correct).
    If X is a correct expression, then (X) is also a correct expression.
    If X is a correct expression, then [X] is also a correct expression.
    If X is a correct expression, then {X} is also a correct expression.
    If X and Y are correct expressions, then XY is a correct expression.
    There are no other correct expressions.

The solution uses std::stack from the STL and includes helper functions. The code is split into the following files:
```
    CMakeLists.txt
src:
    application.cpp
    solution.cpp
    solution.h
test:
    solution.cpp
```    
## Usage

Use the isCorrect function to check if an expression's parentheses are organized correctly. The function has the following prototype:
```
bool isCorrect(const char* expression)
```
Example:
```
const char* expression = "((abc){abc}(((def)))def)";
if (isCorrect(expression)) {
    std::cout << "Expression is correct!" << std::endl;
} else {
    std::cout << "Expression is incorrect." << std::endl;
}
```
###
To build the project:
```
mkdir build
cd build
cmake ..
cmake --build .
```
To run tests:
```
ctest
```
