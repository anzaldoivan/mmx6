#include "common.h"
#define M2C_UNK s32
#define SPAD28 (*(u8**)0x1F800028)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
s32 func_800EA480(s8* arg0);
extern M2C_UNK D_800FAD20;
extern M2C_UNK D_800FBF20;
extern s16 D_800FD120;

void func_800FA720(s8* arg0) {
    if (func_800EA480(arg0) != 0) {
        __builtin_memcpy(&D_800FAD20, SPAD28 + 0x1200, 0x600);
        D_800FD120 = 0;
        func_8002B54C(&D_800FBF20, &D_800FAD20, 0x300, 0);
        load_palette(0x90, &D_800FBF20, 0x30);
        play_sound(0, 8, 0);
        ((u8*)arg0)[1]++;
    }
}
