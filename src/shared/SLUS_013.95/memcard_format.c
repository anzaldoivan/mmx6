/* Adapted from sozud/mmx4 @807a01b src/main/memcard.c:func_8001CE84, AGPL-3.0; proven shared with X6 by exact signature e642975dc52e (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system memcard | range 0x8001C6C0-0x8001C714
// Shared file: included by src/SLUS_013.95/120A0.c, between func_8001C5EC and func_8001C718.
#include "common.h"
#include "mmx6/x4.h"
extern long format(char*);
extern const struct X4_MemcardPath D_800100AC;

// 0x8001C6C0 memcard_format: formats the memory card in the given slot.
// basis: string strings.tsv:6:SLUS_013.95:0x800100AC
// callers: none known
// str 0x800100AC "bu00:" = "memory card device, slot 1"
s32 memcard_format(s32 device_num) {

    struct X4_MemcardPath buf = D_800100AC;

    buf.path[2] += device_num;
    return format(buf.path) ^ 1;
}
