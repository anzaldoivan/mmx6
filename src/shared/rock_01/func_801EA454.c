#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003C4EC(struct X4_PlayerObj* self);
M2C_UNK func_8003CFE0(void*, M2C_UNK);
M2C_UNK func_801EC4AC(void*);

#define FLD(t, o) (*(t*)((u8*)arg0 + (o)))

s32 func_801EA454(void* arg0) {
    if (FLD(s8, 0xD3) != 0) {
        return 0;
    }
    if (!(FLD(u8, 0xC9) & 0x10)) {
        return 0;
    }
    if (!(FLD(u16, 0x7C) & 4)) {
        return 0;
    }
    if (!(FLD(u16, 0x80) & 0x10)) {
        return 0;
    }
    if (FLD(s8, 0x8E) != 0) {
        return 0;
    }
    FLD(s8, 0xDD) = 1;
    FLD(s8, 0x8E) = 1;
    FLD(s8, 0xCB) = 0;
    FLD(s8, 0x8C) = 0;
    func_8003BA04(arg0, 0x65);
    func_80016C48(1, 0x19, arg0);
    func_8003CFE0(arg0, 9);
    FLD(s8, 0x61) = 0;
    FLD(s8, 0xA4) = 0;
    func_8003C4EC(arg0);
    FLD(s8, 0x5) = 0x39;
    FLD(s8, 0x7A) = 1;
    FLD(s8, 0x6) = 0;
    FLD(s32, 0x20) = 0xFFFD0000;
    if (FLD(u8, 0x15) != 0) {
        FLD(s32, 0x20) = 0x30000;
    }
    FLD(s32, 0x24) = 0xFFFB0000;
    func_801EC4AC(arg0);
    return 1;
}
