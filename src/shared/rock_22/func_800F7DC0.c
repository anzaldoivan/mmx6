#include "common.h"

s32 random_byte();
extern s16 D_800970AE;

#define F6(p) (*(u8*)((u8*)(p) + 0x6))
#define F7(p) (*(s8*)((u8*)(p) + 0x7))
#define F7C(p) (*(s16*)((u8*)(p) + 0x7C))
#define F7E(p) (*(s16*)((u8*)(p) + 0x7E))
#define F90(p) (*(u8*)((u8*)(p) + 0x90))
#define F91(p) (*(u8*)((u8*)(p) + 0x91))

void func_800F7DC0(void* arg0) {
    s32 r;

    r = random_byte() & 3;
    if (F7(arg0) >= 2) {
        if (F7C(arg0) == 0) {
            if (r == 0) {
                F90(arg0) = 1;
                F91(arg0) = 3;
            } else if (r == 1) {
                F90(arg0) = 2;
                F91(arg0) = 3;
            } else if (r == 2) {
                F90(arg0) = 1;
                F91(arg0) = 1;
            } else if (r == 3) {
                F90(arg0) = r;
                F91(arg0) = r;
            }
        } else if (F7C(arg0) == 1) {
            if (r >= 2) {
                F90(arg0) = 3;
            } else {
                F90(arg0) = 0;
            }
            F91(arg0) = 3;
        } else if ((u16)(F7C(arg0) - 2) < 2) {
            if (r < 2) {
                F90(arg0) = 0;
            } else {
                F90(arg0) = 1;
            }
            F91(arg0) = 3;
        } else if ((u16)(F7C(arg0) - 4) < 2) {
            if (D_800970AE < 0xC0) {
                F90(arg0) = 0;
            } else {
                F90(arg0) = 1;
            }
            F91(arg0) = 3;
        }
        F7E(arg0) = 0;
        F7(arg0) = 0;
        F6(arg0) = F6(arg0) + 1;
    }
}
