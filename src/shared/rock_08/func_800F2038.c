#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK D_80074C9C;

void func_800F2038(void* arg0) {
    M2C_FIELD(arg0, M2C_UNK**, 0x58) = &D_80074C9C;
    if (M2C_FIELD(arg0, s8*, 0x87) < 0xA) {
        M2C_FIELD(arg0, s8*, 0x87) = (s8)((u8)M2C_FIELD(arg0, s8*, 0x87) + 1);
    }
    M2C_FIELD(arg0, s8*, 0x8B) = 0;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = (s16)(M2C_FIELD(arg0, s8*, 0x88) * 0xA);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
