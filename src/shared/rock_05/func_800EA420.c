#include "common.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s32);
extern s8 D_80097174;
extern void (*D_800F3D58[])(s8*);

void func_800EA420(s8* arg0) {
    s32 r;

    D_800F3D58[arg0[5]](arg0);
    r = check_enemy_hits(arg0);
    if (r < 0) {
        func_8004E654(arg0, 0x12);
        func_80049E50(arg0);
        goto end;
    }
    if (D_80097174 == 1) {
    end:
        arg0[4] = 2;
        return;
    }
    if (r == 0x7F) {
        if ((s8)((u8*)arg0)[0x85]++ >= 5) {
            arg0[5] = 2;
        }
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
    } else {
        func_8002CA54(arg0);
    }
}
