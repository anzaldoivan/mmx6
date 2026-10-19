#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CD9C();
void func_8003D2BC(struct X4_PlayerObj* self);
void func_8003F4C4(struct X4_PlayerObj* self, s32 animation);

void func_8003B548(void* arg0) {
    func_8003F4C4(arg0, 0xF);
    if (M2C_FIELD(arg0, u8*, 0xE7) != 2) {
        func_8003D2BC(arg0);
    }
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x110);
    ((void (*)())func_8003CD9C)(arg0);
    M2C_FIELD(arg0, u8*, 5) = 0xB;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
