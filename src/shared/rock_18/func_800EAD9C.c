#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK func_8002B838();
void* func_8002C530();
void func_800EC114(void);
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern u16 D_800C456C[];
extern s8 D_800CD3F9;
extern struct X4_MiscObj D_800E2F90;
extern void* D_800F1744;

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define AB_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define AB_SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800EAD9C(u8* arg0) {
    s32 t;
    register s32 f asm("$2");
    s32 i;
    u8* obj;

    t = func_8001C5EC((u8)D_800E2F90.unk6);
    if (t != 0) {
        register s32 one asm("$4") = 1;
        register s32 two asm("$3") = 2;
        if (t == one) {
            AB_B(arg0, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            AB_B(arg0, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        AB_B(arg0, 3) = one;
        do {
            D_80097427 = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    if (D_800C456C[2] & 0x1000) {
        u8* e = (u8*)&D_80097420;
        if (e[7] == 0) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val += 0x3BC;
            }
            {
                u8* e2 = (u8*)&D_80097420;
                e2[7] = 7;
            }
        } else {
            s32 y = D_800E2F90.y_pos.val;
            e[7]--;
            D_800E2F90.y_pos.val = y - 0x3BC;
        }
        func_800EC114();
    }
    if (D_800C456C[2] & 0x4000) {
        u8* e = (u8*)&D_80097420;
        if (e[7] == 7) {
            for (i = 0; i < 7; i++) {
                D_800E2F90.y_pos.val -= 0x3BC;
            }
            {
                u8* e2 = (u8*)&D_80097420;
                e2[7] = 0;
            }
        } else {
            s32 y = D_800E2F90.y_pos.val;
            e[7]++;
            D_800E2F90.y_pos.val = y + 0x3BC;
        }
        func_800EC114();
    }
    if (D_800C456C[2] & 0x10) {
        func_80016C48(0, 0x22, 0);
        func_8002B838();
        D_800CD3F9 = 4;
        return;
    }
    if ((D_800C456C[2] & 0x40) && *(u8*)D_800E2F90.y_pos.val != 0xFF) {
        func_80016C48(0, 0x22, 0);
        D_800E2F90.unk7 = D_80097427;
        obj = func_8002C530();
        if (obj != 0) {
            AB_B(obj, 0) = 1;
            AB_B(obj, 1) = 0x2D;
            AB_SB(obj, 2) = -0x41;
        }
        D_800F1744 = obj;
        D_800E2F90.x_pos.bytes[2] = 3;
        AB_H(arg0, 0xA) = 1;
        AB_B(arg0, 3) = 4;
        AB_B(arg0, 1)++;
        func_800EC114();
    }
}

#undef AB_B
#undef AB_H
#undef AB_SB
