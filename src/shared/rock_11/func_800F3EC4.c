#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F3EC4 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);
extern u32* D_80095098;

void func_800F3EC4(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;
    s32 t;

    obj = func_8002C398();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = 0xB;
        M2C_FIELD(obj, u8*, 2) = arg1;
        M2C_FIELD(obj, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        t = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(obj, u8*, 0x14) = 0;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, void**, 0x50) = arg0;
        M2C_FIELD(obj, s32*, 0x30) = t;
        M2C_FIELD(obj, s16*, 0x40) = M2C_FIELD(arg0, s16*, 0x40) + 0x400;
        M2C_FIELD(obj, u16*, 0x40) =
            D_80095098[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1] >> 7;
        M2C_FIELD(obj, s16*, 0x42) =
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1 + 8) / 4 + 0x1E0)
             << 6);
        M2C_FIELD(obj, u8**, 0x3C) =
            (u8*)SPAD20_800F3EC4 +
            SPAD20_800F3EC4[func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 1];
    }
}
