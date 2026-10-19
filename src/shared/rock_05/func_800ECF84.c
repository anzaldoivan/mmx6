#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();

void func_800ECF84(u8* arg0) {
    s16 var_v0_2;
    s8 temp_v1;

    if (func_8002D2D4() & 1) {
        M2C_FIELD(arg0, s16*, 0xA) = 0xB80;
        M2C_FIELD(arg0, u8*, 0x8E) =
            (M2C_FIELD(arg0, u8*, 0x8E) + 0x10) & 0x1F0;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = 0xC20;
        M2C_FIELD(arg0, u8*, 0x8E) = (M2C_FIELD(arg0, u8*, 0x8E) + 1) & 0xF;
    }
    temp_v1 = M2C_FIELD(arg0, s8*, 0x8E);
    if (temp_v1 == 3) {
        var_v0_2 = 0xB80;
        // !FAKE: goto into the shared store block for both matching counter values
        goto block_7;
    }
    if (temp_v1 == 0x30) {
        var_v0_2 = 0xC20;
    block_7:
        M2C_FIELD(arg0, s16*, 0xA) = var_v0_2;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
    }
    {
        // !FAKE: numeric pin loads the -0x1000 constant early into the second return register
        register s32 b asm("$3") = -0x1000;
        M2C_FIELD(arg0, s32*, 0x24) = 0x10000;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = b;
        M2C_FIELD(arg0, u8*, 0x6) = 2;
    }
}
