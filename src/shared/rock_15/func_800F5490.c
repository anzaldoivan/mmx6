#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_80097420;
#define D_80097420 (*(u8*)&D_80097420)
extern s32 D_800F70C0;

void func_800F5490(void* arg0) {
    u8 temp_v1;

    if (!(D_80097420 & 3)) {
        temp_v1 = *(M2C_FIELD(arg0, s8*, 0x93) + (u8*)&D_800F70C0);
        M2C_FIELD(arg0, s8*, 0x93) =
            (s8)(((u8)M2C_FIELD(arg0, s8*, 0x93) + 1) & 0xF);
        M2C_FIELD(arg0, u16*, 0xE) =
            (u16)(M2C_FIELD(arg0, u16*, 0xE) + (s8)temp_v1);
    }
}
#undef D_80097420
