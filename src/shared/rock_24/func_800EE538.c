#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern s8 D_800CCEF6;
extern M2C_UNK D_800F7798;
extern M2C_UNK D_800F77B8;

void func_800EE538(u8* arg0) {
    if (D_800CCEF6 == 0) {
        arg0[4] += 2;
        return;
    }
    if (++*(u16*)(arg0 + 0x1A) >= 0x3C) {
        *(u16*)(arg0 + 0x1A) = 0x3C;
    }
    func_8002B410(&D_800F77B8, &D_800F7798, 0x10, 0x3C - *(u16*)(arg0 + 0x1A),
                  0x3C);
    load_palette(*(u16*)(arg0 + 0x20) + 0x60, &D_800F77B8, 1);
    if (*(u16*)(arg0 + 0x1A) == 0x3C) {
        arg0[4]++;
    }
}
