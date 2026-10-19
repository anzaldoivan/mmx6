#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_VisualObj* func_8002C398(void);

void func_800F3E10(void* arg0, s32 arg1) {
    void* obj;
    u8 b = arg1;

    obj = func_8002C398();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0xB;
        M2C_FIELD(obj, u8*, 2) = b;
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        {
            s32 a = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(obj, s16*, 8) = 0;
            M2C_FIELD(obj, s16*, 0xA) = a;
        }
        {
            s32 e = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(obj, s16*, 0xC) = 0;
            M2C_FIELD(obj, void**, 0x50) = arg0;
            M2C_FIELD(obj, s16*, 0xE) = e;
        }
        M2C_FIELD(obj, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40);
        M2C_FIELD(obj, s16*, 0x42) = M2C_FIELD(arg0, s16*, 0x42) & 0x7FFF;
        M2C_FIELD(obj, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
    }
}
