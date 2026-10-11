#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F9EB4(u8* arg0, u8 arg1, s16 arg2);

void func_800F8E50(void* arg0) {
    s8 kind;
    s32 one;

    kind = M2C_FIELD(arg0, s8*, 0x45);
    one = 1;
    if (kind == one) {
        func_80016C48(2, 0x25, arg0);
        func_80016C48(2, 0x47, arg0);
        func_800F9EB4(arg0, 0x30, 0);
        func_800F9EB4(arg0, 0x30, 0x400);
        func_800F9EB4(arg0, 0x30, 0x800);
        func_800F9EB4(arg0, 0x30, 0xC00);
        func_800F9EB4(arg0, 0x30, 0x200);
        func_800F9EB4(arg0, 0x30, 0x600);
        func_800F9EB4(arg0, 0x30, 0xA00);
        func_800F9EB4(arg0, 0x30, 0xE00);
    } else if (kind == 2) {
        s32 t;
        t = M2C_FIELD(arg0, u8*, 0x8C) - 1;
        M2C_FIELD(arg0, u8*, 0x8C) = t;
        if ((t << 24) == 0) {
            M2C_FIELD(arg0, u8*, 0x5) = 4;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        } else {
            ((void (*)(void*, s32))func_800179A4)(arg0, 1);
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 0x6) = one;
        }
    }
}
