#include "common.h"
#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion();

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800F96E0(void* arg0) {
    u8 t;

    apply_object_motion(arg0);
    t = F8(arg0, 0x15);
    if ((t == 0 && (F8(arg0, 0x70) & 1)) ||
        (t == 0x40 && (F8(arg0, 0x70) & 2))) {
        play_sound(2, 0x4E, arg0);
        start_pad_vibration(5);
        func_8002943C(0x14, 6, 2);
        {
            // !FAKE: depin: dropping it breaks the match (35/40)
            register s32 b asm("$2") = F8(arg0, 6);
            F16(arg0, 0x7C) = 0x1E;
            F8(arg0, 6) = b + 1;
        }
    }
}
