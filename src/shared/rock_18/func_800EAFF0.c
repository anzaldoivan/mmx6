#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void func_800EC114(void);
void func_800ECE54(void);
extern u8 D_80097427;
extern u16 D_800C456C[];
extern struct X4_EngineObj D_800CCED0;
extern struct X4_MiscObj D_800E2F90;
extern void* D_800F1744;

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800EAFF0(u8* arg0) {
    register u8* self asm("$17") = arg0;
    s32 t;
    s32 f;
    u8* p;
    s32 n;

    arg0 = 0;
    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    t = func_8001C5EC((u8)D_800E2F90.unk6);
    if (t != 0) {
        register s32 one asm("$4") = 1;
        register s32 two asm("$3") = 2;
        if (t == one) {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        AB_B(self, 3) = one;
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
    if (D_800C456C[2] & 0xA000) {
        func_80016C48(0, 0xC, 0);
        D_800CCED0.unkA ^= 1;
    }
    if (D_800C456C[2] & 0x40) {
        func_80016C48(0, 0x22, 0);
        p = D_800F1744;
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (D_800CCED0.unkA == 0) {
            AB_B(self, 1)++;
            func_800ECE54();
            func_800139F4(8);
            return;
        }
        AB_B(self, 3) = 3;
        AB_B(self, 1)--;
        func_800EC114();
    }
}

#undef AB_B
