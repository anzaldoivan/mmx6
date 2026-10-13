#include "common.h"
#include "mmx6/x4.h"

s32 func_800F054C(void);
extern u8 D_80097169;
extern struct X4_EngineObj D_800CCED0;

#define ENG ((u8*)&D_800CCED0)

void func_800EE6F4(u8* arg0) {
    s32 flag;
    s32 n;
    u8* p;

    n = 0;
    {
        u8* e = ENG;
        if (!(*(s32*)(e + 0x24) & 0xFFFF0000)) {
            arg0[0x158] = 1;
            n = 1;
        }
        flag = 0;
        if ((u8)(e[0x26] - 1) < 8 && *(s8*)(e + 0x27) == 0) {
            if (D_80097169 != 0xFF) {
                flag = arg0[0x60] == 0xFF;
            }
        }
    }
    if (*(s16*)(arg0 + 0xD2) >= 3000 || *(s16*)(arg0 + 0xD4) >= 3000) {
        flag = 1;
    }
    {
        u8* e = ENG;
        if (*(s8*)(e + 0x27) == 0 && *(s8*)(e + 0x26) >= 0x13 &&
            arg0[0x43B] == 1) {
            flag = 1;
            arg0[0x43B] = 2;
        }
    }
    p = arg0 + 0x158;
    if (arg0[0x66] < 3) {
        if (flag != 0) {
            u8* e = ENG;
            if (*(s8*)(e + 0x38) == 0) {
                p[n] = 6;
            } else {
                p[n] = 7;
            }
            n++;
        } else if (D_80097169 == 0) {
            if (func_800F054C() != 0) {
                p[n] = 3;
                n++;
            }
        }
    }
    p[n] = 0xFF;
}
