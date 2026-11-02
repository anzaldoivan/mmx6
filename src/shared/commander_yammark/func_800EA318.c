#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern void (*D_800F70F0[])(s8*);

#define SPAD (*(u8**)0x1F80004C)

void func_800EA318(s8* arg0) {
    s32 v;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    func_80017A04();
    D_800F70F0[arg0[5]](arg0);
    v = check_enemy_hits(arg0);
    if (v > 0) {
        SPAD[0x87] = 1;
    } else if (v < 0) {
        func_80049E50(arg0);
        func_8004E654((struct X4_BaseObj*)arg0, 0x12);
        arg0[4] = 2;
        return;
    } else {
        SPAD[0x87] = 0;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x50, 0xA0) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
    } else {
        arg0[4] = 3;
    }
}
