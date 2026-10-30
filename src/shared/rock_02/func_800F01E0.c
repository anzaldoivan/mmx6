#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_80040488(M2C_UNK);
extern s8 D_800CCEF4;

void func_800F01E0(void* arg0) {
    s32 base;
    // !FAKE: keeps the table word in the third argument register
    register s32 off asm("$6");
    s32 idx;

    if (M2C_FIELD(arg0, s16*, 0xE) < 0x131) {
        M2C_FIELD(arg0, s16*, 0xE) = 0x130;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        base = SPAD20;
        off = *(s32*)(idx * 4 + base);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0, off);
        func_80040488(0);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 3;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
