#include "movegen.h"
#include <stdint.h>
#include <iostream>
#include "lookup_tables.h"
#include "defs.h"
using namespace std;
/*
    @brief Generates and pushes all pseudo-legal bishop moves into the move
           list vector for the given board state.

    This function generates all pseudo-legal moves for a given bitboard,
    considering all set bits as bishops. This is also useful for generating
    diagonal moves for queens.

    @param u64_1 is the bitboard representing all pieces which are to be
           considered as bishops during generation.
    @param gen_side is the side to generate moves for.
    @param white_bb bitboard containing white pieces
    @param black_bb bitboard containing black pieces

    @return void.
*/

void gen_bishop_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{

    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.

    unsigned int uint_1, uint_2, uint_3; // Temporary variables.
    uint64_t u64_2, u64_3; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);

        // Northeast

        u64_2 = DIAG_NE_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 << 9) | (u64_2 << 18) | (u64_2 << 27) |
            (u64_2 << 36) | (u64_2 << 45) | (u64_2 << 54);
        u64_2 &= DIAG_NE_LT[uint_1];
        u64_2 ^= DIAG_NE_LT[uint_1];

        if(u64_3)
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }

        // Pop the capture move last.

        if(u64_3 && ((gen_side == WHITE && (u64_2 & black_bb)) ||
            (gen_side == BLACK && (u64_2 & white_bb))))
        {
            u64_3 = u64_2;
            assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;

        }

        // Northwest

        u64_2 = DIAG_NW_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 << 7) | (u64_2 << 14) | (u64_2 << 21) |
            (u64_2 << 28) | (u64_2 << 35) | (u64_2 << 42);
        u64_2 &= DIAG_NW_LT[uint_1];
        u64_2 ^= DIAG_NW_LT[uint_1];

        if(u64_3)
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;
        }

        // Pop the capture move last.

        if(u64_3 && ((gen_side == WHITE && (u64_2 & black_bb)) ||
            (gen_side == BLACK && (u64_2 & white_bb))))
        {
            u64_3 = u64_2;
            assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
        }

        // Southeast

        u64_2 = DIAG_SE_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 >> 7) | (u64_2 >> 14) | (u64_2 >> 21) |
            (u64_2 >> 28) | (u64_2 >> 35) | (u64_2 >> 42);
        u64_2 &= DIAG_SE_LT[uint_1];
        u64_2 ^= DIAG_SE_LT[uint_1];

        if(u64_3) // Pop the capture move first.
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
            uint_3 = POP_BIT(u64_2);
            u64_3 = GET_BB(uint_3);

            if((gen_side == WHITE && (u64_3 & black_bb)) ||
                (gen_side == BLACK && (u64_3 & white_bb)))
            {
                assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
                std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
            }
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;
        }

        // Southwest

        u64_2 = DIAG_SW_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 >> 9) | (u64_2 >> 18) | (u64_2 >> 27) |
            (u64_2 >> 36) | (u64_2 >> 45) | (u64_2 >> 54);
        u64_2 &= DIAG_SW_LT[uint_1];
        u64_2 ^= DIAG_SW_LT[uint_1];

        if(u64_3) // Pop the capture move first.
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
            uint_3 = POP_BIT(u64_2);
            u64_3 = GET_BB(uint_3);

            if((gen_side == WHITE && (u64_3 & black_bb)) ||
                (gen_side == BLACK && (u64_3 & white_bb)))
            {
                assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
                std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
            }
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
        }
    }
}
/*
    @brief Generates and pushes all pseudo-legal rook moves into the move
           list vector for the given board state.

    This function generates all pseudo-legal moves for a given bitboard,
    considering all set bits as rooks. This is also useful for generating
    line moves for queens.

    @param u64_1 is the bitboard representing all pieces which are to be
           considered as rooks during generation.
    @param gen_side is the side to generate moves for.
    @param white_bb bitboard containing white pieces
    @param black_bb bitboard containing black pieces

    @return void.
*/

