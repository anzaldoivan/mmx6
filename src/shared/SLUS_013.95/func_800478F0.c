#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530();
s32 func_8002D2D4();

void func_800478F0(u8 count, u8* src, void* parent, u16 kind, s32 arg4,
                   s32 arg5) {
    void* obj;
    s32 t;

    while (count != 0) {
        obj = func_8002C530();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0x0) = 0x41;
            M2C_FIELD(obj, u8*, 0x1) = 3;
            M2C_FIELD(obj, u8*, 0x2) = 1;
            M2C_FIELD(obj, u8*, 0x15) = func_8002D2D4() & 0x40;
            M2C_FIELD(obj, u8*, 0x4) = 0;
            M2C_FIELD(obj, u8*, 0x5) = 0;
            M2C_FIELD(obj, u8*, 0x6) = 0;
            M2C_FIELD(obj, s32*, 0x8) =
                M2C_FIELD(parent, s32*, 0x8) + (func_8002D2D4() & 3) + arg4;
            M2C_FIELD(obj, s32*, 0xC) =
                M2C_FIELD(parent, s32*, 0xC) + (func_8002D2D4() & 3) + arg5;
            t = *src++;
            M2C_FIELD(obj, void**, 0x54) = parent;
            M2C_FIELD(obj, u16*, 0x42) = kind;
            M2C_FIELD(obj, u8*, 0x58) = t;
            M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
            M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
            M2C_FIELD(obj, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
        }
        count--;
    }
}
