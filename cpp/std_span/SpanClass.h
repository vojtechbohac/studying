#pragma once
#include <span>

/*
 *  Today, I learnt std::span available inside the C++20.
 *  std::span accepts any contiguous memory such as std::array or std::vector.
 *  It doesn't care where it gets the data from.
 *
 *  This is exceptionally great when we want to edit both an std::array and std::vector,
 *  as we can do it inside one single function while not making a copy at all.
 */
template <typename T>
class SpanClass {
public:
    std::span<T> array;

    // Constructor.
    explicit SpanClass(std::span<T> anyArray) noexcept : array(anyArray) {}

    /*
     *  Accepts a const unsigned QWORD and returns a const reference (the value).
     *  It could've been way easier, but since I'm also passing a std::string
     *  inside the main.cpp, returning a read-only reference is the best bet in here.
     */
    const T& getElement(const std::size_t element) const {
        return array[element];
    }

    /*
     *  Accepts a const unsigned QWORD and const underlying data.
     *  It could've been way easier, but since I'm also passing a std::string
     *  inside the main.cpp, returning a read-only reference is the best bet in here.
     */
    std::span<T> editMemory(const std::size_t element, const T& memory) {
        array[element] = memory;
        return array;
    }
};