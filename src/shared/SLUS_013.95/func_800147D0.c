#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_800617A4(X4_CdlLOC* p);
s32 func_80061824(s32*, u8*);
s32 func_800648D4(M2C_UNK, M2C_UNK, u8*);
s32 func_80065504(s32, s32*, s32);
s32 func_800656A0(s32, u8*);

extern u8 D_80010004[];
extern u8 D_8006CD42[][22];
extern s32 D_800E0398[][2];

void func_800147D0(void) {
    s32 file[6];
    u8 result[8];
    s32(*src)[2];
    s32 base;
    s32 i;

    src = (s32(*)[2])0x80103000;
    while (func_80061824(file, D_80010004) == 0) {
    }
    base = func_800617A4((X4_CdlLOC*)file);
    func_800648D4(2, (s32)file, 0);
    func_80065504(2, (s32*)0x80103000, 0x80);
    func_800656A0(0, result);
    while (func_800648D4(9, 0, 0) == 0) {
    }
    for (i = 0; i < 0xF3; i++) {
        D_800E0398[i][0] = base + src[i][0];
        D_800E0398[i][1] = src[i][1];
    }
    for (i = 0xF3; i < 0xF7; i++) {
        while (func_80061824(file, D_8006CD42[i]) == 0) {
        }
        D_800E0398[i][0] = func_800617A4((X4_CdlLOC*)file);
        D_800E0398[i][1] = file[1];
        while (func_800648D4(9, 0, 0) == 0) {
        }
    }
}
