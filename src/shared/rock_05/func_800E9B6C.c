#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800F3CD0[];

#define SPAD (*(u8**)0x1F80004C)
#define F(type, off) (*(type*)((u8*)self + (off)))

void func_800E9B6C(void* self) {
    u8* p;
    s32 t;

    if (F(s8, 0x45) == 1) {
        p = SPAD;
        if ((u8)--p[0x85] == 0) {
            F(s8, 5) = 3;
            F(s8, 6) = 0;
            return;
        }
        play_sound(2, 0x16, self);
        if (!(F(s8, 2) & 0xF0)) {
            set_animation(self, 0);
        } else {
            set_animation(self, 2);
        }
        t = F(u8, 2) & 0xF;
        if (t == 0) {
            F(s16, 0x7C) = 0xB4;
        } else if (t < 8) {
            F(s16, 0x7C) = 0xE;
        } else {
            F(s16, 0x7C) = 0xE;
        }
        F(s8, 6) = 1;
        return;
    }
    if (!(F(s8, 2) & 0xF0)) {
        SPAD[0x81] = -D_800F3CD0[F(u8, 0x47)];
        SPAD[0x83] = D_800F3CD0[F(u8, 0x47)];
        return;
    }
    SPAD[0x81] = 0;
    SPAD[0x83] = D_800F3CD0[F(u8, 0x47)];
}

#undef F
#undef SPAD
