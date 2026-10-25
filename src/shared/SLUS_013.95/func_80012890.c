#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800122A4();
M2C_UNK func_80066150(M2C_UNK);
void func_800662D4(X4_RECT*, s32, s32, s32);
M2C_UNK func_8006663C(s32, M2C_UNK);
void func_80068CD4(void*, s32, s32, s32, s32);
void func_80068D94(void*, s32, s32, s32, s32);

extern u8 D_8006D5FC[];
extern X4_RECT D_8006D884;
extern u16 D_80090D6A;
extern u16 D_8009B79C;
extern u8 D_800C458C[];
extern struct X4_EngineObj D_800CCED0;

void func_80012890(s32 arg0) {
    u8* p;
    u8* a;
    u8* b;
    u8* eng;
    s32 pad[2];

    if (D_80090D6A != arg0) {
        D_80090D6A = arg0;
        if ((u16)arg0 == 0) {
            D_8009B79C = 0x140;
            func_800662D4(&D_8006D884, 0, 0, 0);
            func_80066150(0);
        } else {
            D_8009B79C = 0x200;
            func_800662D4(&D_8006D884, 0, 0, 0);
            func_80066150(0);
        }
        p = D_800C458C;
        func_80068CD4(p, 0, 0, D_8009B79C, 0xF0);
        a = p - 0x14;
        func_80068D94(a, 0, 0xF0, D_8009B79C, 0xF0);
        func_80068CD4(p + 0xF0, 0, 0xF0, D_8009B79C, 0xF0);
        b = p + 0xDC;
        func_80068D94(b, 0, 0, D_8009B79C, 0xF0);
        {
            // !FAKE: depin: dropping it breaks the match (102/105)
            register s32 x asm("$7");
            s32 y;
            // !FAKE: depin: dropping it breaks the match (97/105)
            register u8* src asm("$3");
            src = D_8006D5FC;
            eng = (u8*)&D_800CCED0;
            x = src[0];
            y = src[2];
            eng[0xD0] = x;
            eng[0xD1] = y;
            func_800122A4((s8)x, (s8)y);
        }
        func_8006663C((s32)(p + 0x5C), 0x20);
        a[0x2A] = 0;
        a[0x2C] = 1;
        a[0x2D] = 0;
        a[0x2E] = 0;
        a[0x2F] = 0;
        func_8006663C((s32)(p + 0x14C), 0x20);
        b[0x2A] = 0;
        b[0x2C] = 1;
        b[0x2D] = 0;
        b[0x2E] = 0;
        b[0x2F] = 0;
    }
}
