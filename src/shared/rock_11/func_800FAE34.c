#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
s32 func_8002D2D4();

#define F(p, type, off) M2C_FIELD(p, type*, off)

void func_800FAE34(void* arg0) {
    void* parent;
    s32 angle;

    parent = F(arg0, void*, 0x50);
    func_800179D0(arg0, 0x16, func_8002D2D4() & 3);
    angle = (F(arg0, s16, 0x5A) + 0x800) & 0xFFF;
    F(arg0, s16, 0xA) = F(parent, s16, 0xA) + (rcos(angle) >> 6);
    F(arg0, s16, 0xE) = F(parent, s16, 0xE) + (-rsin(angle) >> 6);
    F(arg0, u8, 0x6)++;
    F(arg0, s16, 0x56) = (func_8002D2D4() & 7) + 5;
    F(arg0, s16, 0x58) = (u8)((u32)func_8002D2D4() % 3);
}
