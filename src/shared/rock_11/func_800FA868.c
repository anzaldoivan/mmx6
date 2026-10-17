#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FD46C[];
extern s32 D_800FD478[];

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800FA868(void* arg0) {
    F(s32*, 0x50) = D_800FD46C;
    F(s32, 0x54) = 0;
    F(s32*, 0x68) = D_800FD478;
    {
        // !FAKE: pin the byte test into the first return register
        register s32 t asm("$2") = F(u8, 0x15);

        if (t == 0) {
            F(s32, 0x20) = 0xFFFEC000;
        } else {
            F(s32, 0x20) = 0x14000;
        }
    }
    if ((F(u8, 0x2) & 0xF) == 1) {
        F(s32, 0x20) = F(s32, 0x20) * 2;
    }
    F(s32, 0x24) = 0;
    F(u8, 0x6) = F(u8, 0x6) + 1;
}
