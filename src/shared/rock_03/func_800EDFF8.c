#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern u8 D_800CCF38;

void func_800EDFF8(void* arg0) {
    s32 v;

    func_80017A04();
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        v = 0xFFFE8000;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            v = 0x18000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = v;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x20) = v * 2;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
