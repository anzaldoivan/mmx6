#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50();
extern s32 D_80097420;
extern u16 D_800C4570;
extern M2C_UNK D_800CD3F8;

void func_80048A8C(void* arg0, s32 arg1, void* arg2) {
    if (M2C_FIELD(arg0, u8*, 0x55) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == -1 || (D_800C4570 & 0x10) ||
            ((D_800C4570 & 0x800) && M2C_FIELD(&D_800CD3F8, s8*, 0) == 0xA)) {
            M2C_FIELD(arg0, s8*, 2) = -1;
        }
        if (M2C_FIELD(arg0, s8*, 2) == -1 || (D_800C4570 & 0x10) ||
            ((D_800C4570 & 0x800) && M2C_FIELD(&D_800CD3F8, s8*, 0) == 8)) {
            M2C_FIELD(arg0, s8*, 2) = -1;
        }
    }
    if (M2C_FIELD(arg0, s8*, 2) != -1) {
        u8* g = (u8*)&D_80097420;
        arg2 = g;
        if (M2C_FIELD(arg0, u8*, 0x54) != g[7]) {
            M2C_FIELD(arg0, u16*, 0xE) =
                ((u8*)(g[7] * 3 + M2C_FIELD(arg0, s32*, 0x50)))[2];
            M2C_FIELD(arg0, u8*, 0x54) = g[7];
        }
    }
    ((M2C_UNK(*)())func_8002CB50)(arg0, arg0, arg2);
}
