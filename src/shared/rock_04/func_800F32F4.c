// rolefeed (3.1 T4): func_800F32F4 of src/rock_04/E9860.c

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK apply_object_motion();
M2C_UNK func_80049D90(void*);
void func_800F51F0(struct X4_AnimatedObj* arg0, u8 arg1);

void func_800F32F4(struct X4_AnimatedObj* arg0) {
    if (((u8*)arg0)[0x70] & 8) {
        ((void (*)())func_80049D90)();
        func_800F51F0(arg0, 0x10);
        func_800F51F0(arg0, 0x11);
        func_800F51F0(arg0, 0x12);
        ((u8*)arg0)[4] = 5;
        return;
    }
    apply_object_motion(arg0);
}
