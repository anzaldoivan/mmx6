#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
extern s32 D_80073760[];
extern s32 D_80073784[];

void func_8004C41C(void* arg0) {
    s32 sy;
    s32 sx;
    s32 i;
    s32 vx;
    s32 vy;

    M2C_FIELD(arg0, u8*, 0x36) = 0;
    M2C_FIELD(arg0, s16*, 0x34) = 1;
    M2C_FIELD(arg0, u8*, 0x37) = 0;
    M2C_FIELD(arg0, u8*, 0) |= 0x82;
    M2C_FIELD(arg0, u8*, 0x38) = func_8002D2D4() & 0x1F;
    if (M2C_FIELD(arg0, u8*, 0x38) < 0x10) {
        sy = -1;
        if (M2C_FIELD(arg0, u8*, 0x38) < 8) {
            sx = 1;
            i = 8 - M2C_FIELD(arg0, u8*, 0x38);
        } else {
            sx = -1;
            i = M2C_FIELD(arg0, u8*, 0x38) - 8;
        }
    } else {
        sy = 1;
        if (M2C_FIELD(arg0, u8*, 0x38) < 0x18) {
            sx = -1;
            i = 0x18 - M2C_FIELD(arg0, u8*, 0x38);
        } else {
            sx = 1;
            i = M2C_FIELD(arg0, u8*, 0x38) - 0x18;
        }
    }
    vx = (D_80073760[i] * sx << 4) >> 4;
    M2C_FIELD(arg0, s32*, 0x3C) = vx;
    vy = D_80073784[i] * sy << 4;
    M2C_FIELD(arg0, s32*, 0x44) = vx;
    M2C_FIELD(arg0, s32*, 0x4C) = vx;
    M2C_FIELD(arg0, s32*, 0x54) = vx / 2;
    M2C_FIELD(arg0, s32*, 0x14) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = 0;
    M2C_FIELD(arg0, s32*, 0x1C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x30) = 0;
    M2C_FIELD(arg0, u8*, 0x39) = 4;
    M2C_FIELD(arg0, u8*, 0x3A) = 0;
    M2C_FIELD(arg0, u8*, 4) += 1;
    M2C_FIELD(arg0, s32*, 0x40) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x48) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x50) = vy >> 4;
    M2C_FIELD(arg0, s32*, 0x58) = (vy >> 4) / 2;
}
