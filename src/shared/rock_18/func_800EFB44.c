#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_EngineObj D_80097420;
#define D_80097420 (*(s32*)&D_80097420)
extern u8 D_800CCEF8;

void func_800EFB44(void* arg0) {
    if (D_800CCEF8 >= 0x7F) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 6) == 0) &&
        ((s8)D_800CCEF8 >= (s32)M2C_FIELD(arg0, u8*, 0x54))) {
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
    if (M2C_FIELD(arg0, s8*, 3) != 0) {
        switch ((u32)(D_80097420 & 3)) {
        case 0:
        case 1:
        case 2:
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
            break;
        case 3:
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
            break;
        }
    }
}
#undef D_80097420
