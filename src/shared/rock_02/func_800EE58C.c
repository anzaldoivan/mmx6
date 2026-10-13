#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_800EE58C(void* arg0) {
    s16 v;
    s16 w;

    if (D_800970A0.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0xB4) {
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        func_800179A4(arg0, 4);
        func_80016C48(2, 4, arg0);
        M2C_FIELD(arg0, s32*, 0x28) = 0x10000;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < D_800970A0.y_pos.i.hi) {
        M2C_FIELD(arg0, s16*, 0xE) = v = M2C_FIELD(arg0, s16*, 0xE) + 2;
        if (D_800970A0.y_pos.i.hi < v) {
            M2C_FIELD(arg0, s16*, 0xE) = D_800970A0.y_pos.i.hi;
        }
    } else if (D_800970A0.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) = w = M2C_FIELD(arg0, s16*, 0xE) - 2;
        if (w < D_800970A0.y_pos.i.hi) {
            M2C_FIELD(arg0, s16*, 0xE) = D_800970A0.y_pos.i.hi;
        }
    }
}
#undef D_800970A0
