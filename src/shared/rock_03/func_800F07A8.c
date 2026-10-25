#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_80074BFC;
extern s8 D_8009711A;
extern M2C_UNK D_800F7954;
extern u8 D_800F7BA0[][6];
extern s32 D_800F7DE4;
extern s32 D_800F7E30;

void func_800F07A8(void* arg0) {
    u8 frame;

    if (M2C_FIELD(arg0, s16*, 0x7C) == 0x78) {
        func_80016C48(2, 0x23, arg0);
    }
    if (M2C_FIELD(arg0, s16*, 0x8E) == 0) {
        if ((s8)(M2C_FIELD(arg0, u8*, 0x7) += 2) >= 0x1E) {
            M2C_FIELD(arg0, s16*, 0x8E) = 1;
        }
    } else {
        if ((s8)(M2C_FIELD(arg0, u8*, 0x7) -= 2) < -0x1D) {
            M2C_FIELD(arg0, s16*, 0x8E) = 0;
        }
    }
    if (D_800F7E30 == 30) {
        if ((s8)(M2C_FIELD(arg0, u8*, 0x5C) -= 3) <= 0) {
            M2C_FIELD(arg0, u8*, 0x4) = 2;
            M2C_FIELD(arg0, u8*, 0x5C) = 0;
            M2C_FIELD(arg0, u8*, 0x5) = 0;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            D_800F7DE4 = 1;
            D_8009711A = 1;
            func_8002CCB0(arg0, 0x40, 0x40);
            return;
        }
        func_80016C48(2, 0x21, arg0);
        func_800179A4(arg0, 8);
        M2C_FIELD(arg0, void**, 0x50) = 0;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    } else if (D_800F7E30 == 1) {
        func_800179A4(arg0, 0);
        {
            // !FAKE: depin: dropping it breaks the match (132/136)
            register s32 a asm("$2") = (s32)&D_800F7954;
            // !FAKE: depin: dropping it breaks the match (76/136)
            register s32 b asm("$3") = (s32)&D_80074BFC;
            M2C_FIELD(arg0, s32*, 0x50) = a;
            M2C_FIELD(arg0, s32*, 0x58) = b;
        }
    }
    if (D_800F7E30 != 0) {
        D_800F7E30--;
    }
    M2C_FIELD(arg0, s16*, 0x7E)++;
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0x258) {
        func_800179A4(arg0, 0);
        {
            // !FAKE: depin: dropping it breaks the match (132/136)
            register s32 a asm("$2") = (s32)&D_800F7954;
            // !FAKE: depin: dropping it breaks the match (130/136)
            register s32 b asm("$3") = (s32)&D_80074BFC;
            M2C_FIELD(arg0, s32*, 0x50) = a;
            M2C_FIELD(arg0, s32*, 0x58) = b;
        }
        D_800F7E30 = 0;
        frame = D_800F7BA0[M2C_FIELD(arg0, u8*, 0x86)]
                          [M2C_FIELD(arg0, u8*, 0x87)++];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = frame;
    }
}
