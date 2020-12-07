#ifndef LOOKUP_TABLES_H
#define LOOKUP_TABLES_H
#include <stdint.h>
#include "defs.h"

// Globals
extern const uint64_t KING_LT[64]; // King lookup.
extern const uint64_t HEX_E_LT[64]; // Hexagonal board side lookups.
extern const uint64_t HEX_N_LT[64];
extern const uint64_t HEX_S_LT[64];
extern const uint64_t HEX_W_LT[64];
extern const uint64_t HEX_NE_LT[64];
extern const uint64_t HEX_NW_LT[64];
extern const uint64_t HEX_SE_LT[64];
extern const uint64_t HEX_SW_LT[64];
extern const uint64_t KNIGHT_LT[64]; // Knight lookup.
extern const uint64_t LINE_LT[64]; // Lines.
extern const uint64_t DIAG_LT[64]; // Diagonals.
extern const uint64_t LINE_DIAG_LT[64]; // Lines and diagonals.
extern const uint64_t LINE_N_LT[64]; // North line.
extern const uint64_t LINE_S_LT[64]; // South line.
extern const uint64_t LINE_E_LT[64]; // East line.
extern const uint64_t LINE_W_LT[64]; // West line.
extern const uint64_t DIAG_NE_LT[64]; // Northeast diagonal.
extern const uint64_t DIAG_NW_LT[64]; // Northwest diagonal.
extern const uint64_t DIAG_SE_LT[64]; // Southeast diagonal.
extern const uint64_t DIAG_SW_LT[64]; // Southwest diagonal.

#endif // LOOKUP_TABLES_H
