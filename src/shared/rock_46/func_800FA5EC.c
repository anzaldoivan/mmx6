#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA5EC(u8* arg0) {
    s32 count;

    count = (u16)D_800FD120 - 1;
    D_800FD120 = count;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        &D_800FBF20, &D_800FAD20, 0x300, (s16)count);
    load_palette(0x70, &D_800FBF20, 0x30);
    if (D_800FD120 == 0) {
        *(s16*)(arg0 + 8) = 0xA;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[1]++;
    }
}
