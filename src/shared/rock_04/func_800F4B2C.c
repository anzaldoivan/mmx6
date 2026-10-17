#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

void func_800F4B2C(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        if (D_800CCED0.stage != 0xC) {
            ((void (*)(s32, s32, s32))func_80021760)(
                0, 0xFF, M2C_FIELD(&D_800CCED0, u8*, 0x2E));
            M2C_FIELD(&D_800CCED0, u8*, 0x2E) = 1;
        }
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
