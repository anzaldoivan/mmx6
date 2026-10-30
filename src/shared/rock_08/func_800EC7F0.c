#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
s32 set_animation(void*, s32);
M2C_UNK func_80017A04(); /* extern */
extern u8 D_800CCF38;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FP(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EC7F0(u8* arg0) {
    u8* temp_s1;

    temp_s1 = FP(arg0, 0x7C);
    ((void (*)(void))func_80017A04)();
    if (F16(arg0, 0x80) == 0) {
        if (F8(arg0, 2) == 0xE) {
            set_animation(arg0, 0x1C);
        } else {
            set_animation(arg0, 0x1B);
        }
        if (F8(temp_s1, 0x5C) < 3) {
            F16(arg0, 0x80) = 0x28;
        } else if (D_800CCF38 < 2) {
            F16(arg0, 0x80) = 0x5A;
        } else {
            F16(arg0, 0x80) = 0x28;
        }
        if (F8(arg0, 3) != 0) {
            play_sound(2, 0xB, arg0);
        }
        FU8(arg0, 7)++;
    }
}
