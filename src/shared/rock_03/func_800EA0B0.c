#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

#define SP64 (*(u8**)(0x1F800064))
#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P50(p) (*(u8**)((u8*)(p) + 0x50))

void func_800EA0B0(u8* arg0) {
    u8* obj;
    register u8* par asm("$2");
    register s32 one asm("$3");

    func_8002CCB0(arg0, 0x10, 0x10);
    par = P50(arg0);
    one = 1;
    if (B(par, 4) != one) {
        if (B(arg0, 2) != 0x10) {
            goto next;
        }
        UB(arg0, 4) = 3;
        H(SP64, 0x54) = 0x3C;
        return;
    }
    func_80017A04(arg0);
    switch (B(arg0, 2)) {
    case 0:
    case 1:
        if (B(P50(arg0), 0x45) != 0x1B) {
            break;
        }
        goto next;
    case 2:
    case 3:
        if (B(arg0, 0x45) == 1) {
            goto next;
        }
        if (B(arg0, 0x45) == 2) {
            obj = func_8002C458();
            if (obj != 0) {
                UB(obj, 0) = 0x41;
                UB(obj, 1) = 3;
                UB(obj, 0x15) = UB(arg0, 0x15);
                W(obj, 0x7C) = W(arg0, 0x50);
                UB(obj, 2) = 0;
                H(obj, 0xA) = H(arg0, 0xA);
                H(obj, 8) = 0;
                H(obj, 0xE) = H(arg0, 0xE);
                H(obj, 0xC) = 0;
                H(obj, 0x42) = H(arg0, 0x42) & 0x7FFF;
                W(obj, 0x30) = W(arg0, 0x30);
                W(obj, 0x3C) = W(arg0, 0x3C);
                H(obj, 0x40) = H(arg0, 0x40);
                UB(obj, 0x14) = UB(arg0, 0x14);
            }
        }
        break;
    case 16:
        if (B(P50(arg0), 0x45) == 1) {
            func_800179A4(arg0, 0xC);
        }
        break;
    case 17:
        if (B(arg0, 0x45) == 1) {
        next:
            UB(arg0, 3) = 0;
            UB(arg0, 4)++;
        }
        break;
    }
}
