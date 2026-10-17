#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern u16 D_800C4570;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800F0FC8[][0x18];

#define EC28C_ENG_2A (D_800CCED0.character_state.bytes[4])

void func_800EC28C(void* arg0) {
    s32 old;

    old = EC28C_ENG_2A;
    if (D_800C4570 & 0x8000) {
        EC28C_ENG_2A = D_800F0FC8[0][old];
    } else if (D_800C4570 & 0x2000) {
        EC28C_ENG_2A = D_800F0FC8[1][old];
    } else if (D_800C4570 & 0x1000) {
        EC28C_ENG_2A = D_800F0FC8[2][old];
    } else if (D_800C4570 & 0x4000) {
        EC28C_ENG_2A = D_800F0FC8[3][old];
    }
    if (old != EC28C_ENG_2A) {
        func_80016C48(5, 0, 0);
    }
}

#undef EC28C_ENG_2A