void gen_rook_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.

    unsigned int uint_1, uint_2, uint_3; // Temporary variables.
    uint64_t u64_2, u64_3; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);

        // North

        u64_2 = LINE_N_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 << 8) | (u64_2 << 16) | (u64_2 << 24) |
            (u64_2 << 32) | (u64_2 << 40) | (u64_2 << 48);
        u64_2 &= LINE_N_LT[uint_1];
        u64_2 ^= LINE_N_LT[uint_1];

        if(u64_3)
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }

        // Pop the capture move last.

        if(u64_3 && ((gen_side == WHITE && (u64_2 & black_bb)) ||
            (gen_side == BLACK && (u64_2 & white_bb))))
        {
            u64_3 = u64_2;
            assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;

        }

        // South

        u64_2 = LINE_S_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 >> 8) | (u64_2 >> 16) | (u64_2 >> 24) |
            (u64_2 >> 32) | (u64_2 >> 40) | (u64_2 >> 48);
        u64_2 &= LINE_S_LT[uint_1];
        u64_2 ^= LINE_S_LT[uint_1];

        if(u64_3) // Pop the capture move first.
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
            uint_3 = POP_BIT(u64_2);
            u64_3 = GET_BB(uint_3);

            if((gen_side == WHITE && (u64_3 & black_bb)) ||
                (gen_side == BLACK && (u64_3 & white_bb)))
            {
                assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
                std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;

            }
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }

        // East

        u64_2 = LINE_E_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 << 1) | (u64_2 << 2) | (u64_2 << 3) |
            (u64_2 << 4) | (u64_2 << 5) | (u64_2 << 6);
        u64_2 &= LINE_E_LT[uint_1];
        u64_2 ^= LINE_E_LT[uint_1];

        if(u64_3)
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }

        // Pop the capture move last.

        if(u64_3 && ((gen_side == WHITE && (u64_2 & black_bb)) ||
            (gen_side == BLACK && (u64_2 & white_bb))))
        {
            u64_3 = u64_2;
            assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;

        }

        // West

        u64_2 = LINE_W_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 >> 1) | (u64_2 >> 2) | (u64_2 >> 3) |
            (u64_2 >> 4) | (u64_2 >> 5) | (u64_2 >> 6);
        u64_2 &= LINE_W_LT[uint_1];
        u64_2 ^= LINE_W_LT[uint_1];

        if(u64_3) // Pop the capture move first.
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
            uint_3 = POP_BIT(u64_2);
            u64_3 = GET_BB(uint_3);

            if((gen_side == WHITE && (u64_3 & black_bb)) ||
                (gen_side == BLACK && (u64_3 & white_bb)))
            {
                assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
                std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;

            }
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }
    }
}
/*
    @brief Generates and pushes all pseudo-legal king moves into the move
           list vector for the given board state.
    @param u64_1 is the bitboard representing all pieces which are to be
           considered as kings during generation.
    @param gen_side is the side to generate moves for.
    @param white_bb bitboard containing white pieces
    @param black_bb bitboard containing black pieces

    @return void.

*/

void gen_king_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.

    unsigned int uint_1, uint_2, uint_3; // Temporary variables.
    uint64_t u64_2, u64_3; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);
        u64_3 = KING_LT[uint_1] & OCC;
        u64_2 = KING_LT[uint_1] ^ u64_3;
        if(gen_side==WHITE)
            u64_3 &= black_bb;
        else
            u64_3 &= white_bb;

        uint_2 = CNT_BITS(u64_2);
        uint_3 = CNT_BITS(u64_3);
        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }
        for(unsigned int i = 0; i < uint_3; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " ->X " << POP_BIT(u64_3) << std::endl;

        }

    }


}


/*
    @brief Generates and pushes all pseudo-legal knight moves into the move
           list vector for the given board state.
    @param u64_1 is the bitboard representing all pieces which are to be
           considered as bishops during generation.
    @param gen_side is the side to generate moves for.
    @param white_bb bitboard containing white pieces
    @param black_bb bitboard containing black pieces
    @param board is the board on which the moves are to be generated.

    @return void.

*/

void gen_knight_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{
    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.

    unsigned int uint_1, uint_2, uint_3; // Temporary variables.
    uint64_t u64_2, u64_3; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);
        u64_3 = KNIGHT_LT[uint_1] & OCC;
        u64_2 = KNIGHT_LT[uint_1] ^ u64_3;

        if(gen_side==WHITE)
            u64_3 &= black_bb;
        else
            u64_3 &= white_bb;
        uint_2 = CNT_BITS(u64_2);
        uint_3 = CNT_BITS(u64_3);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }
        for(unsigned int i = 0; i < uint_3; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " ->X " << POP_BIT(u64_3) << std::endl;

        }

    }


}



