#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BB94(void*, M2C_UNK, s8);

M2C_UNK func_8003F508(void* arg0, M2C_UNK arg1) {
    u8* p = arg0;
    s32 var_a1;
    s8 temp_s0;

    if (*(s8*)(p + 2) == 0) {
        var_a1 = arg1 + 0x70;
        if (*(s8*)(p + 0x90) != 0) {
            temp_s0 = *(s8*)(p + 0x44);
            func_8003BB94(arg0, arg1, p[0x45] & 0x3F);
            *(s8*)(p + 0x44) = temp_s0;
        } else if (*(s8*)(p + 0x8E) != 0 && p[0x17] != var_a1) {
            temp_s0 = *(s8*)(p + 0x44);
            func_8003BB94(p, var_a1, p[0x45] & 0x3F);
            *(s8*)(p + 0x44) = temp_s0;
        }
    }
}
