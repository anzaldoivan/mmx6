#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_sprite_slot();
extern s32 D_80075B9C;

void func_800ECF20(void* arg0) {
    void* temp_v0;

    temp_v0 = alloc_sprite_slot();
    if (temp_v0 != 0) {
        M2C_FIELD(temp_v0, u8*, 0) = 0x41;
        M2C_FIELD(temp_v0, u8*, 1) = 9;
        M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(temp_v0, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(temp_v0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(temp_v0, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(temp_v0, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(temp_v0, u16*, 8) = 0;
        M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(temp_v0, u16*, 0xC) = 0;
        M2C_FIELD(temp_v0, void**, 0x50) = arg0;
    }
    M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
    M2C_FIELD(arg0, u8*, 0x16) = 7;
    M2C_FIELD(arg0, u8*, 0x84) = 0x1F;
    M2C_FIELD(arg0, u8*, 6) = 3;
}
