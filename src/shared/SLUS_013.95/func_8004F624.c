#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_8004A2B4(M2C_UNK, M2C_UNK, void*, M2C_UNK, M2C_UNK);
extern s32 D_80078CB8;
extern s32 D_80078CBC;

void func_80049E50(struct X4_MainObj* self);
void func_8004F624(u8* arg0) {
    s8 t;
    register s32 f asm("$2");

    ((M2C_UNK(*)())func_80017A04)();
    func_8002CCB0(arg0, 0x10, 0x10);
    t = *(s8*)(arg0 + 2);
    if (t == 0) {
        if (*(s8*)(arg0 + 0x45) == 1) {
            arg0[3] = 0;
            arg0[4]++;
            return;
        }
    } else if (t == 1) {
        if (*(s8*)(arg0 + 5) == 0) {
            arg0[3] = 0;
            if (--*(s16*)(arg0 + 0x88) == 0) {
                *(s32**)(arg0 + 0x50) = &D_80078CB8;
                *(s32**)(arg0 + 0x68) = &D_80078CBC;
                arg0[3] = 1;
                arg0[5]++;
            }
            goto tail;
        }
        func_8002D2B0(arg0);
        f = arg0[0x70];
        if (f == 0) {
            func_8002EE10(arg0);
            if (arg0[0x70] == 0) {
                goto tail;
            }
        }
        func_80049D90(arg0);
        arg0[3] = 0;
        arg0[4]++;
        return;
    } else if (t == 16) {
        if (++*(s8*)(arg0 + 6) == 8) {
            func_8004A2B4(0, 0, arg0, 0, 1);
            arg0[6] = 0;
        }
        if (arg0[0x70] != 0 || (func_8002EE10(arg0), arg0[0x70] != 0) ||
            func_80031474(arg0) < 0 || func_80030ECC(arg0) != 0) {
            ((M2C_UNK(*)())func_80049E50)(arg0);
            arg0[4] = 2;
            return;
        }
        ((M2C_UNK(*)())func_80017A04)(arg0);
        func_8002D230(arg0);
        if (func_8002CBFC(arg0, 0x10, 0x10) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
        goto inc;
    }
tail:
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
    inc:
        arg0[4]++;
    }
}
