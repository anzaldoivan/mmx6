#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CFB0(void* arg); /* extern */

s32 func_8003A0E8(void* arg0) {
    s32 mask;
    s32 lim;
    s32 flags;

    mask = 2;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        mask = 1;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & mask) {
        return 1;
    }
    func_8002CFB0(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (M2C_FIELD(arg0, s32*, 0x20) < M2C_FIELD(arg0, s32*, 0x108)) {
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x108);
        }
    } else {
        lim = -M2C_FIELD(arg0, s32*, 0x108);
        if (lim < M2C_FIELD(arg0, s32*, 0x20)) {
            M2C_FIELD(arg0, s32*, 0x20) = lim;
        }
    }
    if (--M2C_FIELD(arg0, s8*, 0x85) == 0) {
        return 1;
    }
    flags = M2C_FIELD(arg0, u16*, 0x7C) & 0x103;
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        if (flags & 2) {
            return 1;
        }
    } else if (flags & 1) {
        return 1;
    }
    return 0;
}
