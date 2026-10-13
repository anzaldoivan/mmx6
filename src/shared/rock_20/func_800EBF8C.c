#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void func_800ED45C();
extern u8 D_80097427;
extern u16 D_800C456C[];
extern struct X4_EngineObj D_800CCED0;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EBF8C(u8* arg0) {
    s32 ret;
    s32 done;
    s32 n;
    u8* p;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        register s32 one asm("$4") = 1;
        register s32 two asm("$3") = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097427 = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    if (D_800C456C[2] & 0xA000) {
        func_80016C48(0, 0xC, 0);
        D_800CCED0.unkA ^= 1;
    }
    if (D_800C456C[2] & 0x40) {
        func_80016C48(0, 0x22, 0);
        p = *(u8**)(D_800F366C + 0x1290);
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (D_800CCED0.unkA == 0) {
            D_800E2F90.x_pos.bytes[2] = 3;
            arg0[3] = 0xB;
            arg0[1] = arg0[1] + 1;
            return;
        }
        arg0[3] = 8;
        arg0[1] = arg0[1] - 2;
        func_800ED45C();
    }
}
