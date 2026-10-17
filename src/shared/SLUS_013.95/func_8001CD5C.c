#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
extern u16 D_800C456C[];
extern s32 D_800E3130[];

void func_8001CD5C(struct X4_EngineObj* arg0) {
    switch (D_800E3130[0]) {
    case 0:
    case 1:
    case 2:
        if (D_800C456C[2] & 0x8000) {
            D_800E3130[0]++;
        } else if (D_800C456C[2] & 0x2000) {
            D_800E3130[0] = 0;
        }
        break;
    case 3:
        if (D_800C456C[2] & 0x2000) {
            func_80016C48(0, 0x22, 0);
            D_800E3130[1] = 0;
            D_800E3130[0]++;
        } else if (D_800C456C[2] & 0x8000) {
            D_800E3130[0] = 0;
        }
        break;
    }
    if (D_800C456C[2] & 0x5000) {
        D_800E3130[0] = 0;
    }
    if (arg0->unk2 != 0) {
        D_800E3130[0] = 0;
    }
}
