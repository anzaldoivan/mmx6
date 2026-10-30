#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_800F0A78(void* arg0);
extern s8 D_800970A5;

#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
void func_800F2274(void* arg0) {
    if (--F_S32(arg0, 0x8C) == 0) {
        func_800F0A78(arg0);
        F_S32(arg0, 0x8C) = F_S32(arg0, 0x80) / 40 + 3;
    }
    if (--F_S32(arg0, 0x90) == 0) {
        ((void (*)(s32, s32, s32))func_80029478)(4, 2, 2);
        F_S32(arg0, 0x90) = F_S32(arg0, 0x80) / 10 + 10;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x60, 0x60);
    if (D_800970A5 == 0x14) {
        if (--F_S32(arg0, 0x80) == 0) {
            ((void (*)(s32, s32, s32))func_80029478)(0x28, 4, 2);
            F_S32(arg0, 0x8C) = 3;
            F_S32(arg0, 0x90) = 0x27;
            ((void (*)(s32, s32, s32))open_text_box)(2, 0xFF, 0);
            F_U8(arg0, 5)++;
        }
    }
}
