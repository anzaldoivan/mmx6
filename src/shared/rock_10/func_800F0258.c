#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
void set_velocity_from_angle(void*, s32);

void func_800F0258(void* arg0) {
    void* temp_v0;
    s32 x;
    s32 y;

    x = M2C_FIELD(arg0, u8*, 0x81);
    if ((u32)(x - 9) < 15) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            goto skip;
        }
    } else {
        y = x - 8;
        if ((u8)y < 17) {
            goto skip;
        }
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            goto skip;
        }
    }
    M2C_FIELD(arg0, u16*, 0x7C) = 0xA;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
skip:
    if (M2C_FIELD(arg0, s8*, 6) != 4) {
        func_800179A4(arg0, 4);
        temp_v0 = func_8002C458();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, u8*, 0) = 0x41;
            M2C_FIELD(temp_v0, u8*, 1) = 0x23;
            M2C_FIELD(temp_v0, u8*, 2) = M2C_FIELD(arg0, u8*, 2);
            M2C_FIELD(temp_v0, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(temp_v0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(temp_v0, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(temp_v0, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            x = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(temp_v0, s32*, 8) = x;
            M2C_FIELD(temp_v0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            set_velocity_from_angle(temp_v0, M2C_FIELD(arg0, u8*, 0x81));
            M2C_FIELD(temp_v0, u8*, 4) = 0;
            M2C_FIELD(temp_v0, s32*, 0x20) = M2C_FIELD(temp_v0, s32*, 0x20) * 3;
            M2C_FIELD(temp_v0, s32*, 0x24) = M2C_FIELD(temp_v0, s32*, 0x24) * 3;
        }
        if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            M2C_FIELD(arg0, u16*, 0x7C) = 0xA;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 0x14;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) - 1;
        }
    }
}
