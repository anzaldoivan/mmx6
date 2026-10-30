#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* enemy_slot_alloc();
extern s8 D_800FD521;

void func_800F4328(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;
    u8 b15;

    obj = enemy_slot_alloc();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0x18;
        b15 = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, void**, 0x80) = arg0;
        M2C_FIELD(obj, u8*, 2) = arg1;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, u8*, 0x15) = b15;
        M2C_FIELD(obj, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        if ((arg1 & 0xF0) == 0x30) {
            D_800FD521++;
        }
    }
}
