#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800F6254[])(s8*);

void func_800EC974(s8* arg0) {
    s32 v;

    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    D_800F6254[arg0[5]](arg0);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_80030ECC(arg0);
    if (check_enemy_hits(arg0) < 0) {
    turn:
        func_80049E50(arg0);
        goto next;
    }
    if (*(u8*)(arg0 + 0x70) == 0) {
        func_8002F288((M2C_UNK*)arg0);
        if (*(u8*)(arg0 + 0x70) == 0) {
            goto move;
        }
    }
    if (*(u8*)(arg0 + 0x93) == 1) {
        goto turn;
    }
move:
    v = *(s32*)(arg0 + 0x20);
    v = (v < 0) ? -v : v;
    arg0[0x70] = 0;
    if (0x40000 < v) {
        *(s32*)(arg0 + 0x28) = 0;
    }
    if (func_8002CBFC(arg0, 0x40, 0x20) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
next:
    arg0[4]++;
}
