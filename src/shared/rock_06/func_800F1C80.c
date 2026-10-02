#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*); /* extern */

void func_800F1C80(void* arg0) {
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x93);
    switch (temp_v1) { /* irregular */
    case 1:
        M2C_FIELD(arg0, u8*, 0x93) = 2U;
        M2C_FIELD(arg0, s16*, 0x9C) =
            (s16)((s32)M2C_FIELD(arg0, s32*, 0x20) >> 8);
        M2C_FIELD(arg0, s16*, 0x9E) =
            (s16)((s32)M2C_FIELD(arg0, s32*, 0x24) >> 8);
        M2C_FIELD(arg0, s16*, 0xA0) =
            (s16)((s32)M2C_FIELD(arg0, s32*, 0x28) >> 8);
        M2C_FIELD(arg0, s16*, 0xA2) =
            (s16)((s32)M2C_FIELD(arg0, s32*, 0x2C) >> 8);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            var_v0 = M2C_FIELD(arg0, s16*, 0xA4) << 8;
        } else {
            var_v0 = -(M2C_FIELD(arg0, s16*, 0xA4) << 8);
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        M2C_FIELD(arg0, s32*, 0x28) = 0x5800;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x5800;
        return;
    case 2:
        func_8002D230(arg0);
        var_v0_2 = M2C_FIELD(arg0, s32*, 0x20);
        if (var_v0_2 < 0) {
            var_v0_2 = -var_v0_2;
        }
        if (var_v0_2 < 0x4800) {
            M2C_FIELD(arg0, u8*, 0x93) = 0U;
            M2C_FIELD(arg0, u8*, 0x97) = (u8)(M2C_FIELD(arg0, u8*, 0x97) ^ 2);
            M2C_FIELD(arg0, s32*, 0x20) =
                (s32)(M2C_FIELD(arg0, s16*, 0x9C) << 8);
            M2C_FIELD(arg0, s32*, 0x28) =
                (s32)(M2C_FIELD(arg0, s16*, 0xA0) << 8);
            M2C_FIELD(arg0, s32*, 0x2C) =
                (s32)(M2C_FIELD(arg0, s16*, 0xA2) << 8);
        }
        if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        }
        return;
    }
}
