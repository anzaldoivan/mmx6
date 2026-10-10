#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_80060964(int mode);
void func_800624A4(s32);
s32 func_80062594(s32*, s32**);
void func_80068EB4(s32);
void func_8006900C(s32, s32);
extern void func_80069088(X4_u_long* buf, int size);
void func_80069574(s32, s32, s32);
extern s32 D_800E2EB0;
extern s32 D_800E2EC0[];
extern s32 D_800E2EC8;
extern s32 D_800E2ECC;
extern s32 D_800E2ED0;
extern s32 D_800E2ED8;
extern s32 D_800E2EE8[];
extern s32 D_800E2F08;
extern s32 D_800E2F0C;
extern X4_RECT D_800E2F10;
extern u32* D_800E2F18;
extern s32 D_800E2F1C;
extern s32 D_800E2F20;
extern u32 D_800E2F24;
extern u32 D_800E2F28;
extern s32 D_800E2F30;
extern s32 D_800E2F34;

s32 func_8001B184(s32 arg0, s32 arg1) {
    s32 sp10;
    s32* sp14;
    s32 ret;
    s32 t;
    u32 x;
    s32* p;
    s32 y;
    s32 n;
    s16 w;
    u32 i;

    i = 0;
    while (func_80062594(&sp10, &sp14) != 0) {
        func_80060964(0);
        i++;
        if (i >= 0x259) {
            return 1;
        }
    }
    w = 0x10;
    p = D_800E2EE8;
    D_800E2F10.x = arg0;
    D_800E2F10.y = arg1;
    D_800E2F08--;
    x = ((u16*)p)[8];
    D_800E2F30 = x;
    D_800E2F34 = ((u16*)p)[9];
    D_800E2EB0 = p[2];
    ret = (u32)p[2] >= (u32)D_800E2ECC;
    if (D_800E2ED0 != 0) {
        w = 0x18;
    }
    D_800E2F10.w = w;
    D_800E2F24 = 0;
    D_800E2F28 = x >> 4;
    D_800E2F10.h = D_800E2F34;
    D_800E2F18 = (u32*)D_800E2EC8;
    {
        s32 z = ((u16*)p)[9];
        s32 u;
        D_800E2F20 = D_800E2ED0 != 0 ? (u = z << 2, (z << 3) + u) : z * 8;
    }
    if (D_800E2F0C == 0) {
        D_800E2F1C = 0;
    } else {
        s32 u;
        y = D_800E2F34;
        D_800E2F1C = D_800E2ED0 != 0 ? (u = y << 2, (y << 3) + u) : y * 8;
    }
    func_80068EB4(1);
    func_8006900C(D_800E2EC0[D_800E2ED8], D_800E2ED0);
    do {
        n = D_800E2F20;
    } while (0);
    func_80069088((X4_u_long*)D_800E2EC8, n);
    D_800E2EE8[0] = sp14[0];
    D_800E2EE8[1] = sp14[1];
    D_800E2EE8[2] = sp14[2];
    D_800E2EE8[3] = sp14[3];
    D_800E2EE8[4] = sp14[4];
    D_800E2EE8[5] = sp14[5];
    t = D_800E2ED8 == 0;
    D_800E2ED8 = t;
    D_800E2EE8[6] = sp14[6];
    D_800E2EE8[7] = sp14[7];
    ((u16*)D_800E2EE8)[8] = (((u16*)D_800E2EE8)[8] + 8) / 16 * 16;
    ((u16*)D_800E2EE8)[9] = (((u16*)D_800E2EE8)[9] + 8) / 16 * 16;
    func_80069574(sp10, D_800E2EC0[t], t);
    func_800624A4(sp10);
    return ret;
}
