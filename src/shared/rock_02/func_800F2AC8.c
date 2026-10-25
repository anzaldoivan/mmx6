#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK move_object(s32);
extern u16 D_8009721A;
extern u8 D_800FB810[];

void func_800F2AC8(void* arg0) {
    u8 t;

    t = SPAD4C[0x8B];
    if (t != 0) {
        SPAD4C[0x8B] = t - 1;
        if (!(SPAD4C[0x8B] & 3)) {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) | 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        }
        if (SPAD4C[0x8B] == 0) {
            SPAD4C[0x8B] = 0x78;
        }
    }
    ((void (*)(s32))move_object)((s32)arg0);
    {
        // !FAKE: depin: dropping it breaks the match (67/71)
        register s32 lim asm("$3") = (s16)D_8009721A + 0x40;
        // !FAKE: depin: dropping it breaks the match (64/71)
        register s32 c asm("$4") = M2C_FIELD(arg0, s16*, 0xE) < lim;
        if (!c) {
            M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
            SPAD4C[0x89] = 0x3C;
            t = ++SPAD4C[0x85];
            M2C_FIELD(arg0, u8*, 5) = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
            M2C_FIELD(arg0, u8*, 6) = 0;
        }
    }
}
