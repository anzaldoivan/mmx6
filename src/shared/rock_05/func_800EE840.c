#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

extern s16 D_800970AA;
extern s32 D_80097420;
#define D_80097420 (*(struct X4_ObjectHeader*)&D_80097420)
#define EF27C_FLAGS (*(s32*)&D_80097420)

void func_800EE840(void* arg0) {
    s32 temp_a1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, u16*, 0x80) - 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a2;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    if (!(EF27C_FLAGS & 1)) {
        D_800970AA = temp_a2;
    } else {
        D_800970AA = temp_a1;
    }
    if (D_80097420.state == 0) {
        M2C_FIELD(arg0, u16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef EF27C_FLAGS
#undef D_80097420
