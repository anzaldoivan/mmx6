#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230();
extern struct X4_PlayerObj D_800970A0;
extern s8 D_800970A2;

#define U8F(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8F(p, o) (*(s8*)((u8*)(p) + (o)))
#define S32F(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800447CC(void* arg0) {
    s32 var_v0;
    s32 var_v1;
    u8 t;
    u8 flags;

    func_8002D230(arg0);
    flags = U8F(arg0, 0x8F);
    if (flags != 0) {
        if (flags & 4) {
            S32F(arg0, 0x24) = 0xFFFD0000;
        } else if (flags & 8) {
            if (D_800970A0.unk2 != 0) {
                S32F(arg0, 0x24) = 0x30000;
                S32F(arg0, 0x2C) = 0x2000;
            } else {
                S32F(arg0, 0x24) = 0x60000;
                S32F(arg0, 0x2C) = 0x4000;
            }
        } else if (flags & 2) {
            S32F(arg0, 0x20) = 0x18000;
            U8F(arg0, 0x15) = 0x40;
        } else if (flags & 1) {
            S32F(arg0, 0x20) = 0xFFFE8000;
            U8F(arg0, 0x15) = 0;
        }
        S32F(arg0, 0x8) = S32F(arg0, 0x18);
        S32F(arg0, 0xC) = S32F(arg0, 0x1C);
        func_8002D230(arg0);
        {
            register s32 t asm("$2") = U8F(arg0, 0x90);
            U8F(arg0, 0x90) = t + 1;
            if (D_800970A0.unk2 != 0) {
                U8F(arg0, 0x90)++;
            }
        }
    }
    if (S8F(arg0, 0x98) != 0) {
        S8F(arg0, 0x98) = 0;
        U8F(arg0, 0x90)++;
        if (D_800970A2 != 0) {
            U8F(arg0, 0x90) += 8;
        }
    }
}
