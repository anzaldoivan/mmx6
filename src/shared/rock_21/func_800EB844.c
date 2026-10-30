#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern M2C_UNK D_800ED240;
extern M2C_UNK D_800ED440;
extern s16 D_800F2240;

void func_800EB844(u8* arg0) {
    u16* src;
    u16* dst;
    s32 i;

    D_800F2240--;
    func_8002B410(&D_800ED440, &D_800ED240, 0x10, D_800F2240, 0x60);
    load_palette(0x60, &D_800ED440, 1);
    if (D_800F2240 == 0) {
        dst = (u16*)&D_800ED440;
        src = (u16*)&D_800ED240;
        for (i = 0xF; i >= 0; i--) {
            *dst++ = *src++ & 0x7FFF;
        }
        load_palette(0x60, &D_800ED440, 1);
        arg0[1]++;
    }
}
