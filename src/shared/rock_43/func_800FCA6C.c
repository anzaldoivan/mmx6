#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void* func_8002C458();
extern s16 D_800970AA;

void func_800FCA6C(void* arg0) {
    s8 t;
    void* p;

    t = M2C_FIELD(arg0, s8*, 0x45);
    if (t == 1) {
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = t;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
        p = func_8002C458();
        if (p != 0) {
            u8 b = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(p, u8*, 1) = 0x13;
            M2C_FIELD(p, u8*, 2) = 3;
            M2C_FIELD(p, void**, 0x7C) = arg0;
            M2C_FIELD(p, u8*, 0) = b;
        }
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x28) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 4);
        {
            s32 g = D_800970AA;
            if (M2C_FIELD(arg0, s16*, 0xA) < g) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
