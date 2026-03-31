#include <iostream>
#include <array>
#include <vector>

#include "SpanClass.h"

int main() {
    // Stack initialization of std::array and std::vector.
    std::array<int, 5> intArray{4, 6, 3, 7, 9};
    std::vector<std::string> stringArray{"hello", "hi", "hello world"};

    // Stack initialization of classes.
    auto intSpan = SpanClass<int>(intArray);
    auto stringSpan = SpanClass<std::string>(stringArray);

    // Just lil testing
    std::cout << intSpan.getElement(2) << std::endl; // 3
    intSpan.editMemory(2, 10); // Changes 3 to 10.
    std::cout << intSpan.getElement(2) << std::endl; // 10

    std::cout << stringSpan.getElement(2) << std::endl; // hello world
    stringSpan.editMemory(2, "test"); // Changes hello world to test.
    std::cout << stringSpan.getElement(2) << std::endl; // test
}