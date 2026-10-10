#include "common.h"
#include "mmx6/x4.h"

void func_80024CC0(s32 arg0, u8 arg1);
void func_800253AC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, u32 arg5,
                   u32 arg6);
s32 func_8003EB0C(void* arg0, s32 arg1);
extern u8 D_80071DC4[];
extern s8 D_800970A2;
extern struct X4_EngineObj D_800CCED0;

#define FB(p, o) (*(s8*)((u8*)(p) + (o)))
#define FH(p, o) (*(s16*)((u8*)(p) + (o)))
#define FUH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800249D4(void* arg0) {
    s32 x;
    s32 d;
    s32 w;
    s32 i;
    s16* t;

    i = FB(arg0, 0x93);
    if (i == 0) {
        struct X4_EngineObj* e = &D_800CCED0;
        x = (s8) * ((u8*)&e->unk38 + 1);
        d = x / 10;
        func_80024CC0(3, d + 0x3B);
        func_80024CC0(4, x - d * 10 + 0x3B);
    } else {
        {
            s32 k = i << 1;
            t = (s16*)((u8*)arg0 + 0xA8);
            x = *(s16*)((u8*)t + k);
        }
        x = (s16)(x / func_8003EB0C(arg0, i));
        func_80024CC0(0xB, x / 100 + 0x3B);
        func_80024CC0(0xC, (s16)(x % 100) / 10 + 0x3B);
        func_80024CC0(0xD, x % 10 + 0x3B);
        func_80024CC0(5, D_80071DC4[FB(arg0, 0x93) - 1]);
        w = *(s16*)((u8*)t + (FB(arg0, 0x93) << 1));
        x = (s16)(w / 6);
        func_800253AC(0x1F, 0x22, 0x50 - x, 0x50, 2,
                      (s16)((s16)FUH(arg0, 0x14A) / 6), x);
        x = (s16)(((s16)((s16)FUH(arg0, 0x14A) / 6) - 0x30) / 2 + 0x99);
        if (x >= 0xA2) {
            x = 0xA1;
        }
        func_80024CC0(2, x);
    }
    {
        register u8* p asm("$3") = (u8*)&D_800CCED0;
        register s32 j asm("$4") = D_800970A2;
        x = (*(s8*)(p - -j + 0x5B) - 0x20) / 2 + 0x88;
    }
    if (x >= 0x99) {
        x = 0x98;
    }
    func_80024CC0(0, x);
}
