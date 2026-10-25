#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
extern s32 D_800FAF08;

void func_800EDED4(void* arg0) {
    if (M2C_FIELD(arg0, void**, 0x68) == 0 &&
        M2C_FIELD(arg0, s16*, 0xE) >= 0x120) {
        M2C_FIELD(arg0, void**, 0x68) = &D_800FAF08;
    }
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        func_80016C48(2, 5, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        {
            s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
            s32 base = SPAD20;
            // !FAKE: depin: dropping it breaks the match (35/64)
            register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
            M2C_FIELD(arg0, s32*, 0x3C) = base + off;
            ((void (*)(void*, s32, s32))func_800179A4)(arg0, 8, off);
        }
        func_80029478(0x14, 4, 2);
        {
            // !FAKE: depin: dropping it breaks the match (61/64)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 7) = 0;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
    M2C_FIELD(arg0, s32*, 0x24) -= M2C_FIELD(arg0, s32*, 0x2C);
    func_80017A04(arg0);
    ((void (*)(void*))move_object)(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
