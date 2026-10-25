#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80031DA8();
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
extern struct X4_PlayerObj g_Player;
extern void (*D_800F7414[])(s8*);

void func_800EBF6C(s8* arg0) {
    struct X4_PlayerObj* p;
    s8 temp_s0;
    u8 s1;
    u8 s0;
    s32 var_v0;

    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    temp_s0 = arg0[0x5C];
    if (func_80031474(arg0) < 0) {
        func_80049E50(arg0);
        ((s32(*)(struct X4_BaseObj*, s8))func_8004E654)(
            (struct X4_BaseObj*)arg0, 0x10);
        arg0[4] = 2;
        return;
    }
    if (arg0[0x5C] != temp_s0) {
        func_80016C48(2, 8, arg0);
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[0x47] = 0;
        arg0[6] = 1;
        arg0[7] = 0;
        *(u16*)(arg0 + 0x42) |= 0x8000;
    }
    D_800F7414[arg0[6]](arg0);
    if (func_8002CBFC((s32)arg0, 0x40, 0x40) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
    } else {
        arg0[4] = 3;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    ((void (*)(M2C_UNK*))func_8002F288)((M2C_UNK*)arg0);
    p = &g_Player;
    if (((u8*)p)[0xE5] == 0) {
        if (arg0[6] != 4 && arg0[6] != 1) {
            s1 = p->unk72;
            p->unk72 = 8;
            s0 = arg0[0x72];
            func_80031DA8(arg0);
            p->unk72 = s1 | (arg0[0x72] & 8);
            if ((s0 & 8) && !(arg0[0x72] & 8)) {
                p->unk72 |= 8;
            }
        }
    }
    func_80030ECC(arg0);
    if ((u8)arg0[0x70] & 8) {
        arg0[0x67] = 0;
        return;
    }
    var_v0 = *(s32*)(arg0 + 0x24);
    if (var_v0 < 0) {
        var_v0 = -1;
    } else {
        var_v0 = 1;
    }
    arg0[0x67] = var_v0;
}
