#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern u16 D_800FCE64;

void func_800FC570(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 0x7) != 0) {
        if (D_800970A0.x_pos.i.hi < M2C_FIELD(arg0, s16*, 0xA)) {
            D_800970A0.unk15 = 0x40;
        } else {
            D_800970A0.unk15 = 0;
        }
        M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        if (D_800970A0.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        ((void (*)(void*, s32))func_800179A4)(arg0, 0xB);
        {
            s32 t = D_800FCE64;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            M2C_FIELD(arg0, u16*, 0xE) = t;
            M2C_FIELD(arg0, u8*, 0x5)++;
        }
        return;
    }
    if ((s16)--M2C_FIELD(arg0, u16*, 0x7E) == -1) {
        M2C_FIELD(arg0, u16*, 0x7E) = 5;
        M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
}
