/* Shared body (phase 2 T6): call the routine D_80075FD8[obj[FAMILY_FIELD]] with obj.
 * Dup class aad97fb234fe... exemplar SLUS_013.95:0x80041AB8; family 40505e80... lane (W-fam): the byte offset is
 * lifted to FAMILY_FIELD (default 4, this class); a sibling class passes `--define FAMILY_FIELD=<k>` (C0065).
 * Included by each member TU in place of its INCLUDE_ASM (config/dedup_registry.txt). */
#include "common.h"

extern void (*D_80075FD8[])(s8*);

#ifndef FAMILY_FIELD
#define FAMILY_FIELD 4
#endif

void func_80041AB8(s8* arg0) {
    D_80075FD8[arg0[FAMILY_FIELD]](arg0);
}

#undef FAMILY_FIELD
