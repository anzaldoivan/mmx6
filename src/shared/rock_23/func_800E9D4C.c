#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800E9D4C(void* arg0) {
    s32 v;

    v = F32(arg0, 0x24);
    F32(arg0, 0x20) = 0;
    F32(arg0, 0x28) = 0;
    F32(arg0, 0x80) = v;
    if (v > 0) {
        if (F16(arg0, 0x7E) - 0x50 >= F16(arg0, 0xE)) {
            F32(arg0, 0x24) = -v;
        }
    } else if (F16(arg0, 0xE) >= F16(arg0, 0x7E) + 0x50) {
        F32(arg0, 0x24) = -v;
    }
    if (F32(arg0, 0x24) != F32(arg0, 0x80)) {
        F8(arg0, 0x84) = 0x28;
    }
    if (F8(arg0, 0x84) == 0) {
        move_object((s32)arg0);
        return;
    }
    if (--F8(arg0, 0x84) == 0) {
        if (F32(arg0, 0x24) > 0) {
            set_animation(arg0, 0);
            return;
        }
        set_animation(arg0, 1);
    }
}

#undef F32
#undef F16
#undef F8
