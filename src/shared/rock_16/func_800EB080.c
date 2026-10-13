#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern u16 D_800C456C[];
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F1CB0[];
extern u8 D_800F1CEB;

#define EB080_SEL (D_800CCED0.character_state.bytes[10])
#define EB080_DIR (D_800CCED0.character_state.bytes[11])
#define EB080_DONE (D_800CCED0.character_state.bytes[12])
#define EB080_F(o, t) (*(t*)((u8*)arg0 + (o)))

void func_800EB080(void* arg0) {
    s32 old;

    old = EB080_SEL;
    if (D_800C456C[2] & 0x8000) {
        EB080_DIR = 1;
        EB080_SEL--;
        if (EB080_SEL < 0) {
            EB080_SEL = D_800F1CEB - 1;
        }
    } else if (D_800C456C[2] & 0x2000) {
        EB080_DIR = 2;
        EB080_SEL++;
        if (EB080_SEL >= D_800F1CEB) {
            EB080_SEL = 0;
        }
    }
    if (old != EB080_SEL) {
        func_80016C48(5, 0, 0);
        EB080_F(0x8, s16) = 0;
        EB080_F(0x2, u8) += 1;
        return;
    }
    if (D_800C456C[2] & 0x840) {
        u8 v = D_800F1CB0[old];
        EB080_F(0x5E, u8) = v;
        if (v == 5) {
            EB080_F(0x38, u8) = 1;
        } else {
            EB080_F(0x38, u8) = 0;
        }
        func_80016C48(5, 1, 0);
        EB080_DIR = 3;
        EB080_F(0x8, s16) = 0;
        EB080_F(0x2, u8) += 2;
        return;
    }
    if (D_800C456C[2] & 0x10) {
        EB080_F(0x2, u8) = 9;
        EB080_DONE = 1;
        EB080_F(0x8, s16) = 0;
    }
}
