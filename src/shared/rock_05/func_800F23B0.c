#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);                 /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                        /* extern */
M2C_UNK func_8002D2B0(void*);                   /* extern */
extern u16 D_800F447E;
#define D_800F447E_S (*(s16*)&D_800F447E)

void func_800F23B0(void* arg0) {
    s16 y;

    ((void (*)(void*))func_8002D2B0)(arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    y = M2C_FIELD(arg0, s16*, 0xA);
    if ((D_800F447E_S + 0x11F0) < y) {
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFF80000;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        func_80016C48(2, 2, arg0);
        func_80012D9C(4);
        return;
    }
    if (y < (D_800F447E_S + 0xFA0)) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        func_80016C48(2, 2, arg0);
        func_80012D9C(4);
    }
}
