#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D230();
extern s32 D_800741F4[];
extern s32 D_800970A8;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800400F4(void* arg0) {
    s32 v;

    if (F_S8(arg0, 6) == 0) {
        F_S8(arg0, 6)++;
        if (D_800970A8 < F_S32(arg0, 8)) {
            F_S32(arg0, 0x20) = D_800741F4[F_S8(arg0, 0x63) - 5];
        } else {
            F_S32(arg0, 0x20) = -D_800741F4[F_S8(arg0, 0x63) - 5];
        }
        F_S32(arg0, 0x28) = 0x3000;
        F_S32(arg0, 0x24) = 0;
        F_S32(arg0, 0x2C) = 0;
        if (F_S8(arg0, 0x63) == 5) {
            F_U8(arg0, 0x61) = 0x12;
        } else {
            F_U8(arg0, 0x61) = 1;
        }
    }
    func_8002D230(arg0);
    v = F_S32(arg0, 0x20);
    if ((v < 0 ? -v : v) < 0x6000) {
        F_S32(arg0, 0x20) = 0;
        F_S32(arg0, 0x28) = 0;
    }
    if (F_U8(arg0, 0x70) & 3) {
        F_S32(arg0, 0x20) = 0;
        F_S32(arg0, 0x28) = 0;
    }
    if ((s8)((s8)F_U8(arg0, 0x61) % 9) != 0) {
        F_U16(arg0, 0x42) &= 0x7FFF;
    } else {
        F_U16(arg0, 0x42) |= 0x8000;
    }
    if (--F_S8(arg0, 0x61) == 0) {
        F_S8(arg0, 5) = 1;
        F_S8(arg0, 6) = 0;
        F_S32(arg0, 0x20) = 0;
        F_S32(arg0, 0x28) = 0;
        F_U16(arg0, 0x42) &= 0x7FFF;
    }
}

#undef F_S8
#undef F_U8
#undef F_U16
#undef F_S32
