#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_8007623C;
extern s32 D_80076240;
extern s32 D_80076244;

void func_80046630(void* arg0) {
    s8 temp_v1;
    void* temp_a2;
    u16 e;

    M2C_FIELD(arg0, s8*, 0x4) = 1;
    temp_v1 = M2C_FIELD(arg0, s8*, 0x2);
    temp_a2 = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, s8*, 0x3) = 0;
    M2C_FIELD(arg0, s8*, 0x16) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32**, 0x50) = &D_8007623C;
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, s32**, 0x50) = &D_8007623C;
        break;
    case 1:
        M2C_FIELD(arg0, s32**, 0x50) = &D_80076240;
        break;
    case 2:
        M2C_FIELD(arg0, s32**, 0x50) = &D_80076244;
        break;
    }
    M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(temp_a2, u16*, 0xA);
    e = M2C_FIELD(temp_a2, u16*, 0xE);
    M2C_FIELD(arg0, s8*, 0x5C) = 0;
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, u16*, 0xE) = e;
}
