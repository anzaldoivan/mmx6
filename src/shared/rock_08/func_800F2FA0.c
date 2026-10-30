#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

s32 set_animation(void*, s32);
M2C_UNK func_80017A04();
void func_800F32A8(struct X4_AnimatedObj* self);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800F5DE8;
extern M2C_UNK D_800F5DEC;

void func_800F2FA0(void* arg0) {

    FX(arg0, u16, 0x7C) = FX(arg0, u16, 0x7C) + 1;
    ((void (*)())func_80017A04)();
    if (FX(arg0, s16, 0x7C) >= 0x29) {
        if (FX(arg0, u16, 0x80) & 1) {
            FX(arg0, u16, 0x80) = 0x3C;
        } else {
            FX(arg0, u16, 0x80) = 0x3B;
        }
        func_800F32A8(arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        FX(arg0, s8, 0x5) = 3;
        FX(arg0, s8, 0x6) = 0;
        FX(arg0, void*, 0x50) = &D_800F5DE8;
        FX(arg0, void*, 0x54) = &D_800F5DEC;
        FX(arg0, void*, 0x58) = &D_8007433C;
    }
}
