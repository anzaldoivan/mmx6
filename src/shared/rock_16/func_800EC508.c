#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800EC28C(void*);
void func_800EC35C(void* arg0);
extern u16 D_800C456C[];
extern u8 D_800F1CC4[];

void func_800EC508(struct X4_EngineObj* arg0) {
    s32 t;

    t = D_800C456C[2];
    if (t & 4) {
        func_80016C48(5, 0, 0);
        D_800F1CC4[4] = 2;
        D_800F1CC4[5] = 1;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk1 = 7;
        arg0->unk2 = 0;
        t = 1;
    } else if (t & 8) {
        D_800F1CC4[4] = 1;
        D_800F1CC4[5] = 2;
        func_80016C48(5, 0, 0);
        t = 1;
        arg0->unk1 = 8;
        arg0->unk2 = 0;
        arg0->unk8 = 0;
    } else {
        t = 0;
    }
    if (t == 0) {
        if (D_800C456C[2] & 0x10) {
            if (arg0->unk5F & 0x10) {
                func_80016C48(5, 1, 0);
            }
            arg0->unk1 = 5;
            arg0->unk2 = 0;
        }
        func_800EC28C(arg0);
        func_800EC35C(arg0);
    }
}
