#include <cstdint>

struct AlignedStruct {
    std::uint64_t qword_1 {1};
    std::uint64_t qword_2 {2};
    std::uint64_t qword_3 {3};
    std::uint64_t qword_4 {4};

    std::uint32_t dword_1 {5};
    std::uint32_t dword_2 {6};
    std::uint32_t dword_3 {7};
    std::uint32_t dword_4 {8};

    std::uint16_t word_1 {9};
    std::uint16_t word_2 {10};
    std::uint16_t word_3 {11};
    std::uint16_t word_4 {12};

    std::uint8_t byte_1 {13};
    std::uint8_t byte_2 {14};
    std::uint8_t byte_3 {15};
    std::uint8_t byte_4 {16};
    std::uint8_t byte_5 {17};
    std::uint8_t byte_6 {18};
    std::uint8_t byte_7 {19};
    std::uint8_t byte_8 {20};
};