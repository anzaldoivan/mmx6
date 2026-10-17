#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530();
s32 func_8002D2D4();

void func_800477E4(u8 count, u8* src, void* parent) {
    void* obj;
    s8 t;
    u8 b;

    while (count != 0) {
        obj = func_8002C530();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0x0) = 0x41;
            t = M2C_FIELD(parent, s8*, 0x0);
            if (t == 0x61) {
                M2C_FIELD(obj, u8*, 0x0) = t;
                t = M2C_FIELD(parent, s8*, 0x0);
            }
            if (t == 0x21) {
                M2C_FIELD(obj, u8*, 0x0) = t;
            }
            {
                s32 x = M2C_FIELD(parent, u8*, 0x0);
                M2C_FIELD(obj, u8*, 0x1) = 3;
                M2C_FIELD(obj, u8*, 0x2) = 0;
                M2C_FIELD(obj, u8*, 0x0) |= x & 0x10;
            }
            M2C_FIELD(obj, u8*, 0x15) = func_8002D2D4() & 0x40;
            M2C_FIELD(obj, u8*, 0x4) = 0;
            M2C_FIELD(obj, u8*, 0x5) = 0;
            M2C_FIELD(obj, u8*, 0x6) = 0;
            M2C_FIELD(obj, s32*, 0x8) =
                M2C_FIELD(parent, s32*, 0x8) + ((func_8002D2D4() & 3) << 16);
            M2C_FIELD(obj, s32*, 0xC) =
                M2C_FIELD(parent, s32*, 0xC) + ((func_8002D2D4() & 3) << 16);
            b = *src++;
            M2C_FIELD(obj, void**, 0x54) = parent;
            M2C_FIELD(obj, u8*, 0x58) = b;
        }
        count--;
    }
}
