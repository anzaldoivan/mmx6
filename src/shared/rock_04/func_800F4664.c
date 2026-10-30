#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F513C(struct X4_AnimatedObj* arg0, u8 arg1);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define SW(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F4664(void* arg0) {
    if (SB(arg0, 0x45) == 1) {
        play_sound(2, 0x13, arg0);
        if (UB(arg0, 0x15) == 0) {
            SW(arg0, 0x20) = 0xFFFA0000;
            SH(arg0, 0x84) = UH(arg0, 0xA) - ((random_byte() & 0x1F) | 0x20);
        } else {
            SW(arg0, 0x20) = 0x60000;
            SH(arg0, 0x84) = UH(arg0, 0xA) + ((random_byte() & 0x1F) | 0x20);
        }
        func_800F513C(arg0, 0x12);
        SH(arg0, 0x7C) = 8;
        UB(arg0, 6) = UB(arg0, 6) + 1;
    }
}
