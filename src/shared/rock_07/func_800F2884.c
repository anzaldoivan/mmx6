#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002D2B0(void*);
void func_800F6880(void*, s32, s16, s16);
void func_800F6E48(struct X4_MainObj*);

void func_800F2884(void* arg0) {
    s16 n;

    n = --M2C_FIELD(arg0, u16*, 0x7E);
    if (n == 0) {
        func_80016C48(2, 0x5E, arg0);
        func_80012D9C(5);
        func_800179D0(arg0, 0x21, 4);
        M2C_FIELD(arg0, u8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x20;
        M2C_FIELD(arg0, s16*, 0x86) = M2C_FIELD(arg0, s16*, 0xE) - 0x48;
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x10, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x11, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        func_800F6880(arg0, 0x12, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE) + 0x30);
        M2C_FIELD(arg0, u8*, 6) += 2;
        return;
    }
    n = --M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0) {
        M2C_FIELD(arg0, u8*, 3) = 1;
        func_800F6E48((struct X4_MainObj*)arg0);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x50000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    func_8002D2B0(arg0);
}
