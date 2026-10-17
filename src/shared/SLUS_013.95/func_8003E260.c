#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 func_8003E344(void* self);
void func_8003E614(void* arg0);
M2C_UNK func_8003F864(void*, M2C_UNK);
void func_801EB6E8(void* arg0);
extern s8 D_80073E00[];

s32 func_8003E260(void* arg0) {
    s8* p = arg0;
    s8 idx;

    if (p[0xD3] != 0) {
        return 0;
    }
    if (p[2] != 0) {
        return 0;
    }
    if (func_8003E344(arg0) != 0) {
        return 1;
    }
    func_8003E614(arg0);
    if (p[0x8F] == 0) {
        return 0;
    }
    idx = p[0x96];
    if (D_80073E00[idx] == 0) {
        func_801EB6E8(arg0);
        return 1;
    }
    p[0x8C] = 0;
    if (idx == 50) {
        func_8003AFF4((s32)arg0);
    } else if (idx == 5 || idx == 14) {
        func_8003BA04(arg0, 0x5C);
    }
    func_8003F864(arg0, 1);
    return 1;
}
