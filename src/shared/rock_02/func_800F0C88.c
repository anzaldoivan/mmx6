#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002A47C(s32);
extern s8 D_80097244;
extern u8 D_800FB218[];
extern s32 D_800FBC74;

void func_800F0C88(void* arg0) {
    s32 off;

    D_800FBC74 = 1;
    func_80027BA0(0, 0x17B0, 0xD0, D_800FB218);
    func_80027BA0(0, 0x1930, 0xD0, D_800FB218 + 0x10);
    D_80097244 = 1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    off = *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20 + 4);
    M2C_FIELD(arg0, s32*, 0x3C) = SPAD20 + off;
    func_800179A4(arg0, 6);
    func_80016C48(2, 2, arg0);
    M2C_FIELD(arg0, u8*, 6)++;
}
