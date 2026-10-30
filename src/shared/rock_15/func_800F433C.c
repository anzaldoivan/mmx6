#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F3824(struct X4_MainObj*);
extern s8 D_800CCF5C;

void func_800F433C(void* arg0) {
    s8* obj = arg0;
    s8* other;
    s32 c;
    u16 t;
    s32 n;

    ((void (*)())func_80017A04)();
    if (D_800CCF5C / 2 < other[0x5C]) {
        t = *(u16*)(obj + 0x8C);
        n = t + 1;
        c = (s16)t < 0x5B;
    } else {
        t = *(u16*)(obj + 0x8C);
        n = t + 1;
        c = (s16)t < 0x33;
    }
    *(u16*)(obj + 0x8C) = n;
    if (c == 0) {
        obj[7] = 0xA;
        func_800F3824((struct X4_MainObj*)obj);
        ((void (*)(void*, s32))set_animation)(obj, 0xD);
        ((u8*)obj)[6]++;
    }
}
