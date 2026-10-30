#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();

void func_800F370C(void* arg0) {
    void* child;

    func_80017A04(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x7E, arg0);
        if (!(SPAD4C[0x8A] & 1)) {
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 9;
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
            SPAD4C[0x8A] |= 1;
        }
        if (!(SPAD4C[0x8A] & 0x10)) {
            child = func_8002C458();
            if (child != 0) {
                M2C_FIELD(child, u8*, 0) = 0x41;
                M2C_FIELD(child, u8*, 1) = 0x15;
                M2C_FIELD(child, u8*, 2) = 0xA;
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
            SPAD4C[0x8A] |= 0x10;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
