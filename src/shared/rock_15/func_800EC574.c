#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
extern s32 D_800F6154;

void func_800EC574(void* arg0) {
    void* o;
    u8 i;

    for (i = 0; i < 2; i++) {
        o = func_8002C458();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x26;
            M2C_FIELD(o, u8*, 2) = i;
            M2C_FIELD(o, void**, 0x7C) = arg0;
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42);
            M2C_FIELD(o, void**, 0x30) = &D_800F6154;
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(o, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(o, u8*, 0x16) = 4;
        }
    }
}
