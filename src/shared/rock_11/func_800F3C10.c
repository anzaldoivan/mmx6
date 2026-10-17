#include "common.h"

s32 func_8002D2D4();
extern u8 D_800FCB40[];
extern s8 D_800FD521;
extern s16 D_800FD524;

#define F_06(p) (*(u8*)((u8*)(p) + 0x6))
#define F_7C(p) (*(s16*)((u8*)(p) + 0x7C))
#define F_8C(p) (*(s8*)((u8*)(p) + 0x8C))
#define F_8D(p) (*(s8*)((u8*)(p) + 0x8D))

void func_800F3C10(void* arg0) {
    s32 t;

    t = (u16)F_7C(arg0) - 1;
    D_800FD524 = 0;
    F_7C(arg0) = t;
    if ((s16)t == 0) {
        if (D_800FCB40[F_8D(arg0) + F_8C(arg0) * 6] == 0xFF) {
            F_8C(arg0) = func_8002D2D4() & 3;
            F_8D(arg0) = 0;
            F_7C(arg0) = 0x78;
        }
        D_800FD524 = D_800FCB40[F_8D(arg0) + F_8C(arg0) * 6];
        F_7C(arg0) = 0x5A;
        F_8D(arg0)++;
    }
    if (D_800FD521 < 5) {
        F_06(arg0)++;
    }
}
