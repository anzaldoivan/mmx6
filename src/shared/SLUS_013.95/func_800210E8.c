#include "common.h"

#define CUR (*(u8**)0x1F800064)

extern u8 D_800964A0[];
extern void (*D_80071360[])(s8*);

void func_800210E8(void) {
    s8* p;

    for (CUR = D_800964A0; CUR < D_800964A0 + 0xC00; CUR += 0x60) {
        p = (s8*)CUR;
        if (p[0] != 0) {
            D_80071360[p[1]](p);
        }
    }
}
