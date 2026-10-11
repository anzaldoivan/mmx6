#include "common.h"
#define M2C_UNK s32
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
extern s8 D_800CCEEC;
extern u8 D_800E9878[];
extern M2C_UNK D_800FD530;
extern M2C_UNK D_800FD930;
extern M2C_UNK D_800FD9D0;
extern s16 D_800FDA70;

void func_800EDD28(u8* arg0) {
    u8 buf[4];

    __builtin_memcpy(buf, D_800E9878, 4);
    D_800CCEEC = 1;
    __builtin_memcpy((u8*)&D_800FD530, (u8*)(SPAD28 + 0x780), 0x200);
    __builtin_memcpy((u8*)&D_800FD930, (u8*)(SPAD28 + 0xC00), 0xA0);
    D_800FDA70 = 0;
    func_8002B410(&D_800FD9D0, &D_800FD930, 0x50, 0, 0x60);
    func_8002B3D4(0x60, &D_800FD9D0, 5);
    *(s16*)(arg0 + 0x7C) = 3;
    arg0[7] = 0;
    arg0[6]++;
}
