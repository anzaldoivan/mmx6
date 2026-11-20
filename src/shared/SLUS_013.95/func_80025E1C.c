#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PTR(off) (*(u8**)(0x1F800000 + (off)))
#define SCR_COUNT (*(s32*)0x1F800124)

void func_80022E44(void);
void func_800232D4(struct X4_VisualObj*);

static inline void func_80025E1C_ot(void) {
    u32 buffer;
    u32 i;
    u32 j;

    buffer = SP_DRAW_BUFFER;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            D_80090D70[buffer][i][j] = NULL;
            D_8008EB08[buffer][i][j] = (X4_P_TAG*)&D_80090D70[buffer][i][j];
        }
    }
}

void func_80025E1C(void) {
    s32 buf;
    u8* p;

    buf = SCR_BUF;
    SCR_COUNT = 0;
    SCR_PTR(0x100) = D_800A51B8 + buf * 0xA000;
    SCR_PTR(0x104) = D_800C4858 + buf * 0x2000;
    func_80025E1C_ot();
    for (p = D_800964A0; p < D_800964A0 + 0xC00; p += 0x60) {
        if (((s8*)p)[3] != 0) {
            func_800232D4(p);
        }
    }
    func_80022E44();
}
