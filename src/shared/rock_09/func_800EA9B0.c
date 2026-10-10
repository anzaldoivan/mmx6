#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(s32);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);
extern s16 D_800970AA;
extern s16 D_800970AE;
extern u8 D_800CCF38;

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EA9B0(void* arg0) {
    func_80017A04(arg0);
    func_8002D2B0((s32)arg0);
    switch (B(arg0, 7)) {
    case 0:
        if (D_800970AE >= H(arg0, 0xE)) {
            func_800179A4(arg0, 9);
            if (D_800CCF38 >= 2) {
                UH(arg0, 0x88) = 8;
            } else {
                UH(arg0, 0x88) = 0x28;
            }
            W(arg0, 0x20) = 0;
            W(arg0, 0x24) = 0;
            B(arg0, 7)++;
        }
        break;
    case 1:
        if (--H(arg0, 0x88) == 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 2);
            if (D_800970AA >= H(arg0, 0xA)) {
                W(arg0, 0x20) = 0x40000;
            } else {
                W(arg0, 0x20) = -0x40000;
            }
            B(arg0, 7)++;
        }
        break;
    case 2:
        break;
    }
    if (func_80031474(arg0) < 0) {
        func_80049E50(arg0);
    } else {
        UH(arg0, 0x42) &= 0x7FFF;
        ((void (*)(void*))func_80030ECC)(arg0);
        if (UB(arg0, 0x70) != 0 || (func_8002EE10(arg0), UB(arg0, 0x70) != 0)) {
            func_80049D90(arg0);
            UB(arg0, 4)++;
            return;
        }
        if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
            func_8002CCB0(arg0, 0x10, 0x10);
            return;
        }
    }
    UB(arg0, 4)++;
}
