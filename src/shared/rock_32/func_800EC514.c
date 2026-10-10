#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void* func_8002C458();

void func_800EC514(void* arg0, u8 arg1, s32 arg2) {
    void* p;

    p = func_8002C458();
    if (p != 0) {
        M2C_FIELD(p, s8*, 0) = 0x41;
        M2C_FIELD(p, s8*, 1) = 0xA;
        M2C_FIELD(p, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(p, u8*, 2) = arg1;
        M2C_FIELD(p, s16*, 0xA) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(p, s16*, 8) = 0;
        M2C_FIELD(p, s16*, 0xE) = M2C_FIELD(arg0, s16*, 0xE);
        M2C_FIELD(p, s16*, 0xC) = 0;
        M2C_FIELD(p, s16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(p, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
        M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(p, s32*, 0x84) = arg2;
        M2C_FIELD(p, s16*, 0x88) = SPAD4C[0x8C];
    }
}
