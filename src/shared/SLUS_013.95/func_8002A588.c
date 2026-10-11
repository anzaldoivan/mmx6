#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
void func_8001FE74(void);
s8* func_8002C590(void);

extern u8 D_8006D5F7;
extern u8 D_80073630[];
extern u8 D_80073658[];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E4188;

#define D_80097420 (*(struct X4_EngineObj*)&D_80097420)

void func_8002A588(void) {
    s8* p;
    u8* t;
    u8 v;

    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0;
        p[2] = 0x20;
        p[0x47] = 0;
        *(s16*)(p + 0xE) = 0x20;
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0;
        p[2] = -1;
        *(s16*)(p + 0xA) = 0x10;
        *(u8**)(p + 0x50) = D_80073658;
    }
    t = D_80073630;
    if (*t != 0xFF) {
        do {
            p = func_8002C590();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0;
                p[2] = 0x10;
                p[0x47] = t[0];
                *(s16*)(p + 0xE) = t[1];
                p[7] = t[2];
            }
            t += 3;
        } while (*t != 0xFF);
    }
    t = D_80073658;
    while (t[0] != 0xFF) {
        p = func_8002C590();
        if (p != 0) {
            p[0] = 1;
            p[1] = 0;
            p[2] = t[1];
            *(s16*)(p + 0xE) = t[0];
        }
        v = t[1];
        t += 2;
        if (v == 0xA) {
            break;
        }
    }
    p = func_8002C590();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0;
        p[2] = -2;
    }
    func_8001FE74();
    {
        u8* e = (u8*)&D_800CCED0;
        D_80097420.unk7 = 0;
        D_8006D5F7 = e[0xC9];
    }
    ((void (*)(s32))func_800139A0)(0x20);
    D_800E4188++;
}
#undef D_80097420
