#pragma once

#include <string>
#include <utility>

/*
 *  Struct Members contains two members:
 *  - stringValue is a STRING that is better to be MOVED due to its size.
 *  - intValue is an INT that is better to be COPIED due to its size.
 *
 *  Members are also sorted (Data Alignment) even though they don't have to be due to only two members.
 *  For future class expansions, this alignment should be used to make it fit into as least cache lines as possible.
 */
struct Members {
    //Size: 32 bytes on my x86_64.
    std::string stringValue;
    //Size: 4 bytes on x86_64 systems.
    std::int32_t intValue;
};

/*
 * Class Operations inherits members from Members.
 */
class Operations : public Members {
public:
    /*
     *  This constructor handles these two arguments differently:
     *  - Since stringArg is a string which I want to MOVE instead of COPYING, I am passing an r-value and casting its
     *  type back to an r-value using std::move() to move it and not waste resources by making a copy. I am also taking
     *  its ownership (the original string will be nulled and pointer set to nullptr).
     *  - I decided to COPY intArg since its defined as a 4 byte integer, which isn't expensive for the system.
     */
    Operations(std::string&& stringArg, const std::int32_t intArg) noexcept : Members{std::move(stringArg), intArg} {}
};
