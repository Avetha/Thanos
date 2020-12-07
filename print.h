#ifndef PRINT_H
#define PRINT_H
#include <stdint.h>
#include <vector>



std::vector<int> bb_to_vec (uint64_t white_bb);
void printbb(uint64_t white_pieces, uint64_t black_pieces);
void print_empty_bb();
void print_lookup(const uint64_t lookup[64]);


#endif
