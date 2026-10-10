#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800FA150(void*, s32);
void func_800FA234(void*, s32);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800FD2EC[];
extern u8 D_800FDA78[];
extern u16 D_800FDA7C;
#define D_800FDA7C (*(s16*)&D_800FDA7C)

void func_800F6998(void* arg0) {
    s32 i;
    s8 idx;

    func_80016C48(2, 0x21, arg0);
    func_800179A4(arg0, 8);
    {
        register s32 six asm("$2") = 6;
        M2C_FIELD(arg0, s8*, 0x60) = six;
    }
    M2C_FIELD(arg0, u8*, 0x8B) = 0;
    if (D_800FDA78[0] == 0 || D_800FDA78[1] == 0 || D_800FDA78[2] == 0) {
        idx = (u32)func_8002D2D4() % 3;
        for (i = 0; i < 3; i++) {
            if (D_800FDA78[idx] == 1) {
                idx++;
                if (idx >= 3) {
                    idx = 0;
                }
            }
        }
        func_800FA234(arg0, (u8)(idx + 0x20));
    }
    if (D_800FDA7C < D_800FD2EC[(u8)D_800CCED0.player_initial_data[0x46]]) {
        func_800FA150(arg0, 1);
    }
    if (M2C_FIELD(arg0, s16*, 0xA) < D_800970A0.x_pos.i.hi) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s32*, 0x20) = 0xFFFB0000;
        M2C_FIELD(arg0, s32*, 0x28) = -0x4000;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        M2C_FIELD(arg0, s32*, 0x28) = -0x4000;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
#undef D_800FDA7C