/*
    @brief Generates and pushes all pseudo-legal short bishop moves into the move
           list vector for the given board state.

    This function generates all pseudo-legal moves for a given bitboard,
    considering all set bits as short bishops. This is also useful for generating
    diagonal moves for queens.

    @param u64_1 is the bitboard representing all pieces which are to be
           considered as bishops during generation.
    @param gen_side is the side to generate moves for.
    @param white_bb bitboard containing white pieces
    @param black_bb bitboard containing black pieces

    @return void.
*/

void gen_short_bishop_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb)
{

    const uint64_t OCC = white_bb | black_bb; // Occupied bitboard.

    unsigned int uint_1, uint_2, uint_3; // Temporary variables.
    uint64_t u64_2, u64_3; // Temporary variables.
    unsigned int bit_cnt; // Number of bits; temporary variable.

    // Generation

    bit_cnt = CNT_BITS(u64_1);

    for(unsigned int i = 0; i < bit_cnt; i++)
    {
        uint_1 = POP_BIT(u64_1);

        // Northeast
        uint64_t MY_DIAG = (uint_1<<9 | uint_1<<18);
        u64_2 = MY_DIAG & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 << 9) | (u64_2 << 18) | (u64_2 << 27) |
            (u64_2 << 36) | (u64_2 << 45) | (u64_2 << 54);
        u64_2 &= MY_DIAG;
        u64_2 ^= MY_DIAG;

        if(u64_3)
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;

        }

        // Pop the capture move last.

        if(u64_3 && ((gen_side == WHITE && (u64_2 & black_bb)) ||
            (gen_side == BLACK && (u64_2 & white_bb))))
        {
            u64_3 = u64_2;
            assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;

        }

        // Northwest

        u64_2 = DIAG_NW_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 << 7) | (u64_2 << 14) | (u64_2 << 21) |
            (u64_2 << 28) | (u64_2 << 35) | (u64_2 << 42);
        u64_2 &= DIAG_NW_LT[uint_1];
        u64_2 ^= DIAG_NW_LT[uint_1];

        if(u64_3)
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;
        }

        // Pop the capture move last.

        if(u64_3 && ((gen_side == WHITE && (u64_2 & black_bb)) ||
            (gen_side == BLACK && (u64_2 & white_bb))))
        {
            u64_3 = u64_2;
            assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
        }

        // Southeast

        u64_2 = DIAG_SE_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 >> 7) | (u64_2 >> 14) | (u64_2 >> 21) |
            (u64_2 >> 28) | (u64_2 >> 35) | (u64_2 >> 42);
        u64_2 &= DIAG_SE_LT[uint_1];
        u64_2 ^= DIAG_SE_LT[uint_1];

        if(u64_3) // Pop the capture move first.
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
            uint_3 = POP_BIT(u64_2);
            u64_3 = GET_BB(uint_3);

            if((gen_side == WHITE && (u64_3 & black_bb)) ||
                (gen_side == BLACK && (u64_3 & white_bb)))
            {
                assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
                std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
            }
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " -> " << POP_BIT(u64_2) << std::endl;
        }

        // Southwest

        u64_2 = DIAG_SW_LT[uint_1] & OCC;
        u64_3 = u64_2;

        u64_2 = (u64_2 >> 9) | (u64_2 >> 18) | (u64_2 >> 27) |
            (u64_2 >> 36) | (u64_2 >> 45) | (u64_2 >> 54);
        u64_2 &= DIAG_SW_LT[uint_1];
        u64_2 ^= DIAG_SW_LT[uint_1];

        if(u64_3) // Pop the capture move first.
        {
            uint_2 = CNT_BITS(u64_2);
            uint_2--;
            uint_3 = POP_BIT(u64_2);
            u64_3 = GET_BB(uint_3);

            if((gen_side == WHITE && (u64_3 & black_bb)) ||
                (gen_side == BLACK && (u64_3 & white_bb)))
            {
                assert((u64_3 != 0ULL) && ((u64_3 & (u64_3 - 1)) == 0ULL));
                std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
            }
        }
        else uint_2 = CNT_BITS(u64_2);

        for(unsigned int i = 0; i < uint_2; i++) // Push quiet moves.
        {
            std::cout << uint_1 << " ->X " << POP_BIT(u64_2) << std::endl;
        }
    }
}

