#include "common.h"
#include "mmx6/x4.h"

void func_80016178(void);
void func_8001642C(u8, s32*, u8*);
void func_80055D74(s8);
s8 func_80055F94(void*, s8, s32);
void func_8005A3CC(s8, u32, s32, s32);
extern u8 D_8006E35C[];
extern s8 D_80090D50[6];
extern s8 D_80090D64[];
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800E2600;
extern s32 D_800E2604;

void func_8001731C(void) {
    u8 i;
    u8* p;

    for (i = 0; i < 6; i++) {
        if (D_80090D64[i] != -1) {
            func_80055D74(D_80090D64[i]);
            D_80090D64[i] = -1;
        }
    }
    {
        struct X4_EngineObj* e = &D_800CCED0;
        p = &D_8006E35C[*(s8*)&e->unk38];
    }
    func_8001642C(*p, &D_800E2600, p);
    func_80016178();
    D_80090D64[0] =
        func_80055F94((u8*)&D_800E2600 + D_800E2600, D_80090D50[0], 8);
    for (i = 0; i < 8; i++) {
        func_8005A3CC(D_80090D64[0], i, 0x7F, 0x7F);
    }
    D_80090D64[1] =
        func_80055F94((u8*)&D_800E2604 - 4 + D_800E2604, D_80090D50[1], 2);
    for (i = 0; i < 2; i++) {
        func_8005A3CC(D_80090D64[1], i, 0x7F, 0x7F);
    }
}
