#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800CCED4;
extern s16 D_800EA858[];
extern s16 D_800EA874[][2];
extern u8 D_800EA8A8[][8];

#define F(T, o) (*(T*)((u8*)arg0 + (o)))

void func_800E9D08(void* arg0) {
    s8 idx;
    s16* p;
    u8(*r)[8];
    u8* q;
    // !FAKE: pin the table offset in the first result register as retail allocates it
    register s32 off asm("$3");

    ((void (*)())func_80017A04)();
    if (F(s8, 0x46) == 0) {
        if (F(s8, 0x2) == 0) {
            idx = F(s8, 0x54);
            p = &D_800EA858[idx];
            r = D_800EA8A8;
            do {
                q = (u8*)D_800EA874;
            } while (0);
            off = idx * 4;
            func_80027BA0(*p, *(s16*)(off + q),
                          ((s16*)((u8*)D_800EA874 + off))[1], r[idx]);
            background_objects[*p].unk4C = 1;
            F(u8, 0x3) = 0;
        }
        D_800CCED4 = 0;
        F(u8, 0x4) = F(u8, 0x4) + 1;
    }
}

#undef F
