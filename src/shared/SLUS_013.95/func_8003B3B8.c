#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_8003F4C4(struct X4_PlayerObj* self, s32 animation);

void func_8003B3B8(void* arg0) {
    // !FAKE: flag byte lives in the second return register
    register s32 t asm("$3");

    func_8003F4C4(arg0, 0xD);
    func_80016C48(1, 4, arg0);
    t = M2C_FIELD(arg0, u8*, 0x89);
    {
        // !FAKE: the -1 constant lives in the first return register
        register s32 m asm("$2") = -1;
        M2C_FIELD(arg0, s8*, 0x8C) = m;
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x86) = 0;
    M2C_FIELD(arg0, s8*, 0x8A) = 8;
    if (t & 1) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    }
    M2C_FIELD(arg0, s8*, 5) = 9;
    M2C_FIELD(arg0, s8*, 6) = 0;
}
