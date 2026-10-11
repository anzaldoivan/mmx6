#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);
void func_800F52AC(void* arg0, u8 arg1);

void func_800F447C(u8* arg0) {
    switch (*(s8*)(arg0 + 0x45)) {
    case 1:
        func_80016C48(2, 0x15, arg0);
        func_800F52AC(arg0, 2);
        break;
    case 2:
        func_800F5088((struct X4_AnimatedObj*)arg0, 2);
        break;
    case 3:
        if (--*(s16*)(arg0 + 0x7E) != 0) {
            *(u16*)(arg0 + 0x7C) = 0x28;
            arg0[6] = arg0[6] + 1;
        } else {
            *(u16*)(arg0 + 0x7C) = 0x28;
            arg0[6] = arg0[6] + 2;
        }
        break;
    }
}
