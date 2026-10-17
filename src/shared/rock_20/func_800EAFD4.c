#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_80097420;
extern u16 D_800C456C[];

void func_800EAFD4(u8* arg0) {
    u8 cur;
    struct X4_EngineObj* eng = &D_80097420;
    s32 one;

    if (((s8*)eng)[4] != 0) {
        return;
    }
    one = 1;
    if (D_800C456C[2] & 0x1000) {
        func_80016C48(0, 0xC, 0);
        cur = eng->unk7;
        if (cur == 0) {
            eng->unk7 = one;
        } else {
            eng->unk7 = cur - 1;
        }
    } else if (D_800C456C[2] & 0x4000) {
        func_80016C48(0, 0xC, 0);
        cur = eng->unk7;
        if (cur == one) {
            eng->unk7 = 0;
        } else {
            eng->unk7 = cur + 1;
        }
    }
    if (D_800C456C[2] & 0x40) {
        func_80016C48(0, 0x22, 0);
        arg0[2]++;
    }
}
