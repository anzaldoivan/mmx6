#include "common.h"

extern s16 D_80073D74[];
extern s16 D_80073DF4[];
extern u8 D_800CCF2F;

#define EB0C_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define EB0C_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define EB0C_S32(p, o) (*(s32*)((u8*)(p) + (o)))

s32 func_8003EB0C(void* arg0, s32 arg1) {
    s8 idx = arg1;
    s16 v;

    if (EB0C_S8(arg0, 2) != 0) {
        if (EB0C_S32(arg0, 0xEC) & 0x20) {
            return (s16)(D_80073DF4[idx] * 3);
        }
        if (D_800CCF2F & 0x20) {
            return (s16)(D_80073DF4[idx] * 4);
        }
        return (s16)(D_80073DF4[idx] * 6);
    }
    v = D_80073D74[idx] * 6;
    if (v == 0) {
        return 0;
    }
    if (EB0C_S32(arg0, 0xEC) & 0x20) {
        v = v / 2;
    } else {
        switch (EB0C_U8(arg0, 0xE7)) {
        case 1:
        case 3:
        case 4:
            v = (v * 2) / 3;
            break;
        }
    }
    if (v == 0) {
        v = 1;
    }
    return v;
}

#undef EB0C_S8
#undef EB0C_U8
#undef EB0C_S32
