#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800EF318();
extern M2C_UNK D_8007591C;

void func_800EE30C(void* arg0) {
    ((void (*)())func_800EF318)();
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        if (M2C_FIELD(arg0, s16*, 0xA) < M2C_FIELD(arg0, s16*, 0x84) + 0x40) {
            return;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xA) >
               M2C_FIELD(arg0, s16*, 0x84) - 0x40) {
        return;
    }
    M2C_FIELD(arg0, void**, 0x58) = &D_8007591C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0x2000;
    M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) - 1;
}
