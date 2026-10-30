#include "common.h"
#define M2C_UNK s32

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_80017A04();
void func_8003AD18(void* arg0);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003D330();

void func_8003809C(void* arg0) {
    u8* p = arg0;

    ((void (*)())func_80017A04)();
    if (*(s8*)(p + 6) == 0) {
        if (p[0xE2] == 4) {
            ((void (*)(void*, s32))func_8003BA04)(p, 0x27);
            p[6]++;
        }
    } else {
        if (*(s8*)(p + 0x45) & 0x80) {
            p[0x45] = 0;
            ((void (*)(s32, s32, void*))play_sound)(0, 0x21, 0);
        }
        if (*(s8*)(p + 0x46) == 0) {
            ((void (*)())func_8003D330)();
            func_8003AD18(p);
        }
    }
}
