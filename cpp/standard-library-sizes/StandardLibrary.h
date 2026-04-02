#pragma once

#include <array>
#include <memory>
#include <vector>
#include <string>
#include <span>
#include <optional>

template <typename T>
class StandardLibrary {
public:
    /*
     *  Usually 32 bytes.
     *  String consists of 4x 8 bytes that are stored on STACK (manager of HEAP memory):
     *  - 8 byte pointer to the HEAP string data (points to 0 if on STACK).
     *  - 8 byte current string's size.
     *  - 8 byte allocated size of the string (maximum ever allocated).
     *  - 8 byte buffer/SSO for stack allocation of the string.
     */
    std::string str{};

    /*
     *  Usually 24 bytes.
     *  Vector consists of 3x 8 bytes that are stored on STACK (manager of HEAP memory):
     *  - 8 byte pointer to the beginning of the HEAP contiguous memory.
     *  - 8 byte pointer to the end of the HEAP contiguous memory.
     *  - 8 byte pointer of the "capacity" (in the same context as in std::string).
     */
    std::vector<T> vec{};

    /*
     *  T * number of entries (in this case 16 bytes).
     *  Array consists of raw STACK data a.k.a. it's not a manager like a std::vector<T>.
     *  No pointer, just pure array entries and values on STACK.
     */
    std::array<T, 4> arr{};

    /*
     *  16 bytes on stack.
     *  String_view consists of 2x 8 bytes that are stored on STACK:
     *  - 8 byte pointer to the real string data (may be stored on .bss, heap or .global).
     *  - 8 byte size of the string.
     *
     *  Unlike std::string, it doesn't own the data, it just acts as a pointer to the real string.
     */
    std::string_view constStr{};


    /*
     *  16 bytes on stack.
     *  Shared_ptr consists of 2x 8 bytes stored on STACK:
     *  - 8 byte pointer to the data on HEAP.
     *  - 8 byte pointer to the amount of pointers that are looking at the data.
     */
    std::shared_ptr<T> sPtr{};

    /*
     *  16 bytes on stack.
     *  Span just consists of 2x 8 bytes stored on STACK:
     *  - 8 byte pointer pointing to the ANY contiguous memory.
     *  - 8 byte size of the contiguous memory.
     *
     *  Doesn't own anything as same as std::string_view.
     */
    std::span<T> anyCM{};

    /*
     *  8 bytes on stack.
     *  Unique_ptr just points anything like a regular T* (usually pointing to a heap object though).
     *  The difference is, it manages its memory so there are no memory leaks.
     *  - 8 byte pointer pointing to data.
     */
    std::unique_ptr<T> ptr{};

    /*
     *  T bytes + ( 1 byte + appropriate padding).
     *  Optional may hold two values, either T or std::nullopt_t.
     *  - T bytes holds the value of T.
     *  - 1 byte holds a flag telling if we are holding T or std::nullopt_t.
     *  - additional padding to ensure std::optional is a suitable size for the CPU handling.
     */
    std::optional<T> opt{};
};