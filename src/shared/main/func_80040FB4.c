#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK apply_object_motion(); /* extern */
s32 random_byte();
void func_80042EB4(void*, u8, s32);
extern s16 D_80097206;
extern s16 D_800970AE;

void func_80040FB4(u8* arg0) {
    if (*(s8*)(arg0 + 7) == 0 && *(s16*)(arg0 + 0xE) >= D_80097206 - 8) {
        play_sound(0, 0x2B, arg0);
        arg0[7]++;
    }
    if (*(s16*)(arg0 + 0x7E) != 0) {
        if (--*(s16*)(arg0 + 0x7E) == 0) {
            *(s32*)(arg0 + 0x24) = 0xFFFF0000;
        }
    }
    if (*(s16*)(arg0 + 0xE) >= D_800970AE - 0x30) {
        ((void (*)(void*))apply_object_motion)(arg0);
        arg0[6]++;
        return;
    }
    ((void (*)(void*))apply_object_motion)(arg0);
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        switch (random_byte() & 7) {
        case 0:
            func_80042EB4(arg0, 0, 0);
            func_80042EB4(arg0, 0, 0x600);
            func_80042EB4(arg0, 0, 0xA00);
            break;
        case 1:
            func_80042EB4(arg0, 0, 0x200);
            func_80042EB4(arg0, 0, 0x800);
            func_80042EB4(arg0, 0, 0xC00);
            break;
        case 2:
            func_80042EB4(arg0, 0, 0x400);
            func_80042EB4(arg0, 0, 0xA00);
            func_80042EB4(arg0, 0, 0xE00);
            break;
        case 3:
            func_80042EB4(arg0, 0, 0x600);
            func_80042EB4(arg0, 0, 0xC00);
            func_80042EB4(arg0, 0, 0);
            break;
        case 4:
            func_80042EB4(arg0, 0, 0x800);
            func_80042EB4(arg0, 0, 0xE00);
            func_80042EB4(arg0, 0, 0x200);
            break;
        case 5:
            func_80042EB4(arg0, 0, 0xA00);
            func_80042EB4(arg0, 0, 0);
            func_80042EB4(arg0, 0, 0x400);
            break;
        case 6:
            func_80042EB4(arg0, 0, 0xC00);
            func_80042EB4(arg0, 0, 0x200);
            func_80042EB4(arg0, 0, 0x600);
            break;
        case 7:
            func_80042EB4(arg0, 0, 0xE00);
            func_80042EB4(arg0, 0, 0x400);
            func_80042EB4(arg0, 0, 0x800);
            break;
        }
        *(s16*)(arg0 + 0x7C) = 0x28;
    }
}
