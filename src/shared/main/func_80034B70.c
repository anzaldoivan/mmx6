#include "common.h"

extern s8 D_80097424;
s32 func_800139A0(s8);
s32 func_800139F4(s32);
void func_8001FFC0(void*);
s32 func_80026028();

void func_80034B70(u8* s) {
    switch ((s8)s[6]) {
    case 0:
        func_800139F4(0x20);
        s[6]++;
        func_80026028();
        break;
    case 1:
        if (D_80097424 == 0) {
            s[6]++;
        }
        func_80026028();
        break;
    case 2:
        func_8001FFC0(s);
        break;
    case 3:
        func_800139A0(0x20);
        s[6]++;
        func_80026028();
        break;
    case 4:
        if (D_80097424 == 0) {
            s[5] = s[0x30];
            s[6] = 0;
        } else {
            func_80026028();
        }
        break;
    }
}
