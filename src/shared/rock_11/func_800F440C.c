#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F440C (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002BBF4();
extern u32* D_80095098;

void func_800F440C(s8 arg0, u8 arg1, s16 arg2, s16 arg3) {
    void* obj;

    obj = func_8002BBF4();
    if (obj != 0) {
        M2C_FIELD(obj, u8*, 0) = 0x41;
        M2C_FIELD(obj, u8*, 1) = arg0;
        M2C_FIELD(obj, u8*, 2) = arg1;
        M2C_FIELD(obj, s16*, 0xA) = arg2;
        M2C_FIELD(obj, s16*, 8) = 0;
        M2C_FIELD(obj, s16*, 0xE) = arg3;
        M2C_FIELD(obj, s16*, 0xC) = 0;
        M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(arg0)] >> 7;
        M2C_FIELD(obj, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(obj, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(obj, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(obj, u8**, 0x3C) =
            (u8*)SPAD20_800F440C +
            SPAD20_800F440C[func_8002A47C(M2C_FIELD(obj, s8*, 1))];
    }
}
