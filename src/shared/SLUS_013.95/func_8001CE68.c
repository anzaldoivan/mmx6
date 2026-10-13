#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern u16 D_800C456C[];
extern s32 D_800E3130[];

void func_8001CE68(struct X4_EngineObj* arg0) {
    switch (D_800E3130[1]) {
    case 0:
    case 1:
    case 2:
        if (D_800C456C[2] & 4) {
            D_800E3130[1]++;
        } else if (D_800C456C[2] & 8) {
            D_800E3130[1] = 0;
        }
        break;
    case 3:
        if (D_800C456C[2] & 2) {
            func_80016C48(0, 0x22, 0);
            D_800E3130[0] = 0;
            D_800E3130[1]++;
        } else if (D_800C456C[2] & 4) {
            D_800E3130[1] = 0;
        }
        break;
    }
    if (D_800C456C[2] & 0x5000) {
        D_800E3130[1] = 0;
    }
    if (arg0->unk2 != 0) {
        D_800E3130[1] = 0;
    }
}
