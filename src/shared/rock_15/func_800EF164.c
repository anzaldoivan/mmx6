#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);

void func_800EF164(void* arg0, s32 arg1) {
    u8 sub;
    void* c;

    sub = arg1;
    c = func_8002C398();
    if (c != 0) {
        M2C_FIELD(c, u8*, 0x0) = 0x41;
        M2C_FIELD(c, u8*, 0x1) = 0x10;
        M2C_FIELD(c, u8*, 0x2) = sub;
        M2C_FIELD(c, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(c, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(c, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(c, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(c, u16*, 0x8) = 0;
        M2C_FIELD(c, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(c, u16*, 0xC) = 0;
        M2C_FIELD(c, void**, 0x50) = arg0;
        M2C_FIELD(c, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(c, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
        M2C_FIELD(c, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        if (!(sub & 0xF0)) {
            M2C_FIELD(arg0, u8*, 0x7)++;
        }
    }
}
