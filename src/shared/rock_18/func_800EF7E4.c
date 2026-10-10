#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_EngineObj D_80097420;
extern u8 D_800CCEF8;
extern u16 D_800F0F6C[][2];

void func_800EF7E4(void* arg0) {
    if (D_800CCEF8 == 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
    M2C_FIELD(arg0, u16*, 0xA) = D_800F0F6C[(u8)D_80097420.unk7][0];
    M2C_FIELD(arg0, u16*, 0xE) = D_800F0F6C[(u8)D_80097420.unk7][1];
}
