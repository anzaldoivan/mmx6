#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800EE2C4(void* arg0) {
    s32 g = D_800970AA;
    s32 x = M2C_FIELD(arg0, s16*, 0xA);
    s32 v;

    if ((g - x >= 0 ? g - x : x - g) < 0x3D) {
        v = 6;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
    } else {
        if (++M2C_FIELD(arg0, s16*, 0x7C) != 0x78) {
            return;
        }
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        set_animation(arg0, 0);
        v = 4;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    M2C_FIELD(arg0, u8*, 5) = v;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
