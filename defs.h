#ifndef DEFS_H
#define DEFS_H

// Compile settings

// #define NDEBUG // Disables assert() if defined.
// #define WIN32 // Uncomment if compiling for Windows.
// #define VERBOSE // Enables more output.

#include <string> // std::string
#include <sstream> // std::stringstream
#include <assert.h> // std::assert()

// Macros

#define INFINITY_C 50000
#define MAX_DEPTH 64
#define IS_MATE 49936

// Enumerations

enum { BLACK, WHITE };




const int FLIPV[64] = {
56  ,   57  ,   58  ,   59  ,   60  ,   61  ,   62  ,   63  ,
48  ,   49  ,   50  ,   51  ,   52  ,   53  ,   54  ,   55  ,
40  ,   41  ,   42  ,   43  ,   44  ,   45  ,   46  ,   47  ,
32  ,   33  ,   34  ,   35  ,   36  ,   37  ,   38  ,   39  ,
24  ,   25  ,   26  ,   27  ,   28  ,   29  ,   30  ,   31  ,
16  ,   17  ,   18  ,   19  ,   20  ,   21  ,   22  ,   23  ,
8   ,   9   ,   10  ,   11  ,   12  ,   13  ,   14  ,   15  ,
0   ,   1   ,   2   ,   3   ,   4   ,   5   ,   6   ,   7
};

// Bit manipulation helper functions

/**
    @brief Generates a bitboard out of the given index.

    This function currently uses bitshifting. It may be later changed to
    utilise lookup tables, if they are found to be faster.
    Refer: http://stackoverflow.com/questions/33703233/

    @param index is the integer index of the bit to set.

    @return uint64_t board with one bit indexed by 'index' set.

    @warning 'index' must be between (or equal to) 0 and 63.
*/

inline uint64_t GET_BB(unsigned int index)
{
    assert(index < 64);

    return 1ULL << index;
}

/**
    @brief Sets the bit on the given index on the given bitboard.

    @param bb is the bitboard to set the bit on.
    @param index is the integer index denoting which bit to set.

    @return void.

    @warning 'index' must be between (or equal to) 0 and 63.
*/

inline void SET_BIT(uint64_t& bb, unsigned int index)
{
    assert(index < 64);

    bb |= GET_BB(index);
}

/**
    @brief Clears the bit on the given index on the given bitboard.

    @param bb is the bitboard to clear the bit on.
    @param index is the integer index denoting which bit to clear.

    @return void.

    @warning 'index' must be between (or equal to) 0 and 63.
*/

inline void CLR_BIT(uint64_t& bb, unsigned int index)
{
    assert(index < 64);

    bb &= ~(GET_BB(index));
}

/**
    @brief Returns the number of set bits in the given integer.

    Uses __builtin_popcountll() to count the number of bits.

    @param bb is the integer (bitboard) in which to count the number of bits.

    @return unsigned int value denoting the number of set bits in 'bb'.
*/

inline unsigned int CNT_BITS(const uint64_t& bb)
{
    if (bb != 0ULL) return __builtin_popcountll(bb);
    else return 0;
}

/**
    @brief Pops the least significant bit in the given integer and returns its
           index.

    Uses __builtin_ffsll() to get the index of the least significant bit.

    @param bb is the non-zero integer (bitboard) to pop the bit from.

    @return unsigned int value denoting the index where the bit existed.

    @warning 'bb' must be a non-zero integer. Otherwise, its value will be
             corrupted and the returned index will overflow, being equal
             to the maximum unsigned 32-bit integer.
*/

inline unsigned int POP_BIT(uint64_t& bb)
{
    assert(bb != 0ULL);

    unsigned int index = __builtin_ffsll(bb) - 1;
    bb ^= GET_BB(index);
    return index;
}

#endif // DEFS_H
