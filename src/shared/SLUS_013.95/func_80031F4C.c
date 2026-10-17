#include "common.h"

extern s8 D_8008EF48[];
s32 func_8002E664(void* arg0, void* arg1);
s32 func_800323D4(struct X4_MainObj* self, struct X4_PlayerObj* tgt);
void func_80032D24(void* arg0, void* arg1);

void func_80031F4C(void* arg0) {
    s8* p;
    s32* w;
    s32 bit;
    s32 x;
    s32 y;
    s32 i;
    u8 f;

    i = 0;
    if (*(s32*)((u8*)arg0 + 0x68) != 0) {
        p = D_8008EF48;
        do {
            if (p[0] != 0 && *(s32*)(p + 0x68) != 0) {
                x = *(s32*)(p + 8);
                y = *(s32*)(p + 0xC);
                func_800323D4(arg0, p);
                {
                    register s32 o asm("$3") = (i >> 5) << 2;
                    u8* b = (u8*)arg0 + 0x98;
                    w = (s32*)(b + o);
                }
                bit = 1 << (i & 0x1F);
                if (*w & bit) {
                    func_80032D24(arg0, p);
                }
                if (func_8002E664(arg0, p) == 8) {
                    *w |= bit;
                } else {
                    *w &= ~bit;
                    f = p[0x70];
                    if ((f & 0xC) == 0xC || (f & 3) == 3) {
                        *(s32*)(p + 8) = x;
                        *(s32*)(p + 0xC) = y;
                    }
                }
            }
            i++;
            p += 0x9C;
        } while (i < 0x30);
    }
}
