#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_8009721E;
extern M2C_UNK D_800FCEFC;

void func_800F8454(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FCEFC;
    if ((D_8009721E + 0xA8) < M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
}
