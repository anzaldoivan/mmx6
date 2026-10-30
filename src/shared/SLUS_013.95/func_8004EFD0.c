#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void*, M2C_UNK);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_8004EFD0(struct X4_MainObj* self) {
    s8 state;

    state = S8(self, 6);
    if (state == 0) {
        F8(self, 0x7F) = 0x82;
        if (F8(self, 0x84) == 0) {
            if (F8(self, 0x7E) == 0) {
                if (F8(self, 0x82) == 0) {
                    set_animation(self, 1);
                } else {
                    set_animation(self, 0xC);
                }
            } else if (F8(self, 0x82) == 0) {
                set_animation(self, 6);
            } else {
                set_animation(self, 0xF);
            }
        } else if (F8(self, 0x82) == 0) {
            set_animation(self, 0x18);
        } else {
            set_animation(self, 0x1F);
        }
        F8(self, 6)++;
    } else if (state == 1) {
        if (--F8(self, 0x7F) == 0) {
            play_sound(2, 0x41, self);
            F8(self, 0x83) = state;
            F8(self, 0x7F) = 0x3C;
            F8(self, 6)++;
        }
    } else if (state == 2) {
        if (--F8(self, 0x7F) == 0) {
            F8(self, 0x83) = 0;
            F8(self, 6) = 0;
            F8(self, 5)++;
        }
    }
}
