#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;
extern u8 D_800CCF38;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F371C(void* arg0) {
    if (D_800970AA > F(s16, arg0, 0xA)) {
        F(u8, arg0, 0x15) = 0x40;
    } else {
        F(u8, arg0, 0x15) = 0;
    }
    if (F(s8, arg0, 0x46) == 0) {
        play_sound(2, 0x3E, arg0);
        func_800F0434(arg0, 0x1E);
        F(u16, arg0, 0x7C) = 0;
    }
    if (++F(s16, arg0, 0x7C) == 0x3C) {
        F(s16, arg0, 0x7E) = 0;
        if (D_800CCF38 == 2) {
            F(s8, arg0, 6) = 0xC;
        } else {
            F(s8, arg0, 6) = 3;
        }
    }
}
