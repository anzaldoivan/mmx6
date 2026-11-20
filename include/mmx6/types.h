/* mmx6/types.h -- the one home of the project's types (hand-edited; Phase 1.6 T3).
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

// evidence: func_800144DC (src/shared/SLUS_013.95/func_800144DC.c, matched): D_8006E1D4[idx] at idx*8, lhu +0/+2, lbu +4..+7
struct LoadingSprtRow {
    s16 x, y;
    u8 uv, w, h, clut; // uv and clut pack two 16-px cells in their nibbles; w and h count 16-px cells
};

/* a 7-entry function table read as one object (func_80040290, D_80011574) */
typedef struct {
    void* fn[7];
} FnTbl7;

/* a stack-built visual object (X4_VisualObj prefix, 0x50 bytes; func_8001A330) */
typedef struct {
    s8 active;
    s8 pad1[9];
    s16 x;
    s8 pad2[2];
    s16 y;
    s8 pad3[4];
    s8 bg_offset;
    u8 unk15;
    u8 unk16;
    s8 pad4[0x3C - 0x17];
    u8* unk3C;
    s16 unk40;
    s16 unk42;
    s8 pad5[3];
    s8 unk47;
    s8 pad6[0x50 - 0x48];
} VisObj50;

// evidence: func_8001717C (src/shared/SLUS_013.95/func_8001717C.c, matched): lw +0 then `& 0xFFFFFF` (ofs:24) / `>> 24` (mode), lw +4 size; the match needs the bitfield read (C0471)
typedef struct {
    u32 ofs : 24;
    u32 mode : 8;
    s32 size;
} VabSlot;

// evidence: func_800319EC (src/shared/SLUS_013.95/func_800319EC.c, matched): D_800737D0[] 5-byte rows, lb +0 next, +1 kind, +2/+3 flags, lbu +4 sound
typedef struct {
    s8 next;
    s8 kind;
    s8 flag2;
    s8 flag3;
    u8 sound;
} HitEntry;

// evidence: func_800319EC (matched): the hit object's fields read at +0, +1, +0x14, +0x15, +0x80, +0x82, +0x98
typedef struct {
    s8 active;
    s8 id;
    s8 pad2[0x12];
    s8 bg_offset;
    u8 unk15;
    s8 pad16[0x80 - 0x16];
    u16 unk80;
    u16 unk82;
    s8 pad84[0x98 - 0x84];
    s8 unk98;
} HitSelf;

// evidence: func_8004E26C (src/shared/SLUS_013.95/func_8004E26C.c, matched): g_playthrough_state as a byte array from +0x5B; inline `(e + 0x5B)[i]` scores 215/219
typedef struct {
    u8 pad[0x5B];
    u8 a[8];
} S5B;

#endif /* MMX6_TYPES_H */
