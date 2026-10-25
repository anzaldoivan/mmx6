#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK func_8002B838();
void* func_8002C530();
void func_800ED45C();
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern u16 D_800C456C[];
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EBB30(u8* arg0) {
    s32 ret;
    s32 done;
    u8 old;
    u8 i;
    u8* obj;

    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

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
    old = D_80097420.unk7;
    if (D_800C456C[2] & 0x1000) {
        if (old == 0) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val += 0x3BC;
            }
            D_80097420.unk7 = 7;
        } else {
            D_800E2F90.y_pos.val -= 0x3BC;
            D_80097420.unk7 = old - 1;
        }
        func_800ED45C();
    }
    if (D_800C456C[2] & 0x4000) {
        if ((u8)D_80097420.unk7 == 7) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val -= 0x3BC;
            }
            D_80097420.unk7 = 0;
        } else {
            D_80097420.unk7 = D_80097420.unk7 + 1;
            D_800E2F90.y_pos.val += 0x3BC;
        }
        func_800ED45C();
    }
    if ((u8)D_80097420.unk7 != old) {
        func_80016C48(0, 0xC, 0);
    }
    if (D_800C456C[2] & 0x10) {
        func_80016C48(0, 0x22, 0);
        ((void (*)())func_8002B838)();
        arg0[1] = 6;
        arg0[2] = 6;
        arg0[3] = 0;
        return;
    }
    if (D_800C456C[2] & 0x40) {
        func_80016C48(0, 0x22, 0);
        D_800E2F90.unk7 = D_80097420.unk7;
        obj = func_8002C530();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2D;
            ((s8*)obj)[2] = -0x41;
        }
        *(u8**)(D_800F366C + 0x1290) = obj;
        D_800E2F90.x_pos.bytes[2] = 3;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[3] = 9;
        arg0[1] = arg0[1] + 1;
        func_800ED45C();
    }
}
