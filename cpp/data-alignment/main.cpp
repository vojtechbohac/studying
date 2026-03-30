#include <iostream>

#include "AlignedStruct.h"
#include "UnalignedStruct.h"

/*
 *  I created two structs using exactly the same amount of members and same types,
 *  BUT the structs have different sizes. Why? Because of padding.
 *
 *  AlignedStruct as its name states, is aligned whereas UnalignedStruct isn't.
 *  Due to Data Alignment and Hardware Prefetcher the next address, the compiler
 *  has to add padding which makes the UnalignedStruct bigger.
 *
 *  - AlignedStruct is 64 bytes big due to alignment. This one comes in 1 single cache line.
 *  - UnalignedStruct is 96 bytes big due to not being aligned. This one come in 2 cache lines.
 *
 *  Results can be verified in the main function.
 *
 */
int main() {
    constexpr AlignedStruct alignedStruct;
    constexpr UnalignedStruct unalignedStruct;

    std::cout << "AlignedStruct: " << sizeof(alignedStruct) << std::endl;
    std::cout << "UnalignedStruct: " << sizeof(unalignedStruct) << std::endl;
}