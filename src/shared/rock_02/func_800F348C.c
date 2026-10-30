#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();
M2C_UNK func_800F82C0();

void func_800F348C(void* arg0) {
    void* child;
    // !FAKE: depin: dropping it breaks the match (87/94)
    register s32 t asm("$2");

    func_800F82C0();
    func_80017A04(arg0);
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x3D) {
        if (M2C_FIELD(arg0, s8*, 2) == 1) {
            play_sound(2, 0x3D, arg0);
            play_sound(2, 0x23, arg0);
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 7;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(child, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(child, s32*, 0x3C) =
                    SPAD20 + *(s32*)(func_8002A47C(0x37) * 4 + SPAD20 + 4);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
        } else if (M2C_FIELD(arg0, s8*, 2) == 2 &&
                   M2C_FIELD(arg0, s8*, 7) == 0) {
            play_sound(2, 0x3D, arg0);
            play_sound(2, 0x23, arg0);
            M2C_FIELD(arg0, s8*, 7) = 1;
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 0xB;
                M2C_FIELD(child, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
                M2C_FIELD(child, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                M2C_FIELD(child, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(child, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(child, s32*, 0x3C) =
                    SPAD20 + *(s32*)(func_8002A47C(0x37) * 4 + SPAD20 + 4);
                M2C_FIELD(child, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(child, void**, 0x7C) = arg0;
            }
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
