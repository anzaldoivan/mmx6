#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8003EB0C(void* arg0, s32 arg1);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_U32(p, o) (*(u32*)((u8*)(p) + (o)))

void func_8003EEE4(void* arg0) {
    register s16* hp asm("$16");
    s32 n;
    register u32 b asm("$6");
    u32 x;
    s32 c;
    s32 m;
    u8 k;

    if (F_S8(arg0, 0x93) == 0) {
        F_S8(arg0, 0x9B) = 0;
        return;
    }
    if (!(F_U16(arg0, 0x7C) & 0x10)) {
        return;
    }
    if (F_S8(arg0, 0x9B) == 2) {
        return;
    }
    k = F_U8(arg0, 0xE7);
    if (k != 1 && k != 4) {
        x = 0x5A;
        if (k != 3) {
            return;
        }
    }
    hp = (s16*)((u8*)arg0 + 0xA8);
    hp += F_S8(arg0, 0x93);
    if (func_8003EB0C(arg0, (s8)(F_U8(arg0, 0x93) + 9)) > *hp) {
        return;
    }
    b = x;
    c = F_U8(arg0, 0x9D) + 1;
    F_U8(arg0, 0x9D) = c;
    n = 0x19;
    do {
    } while (0);
    if (F_U32(arg0, 0xEC) & 0x100000) {
        b >>= 1;
        n = 0xC;
    }
    m = c & 0xFF;
    if (m == n) {
        func_80016C48(1, 7, arg0);
        F_S8(arg0, 0x9B) = 1;
        return;
    }
    if (m == b) {
        F_S8(arg0, 0x9B) = 2;
    }
}
