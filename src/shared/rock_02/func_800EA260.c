#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EA8E0(void*, s32);
extern M2C_UNK D_8007433C;
extern u8 D_800970B4;
extern M2C_UNK D_800FA99C;
extern M2C_UNK D_800FA9A0;
extern M2C_UNK D_800FA9A4;
extern M2C_UNK D_800FAA34;

void func_800EA260(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = D_800970B4;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(SPAD4C, u16*, 0x80) = M2C_FIELD(arg0, u16*, 0xE);
    M2C_FIELD(SPAD4C, u8*, 0x82) = 1;
    M2C_FIELD(SPAD4C, u8*, 0x83) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, void**, 0x30) = &D_800FAA34;
    M2C_FIELD(arg0, u8*, 0x16) = 0x21;
    M2C_FIELD(arg0, void**, 0x68) = &D_800FA99C;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FA9A4;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FA9A0;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    func_800179A4(arg0, 0);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x5) = 2;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    func_800EA8E0(arg0, 0);
    func_800EA8E0(arg0, 1);
}
