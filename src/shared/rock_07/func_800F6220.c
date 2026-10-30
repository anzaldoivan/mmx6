#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F6220(u8* arg0) {
    if (--F_S16(arg0, 0x7C) == 0) {
        if (--F_S16(arg0, 0x7E) == 0) {
            set_animation(arg0, 0x12);
            F_S32(arg0, 0x50) = 0;
            F_S32(arg0, 0x54) = 0;
            F_S16(arg0, 0x7C) = 0x1E;
            F_U8(arg0, 6)++;
        } else {
            F_U8(arg0, 6) -= 2;
        }
    }
}
