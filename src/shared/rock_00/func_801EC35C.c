#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);

s32 func_801EC35C(struct X4_PlayerObj* self) {
    u32 var_v1;
    s32 t;

    t = ((u8*)self)[0xD9] - 1;
    ((u8*)self)[0xD9] = t;
    var_v1 = ((u8*)self)[0x80] >> 7;
    if (!(t & 0xFF)) {
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        return 0;
    }
    func_8003AFF4((s32)self);
    return 1;
}
