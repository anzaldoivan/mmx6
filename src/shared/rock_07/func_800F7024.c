#include "common.h"
#define M2C_UNK s32

extern M2C_UNK func_8002C9B0();
extern s16 D_800F9868;
extern s16 D_800F986A;

void func_800F7024(u8* arg0) {
    s32 kind;

    kind = *(s8*)(arg0 + 2) & 0xF0;
    if (kind == 0x20) {
        D_800F9868--;
    } else if (kind == 0x50 && arg0[0x96] == 1) {
        D_800F986A--;
    }
    ((M2C_UNK(*)())func_8002C9B0)(arg0, kind);
}
