/* Shared body (phase 1.6 T4): call the routine D_80073C1C[obj[6]] with obj.
 * Dup class 6d5cbe2977a0... (15 words, 416 members, reach 37); exemplar SLUS_013.95:0x8003744C.
 * Included by each member TU in place of its INCLUDE_ASM (config/dedup_registry.txt). */
#include "common.h"

extern void (*D_80073C1C[])(s8*);

void func_8003744C(s8* arg0) {
    D_80073C1C[arg0[6]](arg0);
}
