#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BBF4();

void func_800EAA58(void* arg0, u8 arg1) {
    void* e;
    u8 b;
    u16 h;

    e = func_8002BBF4();
    if (e != 0) {
        M2C_FIELD(e, u8*, 0x0) = 0x41;
        b = M2C_FIELD(arg0, u8*, 0x1);
        M2C_FIELD(e, u8*, 0x2) = arg1;
        M2C_FIELD(e, s32*, 0x10) = 0;
        M2C_FIELD(e, void**, 0x80) = arg0;
        M2C_FIELD(e, u8*, 0x1) = b;
        M2C_FIELD(e, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(e, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(e, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        M2C_FIELD(e, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(e, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        h = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(e, u16*, 0x8) = 0;
        M2C_FIELD(e, u16*, 0xA) = h;
        h = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(e, u16*, 0xC) = 0;
        M2C_FIELD(e, u16*, 0xE) = h;
    }
}
