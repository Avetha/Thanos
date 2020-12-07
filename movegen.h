#ifndef MOVEGEN_H
#define MOVEGEN_H
#include <stdint.h>

void gen_bishop_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_rook_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_king_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_knight_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_short_bishop_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);

#endif // MOVEGEN_H
