#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
s32 random_byte();
void func_800F3824(struct X4_MainObj*);

void func_800F3C44(u8* arg0) {
    ((void (*)(void*))func_80017A04)(arg0);
    if (*(s16*)(arg0 + 0x8C) == 0) {
        if (*(s8*)(arg0 + 0x45) == 1) {
            func_800F3824((struct X4_MainObj*)arg0);
            if (random_byte() & 3) {
                ((void (*)(void*, s32))set_animation)(arg0, 7);
                *(s16*)(arg0 + 0x8C) = 0x3C;
                arg0[6] = arg0[6] + 1;
                return;
            }
            ((void (*)(void*, s32))set_animation)(arg0, 5);
            arg0[6] = 5;
        }
    } else {
        *(s16*)(arg0 + 0x8C) = *(s16*)(arg0 + 0x8C) - 1;
        ((void (*)(void*))move_object)(arg0);
    }
}
