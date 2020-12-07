#include "movegen.h"
#include <stdint.h>
#include <iostream>
#include "lookup_tables.h"
#include "defs.h"
#include "print.h"
using namespace std;

void gen_side_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb, const uint64_t lookup[])
{
    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.

    unsigned int uint_1, uint_2, uint_3 , uint_4; // Temporary variables.
    uint64_t u64_2, u64_3; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);

        u64_2 = lookup[uint_1] & OCC;  // occupied fields on the way
        u64_3 = u64_2;
        u64_2 ^= lookup[uint_1]; // just free moves

        if(gen_side == WHITE)
            u64_3 &= black_bb; //only actual captures
        else
            u64_3 &= white_bb;

        uint_2 = CNT_BITS(u64_2);
        uint_3 = CNT_BITS(u64_3);

        for(unsigned int i = 0; i < uint_2; i++)
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }
        for(unsigned int i = 0; i < uint_3; i++)
        {
            std::cout << uint_1 << " ->X " << POP_BIT(u64_3) << std::endl;
        }

    }
}

void gen_side_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb, const uint64_t lookup[])
{
    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.
    unsigned int uint_1, uint_2, uint_3 , uint_4; // Temporary variables.
    uint64_t u64_2, u64_3, u64_4,u64_5; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);

        u64_2 = lookup[uint_1] & OCC;  // occupied fields on the way
        u64_3 = 0x0ULL;
        u64_4 = u64_2;
        for (unsigned int j = 0; j < CNT_BITS(u64_2); j++)
        {
            uint_4 = POP_BIT(u64_4);
            u64_3 |= lookup[uint_4];  // not possible moves

        }
        u64_4 = lookup[uint_1] ^ (lookup[uint_1] & u64_3); // possible moves including optional capture

        u64_3 = u64_4 & u64_2; // just optional capture

        u64_4 ^= u64_3; // just free moves

        if(gen_side == WHITE)
            u64_3 &= black_bb; //only actual capture
        else
            u64_3 &= white_bb;

        uint_2 = CNT_BITS(u64_4);

        for(unsigned int i = 0; i < uint_2; i++)
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_4) << std::endl;

        }
        if(CNT_BITS(u64_3))
            std::cout << uint_1 << " ->X " << POP_BIT(u64_3) << std::endl;

    }
}
void gen_west_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_moves(u64_1, gen_side, white_bb, black_bb, HEX_W_LT);
}
void gen_east_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_moves(u64_1, gen_side, white_bb, black_bb, HEX_E_LT);
}
void gen_north_east_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_moves(u64_1, gen_side, white_bb, black_bb, HEX_NE_LT);
}
void gen_north_west_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_moves(u64_1, gen_side, white_bb, black_bb, HEX_NW_LT);
}
void gen_south_east_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_moves(u64_1, gen_side, white_bb, black_bb, HEX_SE_LT);
}
void gen_south_west_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_moves(u64_1, gen_side, white_bb, black_bb, HEX_SW_LT);
}

void gen_west_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_jumps(u64_1, gen_side, white_bb, black_bb, HEX_W_LT);
}
void gen_east_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_jumps(u64_1, gen_side, white_bb, black_bb, HEX_E_LT);
}
void gen_north_east_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_jumps(u64_1, gen_side, white_bb, black_bb, HEX_NE_LT);
}
void gen_north_west_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_jumps(u64_1, gen_side, white_bb, black_bb, HEX_NW_LT);
}
void gen_south_east_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_jumps(u64_1, gen_side, white_bb, black_bb, HEX_SE_LT);
}
void gen_south_west_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    gen_side_jumps(u64_1, gen_side, white_bb, black_bb, HEX_SW_LT);
}
