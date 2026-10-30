#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007555C;
extern u8 D_800970B4;
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
extern M2C_UNK D_800F908C;
extern M2C_UNK D_800F952C;
extern s16 D_800F9868;
extern s16 D_800F986A;
extern s32 D_800F9874;
extern M2C_UNK func_800F9088;

#define SP_9C (*(s32**)0x1F80009C)

void func_800F1F80(void* arg0) {
    s32* p;
    s32 t;
    s8 st;

    if (D_800CCEDC == 0xC) {
        p = SP_9C;
        t = *p;
        M2C_FIELD(arg0, s16*, 0x42) = 0x7948;
        M2C_FIELD(arg0, void**, 0x3C) = (s8*)p + t;
    }
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007555C;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F952C;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    set_animation(arg0, 2);
    st = M2C_FIELD(arg0, s8*, 2);
    if (st == 0) {
        M2C_FIELD(arg0, s16*, 0x40) = 0x140;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 0x8A) = -1;
        M2C_FIELD(arg0, u8*, 0x8B) = 0;
        M2C_FIELD(arg0, u8*, 0x8C) = 0;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        D_800F9874 = 0;
        M2C_FIELD(arg0, void**, 0x50) = &func_800F9088;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F908C;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        D_800F9868 = 0;
        D_800F986A = 0;
        M2C_FIELD(arg0, u8*, 4) = 1;
        M2C_FIELD(arg0, u8*, 5) = 2;
    } else if (st == 1) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 2;
    } else if (st == 2) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 5) = 3;
    } else if (st == 3) {
        M2C_FIELD(arg0, u8*, 0x5C) = 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 4) = st;
        M2C_FIELD(arg0, u8*, 5) = 4;
    }
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
}
#undef D_800CCEDC
