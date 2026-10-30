#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* enemy_slot_alloc();

void func_800F9EE4(void* arg0, u8 arg1) {
    void* p;

    p = enemy_slot_alloc();
    if (p != 0) {
        M2C_FIELD(p, u8*, 0) = 0x41;
        M2C_FIELD(p, u8*, 1) = 0x33;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(p, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(p, u8*, 0x15) = 0;
        }
        M2C_FIELD(p, u8*, 2) = arg1;
        M2C_FIELD(p, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(p, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(p, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(p, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(p, void**, 0x80) = arg0;
    }
}
