#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();
extern M2C_UNK D_800F6154;

void func_800EC648(void* arg0) {
    void* child;
    u8 i;

    for (i = 0; i < 2; i++) {
        child = func_8002C458();
        if (child != 0) {
            M2C_FIELD(child, u8*, 0) = 0x41;
            M2C_FIELD(child, u8*, 1) = 0x25;
            if (i == 0) {
                M2C_FIELD(child, u8*, 2) = 0;
            } else {
                M2C_FIELD(child, u8*, 2) = 2;
            }
            M2C_FIELD(child, void**, 0x7C) = arg0;
            {
                u16 t = M2C_FIELD(arg0, u16*, 0x42);
                M2C_FIELD(child, void**, 0x30) = &D_800F6154;
                M2C_FIELD(child, u16*, 0x42) = t;
            }
            M2C_FIELD(child, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(child, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
            M2C_FIELD(child, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(child, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(child, u8*, 0x16) = 4;
        }
    }
}
