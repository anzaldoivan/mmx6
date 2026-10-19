#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s32 D_8007618C;
extern s32 D_80076190;

void func_8004605C(u8* arg0) {
    s32* var_v0;

    ((void (*)())func_80017A04)();
    if (*(s8*)(arg0 + 0x45) != 0) {
        if (*(s8*)(arg0 + 2) < 3) {
            var_v0 = &D_8007618C;
        } else {
            var_v0 = &D_80076190;
        }
        *(s32**)(arg0 + 0x50) = var_v0;
        do {
        } while (0);
        arg0[5]++;
    }
}
