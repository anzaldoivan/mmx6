#include "common.h"

extern u8 D_801EE700[];
extern u8 D_801EE800[];
extern u8 D_801EE900[];
extern s32 D_801EEA00[];
extern u8 D_801EF620[];
extern u8 D_801F3B4C[];
extern u8 D_801F3C4C[];
extern u8 D_801F3D4C[];
extern u8 D_801F3E4C[];
extern s32 D_801F3F4C[];
extern u8 D_801F49F4[];

#define PB(o) (*(s8*)((u8*)arg0 + (o)))
#define PU(o) (*(u8*)((u8*)arg0 + (o)))
#define PP(o) (*(s32**)((u8*)arg0 + (o)))

void func_8003C3C8(void* arg0) {
    s32 base;
    s32 off;
    u8 v;
    u8 k;

    if (PB(0x2) == 0) {
        if (D_801F49F4[PU(0x17)] == 0) {
            v = D_801F3B4C[PU(0x47)];
        } else {
            k = PU(0xE7);
            if (k == 1) {
                v = D_801F3D4C[PU(0x47)];
            } else if (k == 2) {
                v = D_801F3E4C[PU(0x47)];
            } else {
                v = D_801F3C4C[PU(0x47)];
            }
        }
        off = v * 4;
        if (v == 0) {
            PP(0x54) = 0;
            return;
        }
        base = (s32)D_801F3F4C;
        goto end;
    }
    k = D_801EF620[PU(0x17)];
    if (k == 0) {
        v = D_801EE700[PU(0x47)];
    } else if (k == 1) {
        v = D_801EE800[PU(0x47)];
    } else if (k == 2) {
        v = D_801EE900[PU(0x47)];
    }
    off = v * 4;
    if (v == 0) {
        PP(0x54) = 0;
        return;
    }
    base = (s32)D_801EEA00;
end:
    off += base;
    PP(0x54) = (s32*)off;
}

#undef PB
#undef PU
#undef PP
