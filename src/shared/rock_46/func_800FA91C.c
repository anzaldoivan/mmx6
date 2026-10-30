#include "common.h"
#define M2C_UNK s32

M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA91C(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x79) {
        if (func_800EA480((s8*)arg0) != 0) {
            s32 t = (u16)D_800FD120 - 1;
            D_800FD120 = t;
            ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
                &D_800FBF20, &D_800FAD20, 0x300, (s16)t);
            load_palette(0x90, &D_800FBF20, 0x30);
            if (D_800FD120 == 0) {
                *(s16*)(arg0 + 8) = 0x13;
                *(s16*)(arg0 + 0xA) = 2;
                arg0[1]++;
            }
        }
    } else {
        *(s16*)(arg0 + 4) += 1;
    }
}
