#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_EngineObj D_80097420;
extern u16 D_800F10F8[][2];

void func_800F03E4(void* arg0) {
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u16*, 0xA) = D_800F10F8[(u8)D_80097420.unk7][0];
    M2C_FIELD(arg0, s16*, 0xE) = D_800F10F8[(u8)D_80097420.unk7][1] - 3;
}
