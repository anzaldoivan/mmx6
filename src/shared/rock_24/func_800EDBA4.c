#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04(void*);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_80030ECC(void*, s16);              /* extern */
#define func_80030ECC (*(M2C_UNK(*)(void*)) & func_80030ECC)
s32 check_enemy_hits(void*);                     /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
M2C_UNK func_80049E50(void*);                    /* extern */
extern M2C_UNK D_800F6C80;
extern void (*D_800F6DC4[])(struct X4_MainObj*);

void func_800EDBA4(struct X4_MainObj* arg0) {
    if (check_enemy_hits(arg0) < 0) {
        u8* p = *(u8**)((u8*)arg0 + 0x80);
        p[7] = p[7] - 1;
        func_80049E50(arg0);
        func_800477E4(3, &D_800F6C80, arg0);
        arg0->state = 2;
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
    }
    D_800F6DC4[arg0->unk5](arg0);
    func_8002D230(arg0);
    func_80017A04(arg0);
}
#undef func_80030ECC
