#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C458();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F2404(void* arg0) {
    void* p;

    func_80017A04();
    if (SB(arg0, 0x45) == 5) {
        func_80016C48(2, 0x26, arg0);
        func_80016C48(2, 0x37, arg0);
        p = func_8002C458();
        if (p != 0) {
            UB(p, 0) = 0x41;
            UB(p, 1) = 0xE;
            UB(p, 2) = 0;
            UB(p, 0x14) = UB(arg0, 0x14);
            W(p, 8) = W(arg0, 8);
            W(p, 0xC) = W(arg0, 0xC);
            UB(p, 0x15) = UB(arg0, 0x15);
            W(p, 0x30) = W(arg0, 0x30);
            W(p, 0x3C) = W(arg0, 0x3C);
            UH(p, 0x40) = UH(arg0, 0x40);
            UH(p, 0x42) = UH(arg0, 0x42) & 0x7FFF;
            P(p, 0x7C) = arg0;
        }
        H(arg0, 0x7C) = 0x32;
        UB(arg0, 6)++;
    }
}
