#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230();
extern s16 D_800970AA;

void func_800EC4B4(void* arg0) {
    s32 var_v0;
    s8 var_v1;

    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
            var_v0 = 0x38000;
            var_v1 = 0x40;
            M2C_FIELD(arg0, u8*, 0x15) = var_v1;
            var_v1 = 3;
        } else {
            var_v0 = 0xFFFC8000;
            var_v1 = 7;
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        M2C_FIELD(arg0, s8*, 5) = var_v1;
        return;
    }
    func_8002D230(arg0);
}
