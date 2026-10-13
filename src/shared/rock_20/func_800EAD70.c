#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern u16 D_800C456C[];

void func_800EAD70(u8* arg0) {
    u8 v;
    u8 cur;
    register u8* obj asm("$16") = arg0;
    register s32 two asm("$17") = 2;

    if (D_800C456C[2] & 0x1000) {
        func_80016C48(0, 0xC, 0);
        cur = D_80097420.unk7;
        if (cur == 0) {
            D_80097420.unk7 = two;
        } else {
            D_80097420.unk7 = cur - 1;
        }
    } else if (D_800C456C[2] & 0x4000) {
        func_80016C48(0, 0xC, 0);
        cur = D_80097420.unk7;
        if (cur == two) {
            D_80097420.unk7 = 0;
        } else {
            D_80097420.unk7 = cur + 1;
        }
    }
    if (D_800C456C[2] & 0x40) {
        func_80016C48(0, 0x22, 0);
        switch (D_80097427) {
        case 0:
            v = 6;
            break;
        case 1:
            v = 7;
            break;
        case 2:
            v = 9;
            break;
        default:
            return;
        }
        obj[1] = v;
        obj[2] = 0;
    }
}
