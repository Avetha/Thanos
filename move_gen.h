#ifndef MOVEGEN_H
#define MOVEGEN_H
#include <stdint.h>

void gen_side_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb, const uint64_t lookup[64]);
void gen_side_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb, const uint64_t lookup[64]);

void gen_east_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_west_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_north_east_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_north_west_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_south_east_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_south_west_moves(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);


void gen_east_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_west_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_north_east_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_north_west_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_south_east_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);
void gen_south_west_jumps(uint64_t u64_1, bool gen_side, const uint64_t white_bb, const uint64_t black_bb);


#endif // MOVEGEN_H
