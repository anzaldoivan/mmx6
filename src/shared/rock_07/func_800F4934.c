#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8001750C(M2C_UNK, M2C_UNK);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F4144(void* arg0);
extern M2C_UNK D_800F907C;

void func_800F4934(u8* arg0) {
    s32 t;
    // !FAKE: depin: dropping it breaks the match (36/41)
    register s32 v asm("$2");

    func_8001750C(2, 0x14);
    func_80016C48(2, 0x21, arg0);
    func_80016C48(2, 0x77, arg0);
    func_800F4144(arg0);
    func_800179A4(arg0, 0x25);
    t = *(s8*)(arg0 + 0x8E);
    v = 4;
    arg0[0x60] = v;
    v = 1;
    if (t == v) {
        arg0[0x8E] = 0;
        *(s32**)(arg0 + 0x68) = &D_800F907C;
        *(u16*)(arg0 + 0xE) -= 0x1C;
    }
    *(s16*)(arg0 + 0x7C) = 0x5A;
    arg0[6]++;
}
