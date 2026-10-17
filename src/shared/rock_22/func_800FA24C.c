#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
void* func_8002C458();
M2C_UNK func_8002D2B0();

void func_800FA24C(void* arg0) {
    void* p;

    func_80017A04();
    func_8002D2B0(arg0);
    {
        // !FAKE: retail reads the test byte into the first return register
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x70);

        if (t == 0) {
            return;
        }
    }
    {
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x1E;
            M2C_FIELD(p, u8*, 2) = 5;
            M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, u16*, 0xA) = 0x1FC0;
            M2C_FIELD(p, u16*, 0xE) = 0x158;
            M2C_FIELD(p, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
        }
        p = func_8002C458();
        if (p != 0) {
            M2C_FIELD(p, u8*, 0) = 0x41;
            M2C_FIELD(p, u8*, 1) = 0x1E;
            M2C_FIELD(p, u8*, 2) = 6;
            M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(p, u16*, 0xA) = 0x2088;
            M2C_FIELD(p, u16*, 0xE) = 0x158;
            M2C_FIELD(p, s32*, 0x7C) = M2C_FIELD(arg0, s32*, 0x7C);
        }
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
