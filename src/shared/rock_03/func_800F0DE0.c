#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj D_800970A0;

void func_800F0DE0(void* arg0) {

    if (D_800970A0.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x5A) {
        func_80016C48(2, 0x28, arg0);
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < D_800970A0.y_pos.i.hi) {
        M2C_FIELD(arg0, s16*, 0xE) += 2;
        if (D_800970A0.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = D_800970A0.y_pos.i.hi;
        }
    } else if (D_800970A0.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) -= 2;
        if (M2C_FIELD(arg0, s16*, 0xE) < D_800970A0.y_pos.i.hi) {
            M2C_FIELD(arg0, s16*, 0xE) = D_800970A0.y_pos.i.hi;
        }
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
        if (D_800970A0.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
        }
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
}
