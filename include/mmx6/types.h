/* mmx6/types.h — the one home of the project's types (hand-edited; Phase 1.6 T3).
 * Every typedef and struct the C units use is defined here, once, each preceded by its `// evidence:` line.
 * tools/mmx6/typecheck.py refuses a definition outside include/mmx6/, a duplicate shape, or a raw address cast in
 * src/<prog>/. Included by common.h. */
#ifndef MMX6_TYPES_H
#define MMX6_TYPES_H

// evidence: PSX MIPS R3000 ABI widths (char 1, short 2, int 4); was include/common.h, C MATCHED with these widths
typedef unsigned char u8;
// evidence: as u8, signed (lb loads of s8 globals, e.g. D_800970A5 in func_800473EC)
typedef signed char s8;
// evidence: PSX ABI short = 2 bytes, unsigned
typedef unsigned short u16;
// evidence: PSX ABI short = 2 bytes, signed (lh/sh of unk14/unk16 in func_800473EC)
typedef signed short s16;
// evidence: PSX ABI int = 4 bytes, unsigned
typedef unsigned int u32;
// evidence: PSX ABI int = 4 bytes, signed (lw/sw of unk18/unk1C in func_800473EC)
typedef signed int s32;

// evidence: func_800473EC (src/SLUS_013.95/120A0.c, matched): byte at +5, halfwords at +0x14/+0x16, words at +0x18/+0x1C
typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 pad6[0xE];
    s16 unk14;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
} Probe800473EC;

#endif /* MMX6_TYPES_H */
