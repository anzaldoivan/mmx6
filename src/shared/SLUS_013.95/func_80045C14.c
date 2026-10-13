#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern s16 D_800761FC[];
extern u8 D_8007620C[];

void func_80045C14(void* arg0) {
    s16 a;
    s16 b;
    s32 i;
    u16 x;
    u16 y;
    s8 t;
    void* p;

    p = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(p, s8*, 0x91) != 0) {
        M2C_FIELD(arg0, u8*, 4) = 3;
        return;
    }
    ((void (*)())func_80017A04)(arg0);
    i = (M2C_FIELD(arg0, s8*, 2) - 1) * 4;
    a = *(s16*)(i + (u8*)D_800761FC);
    b = *(s16*)((u8*)D_800761FC + i + 2);
    t = ++M2C_FIELD(arg0, u8*, 0x8E);
    if (t >= 20) {
        {
            u8 v;
            M2C_FIELD(p, u8*, 0x8C)++;
            M2C_FIELD(arg0, s16*, 0xA) = a;
            M2C_FIELD(arg0, s16*, 0xE) = b;
            v = D_8007620C[M2C_FIELD(arg0, s8*, 2) - 1];
            M2C_FIELD(arg0, u8*, 5)++;
            M2C_FIELD(arg0, u8*, 0x47) = v;
        }
        return;
    }
    x = M2C_FIELD(arg0, u16*, 0x92);
    y = M2C_FIELD(arg0, u16*, 0x94);
    M2C_FIELD(arg0, s16*, 0xA) = x + (t * (s16)(a - x)) / 20;
    M2C_FIELD(arg0, s16*, 0xE) = y + (t * (s16)(b - y)) / 20;
}
