#include "common.h"
#define M2C_UNK s32
M2C_UNK func_80017A04();
void* func_8002C458();

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800EA5FC(void* arg0) {
    s32 n;
    s32 i;
    s32 k;
    void* o;
    s32 t;

    ((void (*)())func_80017A04)(arg0);
    if (B(arg0, 0x45) == 1) {
        n = 1;
        if (B(arg0, 6) == 0) {
            n = 3;
        }
        k = 0;
        if (n != 0) {
            i = n;
            do {
                o = func_8002C458();
                if (o != 0) {
                    UB(o, 0) = 0x41;
                    UB(o, 1) = 7;
                    UB(o, 2) = UB(arg0, 6);
                    UH(o, 0x40) = UH(arg0, 0x40);
                    UH(o, 0x42) = UH(arg0, 0x42) & 0x7FFF;
                    W(o, 0x30) = W(arg0, 0x30);
                    W(o, 0x3C) = W(arg0, 0x3C);
                    UB(o, 0x15) = UB(arg0, 0x15);
                    W(o, 8) = W(arg0, 8);
                    t = W(arg0, 0xC);
                    UB(o, 4) = 0;
                    UB(o, 6) = k;
                    W(o, 0xC) = t;
                    UB(o, 0x15) = UB(arg0, 0x15);
                    P(o, 0x7C) = arg0;
                }
                i--;
                k += 6;
            } while (i != 0);
        }
        UB(arg0, 5) = 3;
    }
}
