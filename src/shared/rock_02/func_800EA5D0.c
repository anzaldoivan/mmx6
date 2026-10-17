#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_8002D230();

void func_800EA5D0(void* arg0) {
    ((void (*)(void*))func_8002D230)(arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            SPAD4C[0x82] = 0;
            SPAD4C[0x83] = 0;
            M2C_FIELD(arg0, u8*, 5) = 4;
            M2C_FIELD(arg0, u8*, 6) = 0;
            return;
        }
        SPAD4C[0x82] = 0;
        SPAD4C[0x83] = 0;
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, u8*, 6) = 2;
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) >= M2C_FIELD(SPAD4C, s16*, 0x80) + 0x80) {
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(SPAD4C, u16*, 0x80) + 0x80;
        SPAD4C[0x82] = 0;
        SPAD4C[0x83] = 0;
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
