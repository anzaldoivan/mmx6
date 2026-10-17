#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_800617A4(X4_CdlLOC* p);
s32 func_80061824(s32*, u8*);
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*);
s32 func_80065504(s32, s32*, s32);
s32 func_800656A0(s32, u8*);

extern u8 D_80010014[];
extern u8 D_800E0B58[];
#define D_800E0B58 (*(s32(*)[][2]) & D_800E0B58)

void func_80016780(void) {
    s32 file[6];
    u8 result[8];
    s32(*src)[2];
    s32 base;
    s32 i;

    src = (s32(*)[2])0x80103000;
    while (func_80061824(file, D_80010014) == 0) {
    }
    base = func_800617A4((X4_CdlLOC*)file);
    func_800648D4(2, (s32)file, 0);
    func_80065504(2, (s32*)0x80103000, 0x80);
    func_800656A0(0, result);
    while (func_800648D4(9, 0, 0) == 0) {
    }
    for (i = 0; i < 0x3B; i++) {
        D_800E0B58[i][0] = base + src[i][0];
        D_800E0B58[i][1] = src[i][1];
    }
}
#undef D_800E0B58
