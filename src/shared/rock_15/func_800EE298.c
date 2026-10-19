#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EF318();
extern M2C_UNK D_8007433C;

void func_800EE298(void* arg0) {
    s32 v;

    if (M2C_FIELD(arg0, s8*, 0x88) == 1) {
        v = (s32)&D_8007433C;
        M2C_FIELD(arg0, s32*, 0x58) = v;
        M2C_FIELD(arg0, s16*, 0x84) = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0x86) = M2C_FIELD(arg0, s16*, 0xE);
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x50000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFB0000;
        }
        v = M2C_FIELD(arg0, u8*, 5);
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, u8*, 5) = v + 1;
    } else {
        func_800EF318(arg0);
    }
}
