/* common.h — included first by every src/ C unit (hand-edited).
 * INCLUDE_ASM(FOLDER, NAME): a function not yet decompiled; assembles the splat-written
 * FOLDER/NAME.s (asm/<bin>/nonmatchings/<tu>/, ignored, never tracked) in place.
 * A NON_MATCHING draft sits under `#ifdef NON_MATCHING` with its INCLUDE_ASM in the
 * `#else`; the default build never defines NON_MATCHING (G4). */
#ifndef COMMON_H
#define COMMON_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define INCLUDE_ASM(FOLDER, NAME)                                              \
    __asm__(".section .text\n"                                                 \
            "\t.set push\n"                                                    \
            "\t.set noat\n"                                                    \
            "\t.set noreorder\n"                                               \
            ".include \"" FOLDER "/" #NAME ".s\"\n"                            \
            "\t.set pop\n")

/* Label macros (glabel, endlabel, ...) for the included .s, once per unit. */
__asm__(".include \"macro.inc\"\n");

#endif /* COMMON_H */
