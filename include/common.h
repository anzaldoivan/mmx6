/* common.h — included first by every src/ C unit (hand-edited).
 * INCLUDE_ASM(FOLDER, NAME): a function not yet decompiled; assembles the splat-written
 * FOLDER/NAME.s (asm/<bin>/nonmatchings/<tu>/, ignored, never tracked) in place.
 * A NON_MATCHING draft sits under `#ifdef NON_MATCHING` with its INCLUDE_ASM in the
 * `#else`; the default build never defines NON_MATCHING (G4). */
#ifndef COMMON_H
#define COMMON_H

#include "mmx6/types.h"

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
