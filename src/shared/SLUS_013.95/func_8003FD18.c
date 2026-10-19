#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003BA04(void*, M2C_UNK);
extern s8 D_800CCEEC;

void func_8003FD18(void* arg0) {
    // !FAKE: pins the shared constant one to the register retail uses
    register s32 one asm("$3");
    ((void (*)(void*, s32))func_8003BA04)(arg0, 0x5F);
    one = 1;
    M2C_FIELD(arg0, u8*, 0xE0) = 2;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 0x7A) = one;
    D_800CCEEC = one;
    M2C_FIELD(arg0, u8*, 0x67) = one;
    M2C_FIELD(arg0, u8*, 5) = 0x29;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
