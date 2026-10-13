#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F1FBC (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002BBF4();
extern u32* D_80095098;
extern s16 D_800FD526;

void func_800F1FBC(void) {
    void* obj;

    if ((u16)D_800FD526 < 0x1519U) {
        obj = func_8002BBF4();
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0) = 0x41;
            M2C_FIELD(obj, u8*, 1) = 0x1C;
            M2C_FIELD(obj, u8*, 2) = 1;
            M2C_FIELD(obj, s16*, 0xA) = 0x1120;
            M2C_FIELD(obj, s16*, 8) = 0;
            M2C_FIELD(obj, s16*, 0xE) = 0x360;
            M2C_FIELD(obj, s16*, 0xC) = 0;
            M2C_FIELD(obj, u16*, 0x40) = D_80095098[func_8002A47C(0x1C)] >> 7;
            M2C_FIELD(obj, s16*, 0x42) =
                ((func_8002A47C(M2C_FIELD(obj, s8*, 1)) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(obj, s8*, 1)) + 8) / 4 + 0x1E0)
                 << 6);
            M2C_FIELD(obj, u8**, 0x3C) =
                (u8*)SPAD20_800F1FBC +
                SPAD20_800F1FBC[func_8002A47C(M2C_FIELD(obj, s8*, 1))];
        }
    }
}
