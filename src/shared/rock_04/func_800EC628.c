#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_8002F288(M2C_UNK*);
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
s32 func_800EB96C(struct X4_PlayerObj*, s16, s16);

void func_800EC628(void* arg0) {
    s32 a;
    s32 b;

    ((void (*)(void*))func_8002D2B0)(arg0);
    if (FX(arg0, s16, 0xE) >= 0x510) {
        ((void (*)(void*))func_8002F288)(arg0);
        {
            s16 hx =
                FX(arg0, u8, 0x82) + (FX(arg0, s16, 0xA) + FX(arg0, s8, 0x80));
            s16 hy =
                FX(arg0, u8, 0x83) + (FX(arg0, s16, 0xE) + FX(arg0, s8, 0x81));
            a = func_800EB96C(arg0, hx - 1, hy - 1);
        }
        {
            s16 hx =
                FX(arg0, s16, 0xA) + FX(arg0, s8, 0x80) - FX(arg0, u8, 0x82);
            s16 hy =
                FX(arg0, u8, 0x83) + (FX(arg0, s16, 0xE) + FX(arg0, s8, 0x81));
            b = func_800EB96C(arg0, hx, hy - 1);
        }
        if (((u8(*)(void*, s32, s16))func_80030234)(
                arg0, FX(arg0, s16, 0xA) - 0x20, FX(arg0, s16, 0xE)) != 0 &&
            ((u8(*)(void*, s32, s16))func_80030234)(
                arg0, FX(arg0, s16, 0xA) + 0x20, FX(arg0, s16, 0xE)) != 0) {
            FX(arg0, s8, 0x60) = 0x7F;
        }
        if (a != 0 || b != 0) {
            FX(arg0, s32, 0xC) = FX(arg0, s32, 0x1C);
            return;
        }
        if (FX(arg0, u8, 0x70) & 8) {
            FX(arg0, s8, 0x6) = 7;
            FX(arg0, s16, 0xC) = 0;
            FX(arg0, s16, 0x8) = 0;
            FX(arg0, s32, 0x20) = 0;
            FX(arg0, s32, 0x24) = 0;
            FX(arg0, u16, 0xE) = (FX(arg0, u16, 0xE) & 0xFFF0) | 8;
            if (FX(arg0, s8, 0x3) != 0) {
                func_80016C48(2, 0x11, arg0);
            }
        }
    }
}
