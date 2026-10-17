#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* func_8002C7F0(void);

void func_800F4588(void* arg0, s32 arg1) {
    void* obj;
    u8 b = arg1;

    obj = func_8002C7F0();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
        M2C_FIELD(obj, u8*, 1) = M2C_FIELD(arg0, u8*, 1);
        M2C_FIELD(obj, u8*, 2) = b;
        M2C_FIELD(obj, s32*, 0x5C) = M2C_FIELD(arg0, s32*, 0x5C);
        M2C_FIELD(obj, u16*, 0xA) = 0;
        M2C_FIELD(obj, u16*, 0xE) = 0;
        M2C_FIELD(obj, u16*, 0x34) = M2C_FIELD(arg0, u16*, 0x34);
        M2C_FIELD(obj, u8*, 0x37) = M2C_FIELD(arg0, u8*, 0x37);
        M2C_FIELD(obj, s32*, 0x14) = M2C_FIELD(arg0, s32*, 0x14);
        M2C_FIELD(obj, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(obj, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0x1C);
        M2C_FIELD(obj, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20);
        M2C_FIELD(obj, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24);
        M2C_FIELD(obj, s32*, 0x28) = M2C_FIELD(arg0, s32*, 0x28);
        M2C_FIELD(obj, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x2C);
        M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
    }
}
