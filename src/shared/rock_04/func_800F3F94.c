#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F3F94(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (47/49)
    register s32 v asm("$2");
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80016C48(2, 0x13, arg0);
        func_800179A4(arg0, 0xA);
        if ((v = M2C_FIELD(arg0, u8*, 0x15)) == 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s32*, 0x20) = (rcos(0xF1D) << 4) * 6;
            M2C_FIELD(arg0, s32*, 0x24) = (rsin(0xF1D) << 4) * 6;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = (rcos(0x8E3) << 4) * 6;
            M2C_FIELD(arg0, s32*, 0x24) = (rsin(0x8E3) << 4) * 6;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
