#include <iostream>
#include <memory>

#include "Operations.h"

int main() {
    std::string stringInput;
    std::int32_t intInput;

    // Basic character input/character output.
    std::cout << "Type a string: " << std::endl;
    std::cin >> stringInput;
    std::cout << "Type an int: " << std::endl;
    std::cin >> intInput;


    // Initializes Operations class to a local variable operations as a smart pointer for memory safety.
    const auto operations = std::make_unique<Operations>(std::move(stringInput), intInput);

    // Just a little safety check that std::move() worked inside Operations.h.
    if (stringInput.empty()) std::cout << "empty" << std::endl;

    // Grabs the members and outputs them.
    std::cout << operations->stringValue << " " << operations->intValue << std::endl;
}