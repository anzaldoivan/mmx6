#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003F4C4(struct X4_PlayerObj* self, s32 animation);

s32 func_8003B5B8(void* arg0) {
    func_8003F4C4(arg0, 0xB);
    if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
        M2C_FIELD(arg0, s32*, 0x20) = -M2C_FIELD(arg0, s32*, 0xF4);
    } else {
        M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0xF4);
    }
    M2C_FIELD(arg0, s8*, 0x8A) = 4;
    M2C_FIELD(arg0, s8*, 0x67) = -1;
    M2C_FIELD(arg0, s8*, 5) = 0xB;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s8*, 6) = 1;
    M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
}
